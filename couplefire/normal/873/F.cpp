#include <bits/stdc++.h>
using namespace std;
#define MAXN 200005

struct state{
    long long len, link, cnt = 0;
    map<char, long long> next;
};

state st[MAXN*2];
vector<pair<long long, long long>> order;
long long sz, last;
string check;

void sc_init(){
    st[0].len = 0;
    st[0].link = -1;
    sz++;
    last = 0;
}

void sc_extends(char c, long long pos){
    long long cur = sz++;
    st[cur].len = st[last].len+1;
    if(check[pos] != '1') st[cur].cnt = 1;
    order.emplace_back(st[cur].len, cur);
    long long p =last;
    while(p != -1 && !st[p].next.count(c)){
        st[p].next[c] = cur;
        p = st[p].link;
    }
    if(p == -1){
        st[cur].link = 0;
    }
    else{
        long long q = st[p].next[c];
        if(st[q].len == st[p].len+1){
            st[cur].link = q;
        }
        else{
            long long clone = sz++;
            st[clone].len = st[p].len+1;
            st[clone].next = st[q].next;
            st[clone].link = st[q].link;
            order.emplace_back(st[clone].len, clone);
            while(p != -1 && st[p].next[c] == q){
                st[p].next[c] = clone;
                p = st[p].link;
            }
            st[q].link = st[cur].link = clone;
        }
    }
    last = cur;
}

int main(){
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long n; cin >> n;
    string s; cin >> s;
    cin >> check;
    sc_init();
    for(long long i = 0; i<n; i++){
        sc_extends(s[i], i);
    }
    sort(order.begin(), order.end());
    reverse(order.begin(), order.end());
    for(auto i : order){
        st[st[i.second].link].cnt += st[i.second].cnt;
    }
    long long ma = 0;
    for(long long i = 0; i<sz; i++){
        ma = max(st[i].cnt*st[i].len, ma);
    }
    cout << ma << endl;
}