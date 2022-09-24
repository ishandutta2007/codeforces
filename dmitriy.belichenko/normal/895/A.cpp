
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <map>
#include <unordered_map>
#include <bitset>
#include <complex>
#include <complex>
#include <cmath>
#include <iomanip>
#include <math.h>
#include <cstring>
#include <queue>
#include <set>
#define mp make_pair
#define pb push_back
using namespace std;
using namespace std;
long long dp[(1<<19) + 1][2];
int divp[73];
int MOD = 1e9 + 7;
int id[73];
int stt[100005];
auto st = stt + 1;
long long sum(long long a , long long b)
{
    a += b;
    if(a >= MOD)
        return a - MOD;
    else return a;
}
long long mult( long long a , long long b)
{
    long long c = 1LL * a * b;
    return c % MOD;
}
int poww(long long a , long long b)
{
    long long res = 1;
    a %= MOD;
    while(b > 0)
    {
        if(b % 2) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res % MOD;
}
int pref[100005];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    pref[0] = 0;
    for(int i = 1; i <= n; i++)
        pref[i] += pref[i - 1] + a[i - 1];
    int ans = 360;
    for(int i  = 0; i < n; i++)
    {
        for(int j =  i  + 1; j <= n; j++)
        {
            
            int v = 360 - pref[j] + pref[i];
            ans = min(ans , abs(pref[j] - pref[i] - v));
        }
    }
    cout << ans << "\n";
}