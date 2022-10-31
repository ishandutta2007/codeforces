#include <bits/stdc++.h>
using namespace std;
#define MAXN 3002
#define MOD 1000000007

struct state{
    long long len, link, firstpos;
    map<char, long long> next;
};

state st[MAXN*2];
long long sz, last;
unordered_set<string> bad = {"0011", "0101", "1110", "1111"};

void sc_init(){
    st[0].len = 0;
    st[0].link = -1;
    sz++;
    last = 0;
}

void sc_extends(char c){
    long long cur = sz++;
    st[cur].len = st[last].len+1;
    st[cur].firstpos = st[cur].len-1;
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
            st[clone].firstpos = st[q].firstpos;
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
    string s = "";
    sc_init();
    long long ans = 0;
    for(long long i = 0; i<n; i++){
        char c; cin >> c;
        s += c;
        sc_extends(c);
        long long dp[i+1];
        for(long long j = 0; j<=i; j++){
            string cur = "";
            dp[j] = 0;
            for(long long k = 0; k<=min(3ll, j); k++){
                cur += s[i-j+k];
                if(!bad.count(cur)){
                    if(j-k-1 >= 0) dp[j] += dp[j-k-1];
                    else dp[j] += 1;
                    dp[j] %= MOD;
                }
            }
            if(j+1 > st[st[last].link].len) ans += dp[j], ans %= MOD;
        }
        cout << ans << endl;

    }
}