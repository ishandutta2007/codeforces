#include<bits/stdc++.h>
#include<vector>
using namespace std;
const long long mod = 1000000007;
void my_add(long long &x, long long v) {
    x = (x + v) %mod;
}
int n;
vector<int>e[100000];
long long my_gcd(long long x, long long y) {
    if(!x || !y) return x + y;
    return __gcd(x, y);
}
int ancestor[100000][17];
int lv[100000];
void dfs(int i, int lt) {
    for(int y: e[i]) {
        if(y == lt) continue;
        lv[y] = lv[i] + 1;
        ancestor[y][0] = i;
        dfs(y, i);
    }
}
long long common_gcd[100000][17];
long long x[100000];
void build() {
    for(int i = 0; i < n; i++) {
        common_gcd[i][0] = my_gcd(x[i], x[ancestor[i][0]]);
    }
    for(int i = 1; i < 17; i++) {
        for(int j = 0; j < n; j++) {
            ancestor[j][i] = ancestor[ancestor[j][i-1]][i-1];
            common_gcd[j][i] = my_gcd(common_gcd[j][i-1],common_gcd[ancestor[j][i-1]][i-1]);
        }
    }
}
int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%lld", &x[i]);
    for(int i = 1; i < n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        a--; b--;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    dfs(0, 0);
    build();
    long long an = 0;
    for(int i = 0; i < n; i++) {
        int now_lv = lv[i];
        long long now_gcd = x[i];
        while(1) {
            int nxt = i;
            if(now_gcd) {
                for(int j = 16; j >= 0; j--) {
                    if(common_gcd[nxt][j] % now_gcd == 0) nxt = ancestor[nxt][j];
                }
            }
            else {
                for(int j = 16; j >= 0; j--) {
                    if(!common_gcd[nxt][j]) nxt = ancestor[nxt][j];
                }
            }
            my_add(an, (now_lv - lv[nxt] + 1LL) * now_gcd);
            if(!nxt) break;
            now_gcd = my_gcd(now_gcd, x[ancestor[nxt][0]]);
            now_lv = lv[nxt] - 1;
        }
    }
    printf("%lld\n", an);
    return 0;
}