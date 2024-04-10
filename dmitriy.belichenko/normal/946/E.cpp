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
#include <random>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
#define fst first
#define snd second
#define ld long double
#define mt make_tuple
const double PI = acos(-1);
const int N = 2e5 + 7;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
const int MAXN = 26;
template<class A, class B>
void sum(A &a, B b)
{
    a += b;
    if (a < 0) a += MOD;
    if (a >= MOD) a -= MOD;
}
int to_i(char c)
{
    return c - 'a';
}
ll mult(ll a, ll  b)
{
    long long c = 1LL * (a % MOD) * (b % MOD);
    return c % MOD;
}
int poww(long long a, long long b)
{
    long long res = 1;
    a %= MOD;
    while (b > 0)
    {
        if (b % 2) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res % MOD;
}

//int gr[50][50][N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        int len = s.size();
        bool ok = 0;
        if (s[0] == '1')
        {
            int flag = 0;
            for (int j = 1; j < len - 1; j++)
            {   if (s[j] != '0')
                {
                    flag = 1;
                }
            }
            if (s[len - 1] > '1') flag = 1;
            if (!flag)
            {
                for (int i = 0; i < len - 2; i++)
                {
                    cout << 9;
                }
                cout << "\n";
                ok = 1;
            }
        }
        if(ok) continue;
        int now = 0;
        for (int i = 0; i < len; i++)
        {
            now ^= (1 << (s[i] - '0'));
        }
        for (int i = len - 1; i >= 0; i--)
        {
            now = now ^ (1 << (s[i] - '0'));
            int c = s[i] - '0';
            for (int j = c - 1; j >= 0; j--)
            {
                int cr = now ^ (1 << j);
                int cnt = __builtin_popcount(cr);
                if (cnt > len - 1 - i) continue;
                string ans = s.substr(0, i);
                ans.pb(char(j + '0'));
               // cout << ans << "\n";
                int lf = len - 1 - i;
                while (lf > cnt)
                {
                    ans.pb('9');
                    ans.pb('9');
                    lf -= 2;
                }
                for (int j = 9; j >= 0; j--)
                {
                    if ((cr >> j) & 1 ) ans.pb(char('0' + j));
                   //  cout << ans << "\n";
                    
                }
                cout << ans << "\n";
                ok = 1;
                break;
            }
            if(ok) break;
        }
    }
    return 0;
}