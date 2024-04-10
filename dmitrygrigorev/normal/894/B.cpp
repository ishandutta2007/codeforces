#include <bits/stdc++.h>
#define int long long
using namespace std;
int MOD = 1000000007;
int ex(int a, int b){
    int ans = 1;
    int s = a;
    for (int i=0; i < 62; i++){
        int ba = (1LL << i) & b;
        if (ba == 0){
            s *= s;
            s %= MOD;
            continue;
        }
        ans *= s;
        ans %= MOD;
        s *= s;
        s %= MOD;
    }
    return ans;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    int Y = (n % 2 == 0) + (m % 2 == 0);
    if (k == -1 && Y == 1){
        cout << 0 << endl;
        return 0;
    }
    if (n > m) swap(n, m);
    if (n == 1){
        cout << 1 << endl;
        return 0;
    }
    int f = ex(2, m-1);
    int d = ex(f, n-2);
    cout << (f*d) % MOD << endl;
    return 0;
}