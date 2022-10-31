#include <bits/stdc++.h>
using namespace std;
#define finish(x) return cout << x << endl, 0
#define ll long long

int n, fact[100001], cnt[52], res[52][52], dp[100001], mod = 1e9 + 7;
string s;
char ss[100001];

int idx(char c){
    if('a' <= c && c <= 'z') return c - 'a';
    return c - 'A' + 26;
}
char c(int id){
    if(id <= 26) return id + 'a';
    return id - 26 + 'A';
}
void add(int x){
    for(int i = n / 2 ; i >= x ; i--){
        dp[i] += dp[i - x];
        if(dp[i] >= mod) dp[i] -= mod;
    }
}
void del(int x){
    for(int i = x ; i <= n / 2 ; i++){
        dp[i] -= dp[i - x];
        if(dp[i] < 0) dp[i] += mod;
    }
}
int powlog(int a, int b){
    if(b == 0) return 1;
    int ret = powlog(a, b / 2);
    if(b % 2) return 1LL * ret * ret % mod * a % mod;
    return 1LL * ret * ret % mod;
}
int calc(int x, int y){
    int ret = 1LL * fact[n / 2] * fact[n / 2] % mod;
    for(int i = 0 ; i < 52 ; i++)
        if(cnt[i]) ret = 1LL * ret * powlog(fact[cnt[i]], mod - 2) % mod;
    if(x == y) return 1LL * ret * dp[n / 2] % mod;
    del(cnt[x]); del(cnt[y]);
    add(cnt[x] + cnt[y]);
    ret = 1LL * ret * dp[n / 2] % mod;
    del(cnt[x] + cnt[y]);
    add(cnt[x]); add(cnt[y]);
    return ret;
}
int main(){
    scanf("%s", ss);
    s = ss;
    n = s.size();
    dp[0] = 1;
    fact[0] = 1;
    for(int i = 1 ; i <= n ; i++)
        fact[i] = 1LL * fact[i - 1] * i % mod;
    for(auto &i : s)
        cnt[idx(i)]++;
    for(int i = 0 ; i < 52 ; i++)
        if(cnt[i]) add(cnt[i]);
    for(int i = 0 ; i < 52 ; i++){
        for(int j = i ; j < 52 ; j++){
            if(cnt[i] && cnt[j]){
                res[i][j] = calc(i, j);
            }
        }
    }
    int q;
    scanf("%d", &q);
    while(q--){
        int x, y;
        scanf("%d %d", &x, &y);
        x--; y--;
        if(idx(s[x]) > idx(s[y])) swap(x, y);
        printf("%d\n", res[idx(s[x])][idx(s[y])]);
    }
}