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
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
#define fst first
#define snd second
#define ld long double
const double PI = acos(-1);
const int N = 100;
const int MOD = 1e9 + 7;
int sum(int a , int b)
{
    a += b;
    if(a < 0)
        return  a + MOD;
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
set<char> gl = { 'a', 'e', 'i', 'o' , 'u' };
set<char> ch = { '1', '3', '5', '7' ,'9' };

int ind(char c)
{
    return c - '0';
}
vector<long long> a;
vector<long double> ans;
int n , r;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> r;
    a.resize(n);
    ans.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i)
    {
        ld cur = r;
        for (int j = 0; j < i; j++)
        {
            if (abs(a[i] - a[j]) <= 2 * r)
            {
                cur = max(cur, ans[j] + sqrt( ans[j] * ans[j] - (a[i] - a[j]) * (a[i] - a[j]) - ans[j] * ans[j] + 4 * r * r ));
            }
        }
        ans[i] = cur;
    }
    for (int i = 0; i < n; i++)
    {
        cout << setprecision(20) << fixed << ans[i] << " ";
    }
    return 0;
}