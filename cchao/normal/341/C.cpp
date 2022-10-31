#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
const int mod = 1000000007, maxn = 2010;

ll dp[maxn][maxn];
ll solve(int a, int b) {
    if(dp[a][b] >= 0) return dp[a][b];
    if(b == 0) {
        if(a==2) return 1;
        if(a==1) return 0;
        if(a==0) return 0;
        return dp[a][b] = (a-1) * (solve(a-1,b) + solve(a-2, b)) % mod;
    }
    else {
        if(a == 0) {
            ll ret = 1;
            for(int i = 1; i <= b; ++i) ret = (ret * i) % mod;
            return dp[a][b] = ret;
        }
        return dp[a][b] = (b * solve(a, b-1) + a * solve(a - 1, b)) % mod;
    }
}
int n, arr[maxn];
int main() {
    memset(dp, -1, sizeof dp);
    scanf("%d", &n);
    int m1 = 0; //num of -1
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &arr[i]);
        if(arr[i] == -1) m1++;
    }
    int a = m1, b = 0; //#of -1 we should consider and we shouldn't consider
    for(int i = 1; i <= n; ++i)
        if(arr[i] != -1 && arr[arr[i]] == -1) {
            a--; b++;
        }
    cout << solve(a, b) << endl;
    return 0;
}