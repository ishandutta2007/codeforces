#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;
const int MOD = 1e9 + 7;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a, b;
    cin >> a >> b;

    cout << (a * (a + 1) / 2 % MOD * b % MOD * (b * (b - 1) / 2 % MOD) % MOD + b * (b - 1) / 2 % MOD * a % MOD) % MOD;
}