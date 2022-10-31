#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005

struct state{
    long long len, link, cnt = 0, cnt2 = -1;
    map<char, long long> next;
};

state st[MAXN*2];
vector<pair<long long, long long>> order;
long long sz, last;

void sc_init(){
    st[0].len = 0;
    st[0].link = -1;
    sz++;
    last = 0;
}

void sc_extends(char c){
    long long cur = sz++;
    st[cur].len = st[last].len+1;
    st[cur].cnt = 1;
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

void preprocess(long long v){
    if(st[v].cnt2 != -1) return;
    st[v].cnt2 = st[v].cnt;
    for(auto u : st[v].next){
        preprocess(u.second);
        st[v].cnt += st[u.second].cnt;
    }
}

int main(){
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s; cin >> s;
    long long n; cin >> n;
    n+=s.length();
    sc_init();
    for(long long i = 0; i<s.length(); i++){
        sc_extends(s[i]);
    }
    sort(order.begin(), order.end());
    reverse(order.begin(), order.end());
    for(auto i : order){
        st[st[i.second].link].cnt += st[i.second].cnt;
    }
    preprocess(0);
    //cout << st[0].cnt2 << endl;
    if(st[0].cnt < n){
        cout << "No such line." << endl;
        return 0;
    }
    long long cur = 0;
    while(st[cur].cnt2 < n){
        n -= st[cur].cnt2;
        for(auto u : st[cur].next){
            if(st[u.second].cnt < n){
                n -= st[u.second].cnt;
            }
            else{
                cout << u.first;
                cur = u.second;
                break;
            }
        }
    }
}