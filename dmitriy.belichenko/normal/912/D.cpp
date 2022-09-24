#include <iostream>
#include <map>
#include <vector>
#include <deque>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <string>
#include <set>
#include <iomanip>
#include <bitset>
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
#define fst first
#define snd second
#define ld long double
const double PI = acos(-1);
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;
ll sum(ll a , ll b)
{
    a += b;
    if(a < 0)
        return  a + MOD;
    if(a >= MOD)
        return a - MOD;
    else return a;
}

ll mult( ll a , ll  b)
{
    long long c = 1LL * (a % MOD) * (b % MOD);
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
map<int , int> at;
set<pair<int, int>> t;
bool used[N];
int pos[1000][1000];
double ans = 0;
int cnt1[N] , cnt2[N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n , m , r , k;
    cin >> n >> m >> r >> k;
    for (int i = 1; i + r <= n + 1 ; i++)
    {
        cnt1[i]++;
        cnt1[i + r]--;
    }
    for (int i = 1 ; i + r <= m + 1 ; i++)
    {
        cnt2[i]++;
        cnt2[i + r]--;
    }
    for (int i = 1; i < n + 1 ; i++)
    {
        cnt1[i] += cnt1[i - 1];
    }
    for (int i = 1 ; i < m + 1 ; i++)
    {
        cnt2[i] += cnt2[i - 1];
    }
    sort(cnt2 + 1,cnt2 + m + 1);
    reverse(cnt2 + 1,cnt2 + m + 1);
    for (int i = 1; i <= n; i++)
    {
        t.insert(mp(1LL * cnt1[i] * cnt2[1] , i));
        at[i] = 1;
    }
    for (int i = 1 ;i <= k; i++)
    {
        auto it = t.end();
        it--;
        int ind = it->snd;
        ans += it->fst;
        t.erase(it);
        t.insert(mp(1ll*cnt1[ind]*cnt2[++at[ind]], ind));
    }
    cout << setprecision(10) << fixed << ans / (- r + m + 1) / (- r + n + 1);
    return 0;
}