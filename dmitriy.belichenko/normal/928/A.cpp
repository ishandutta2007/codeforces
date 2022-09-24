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
const int N = 3e5 + 7;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
template<class A, class B>
void sum(A &a, B b)
{
    a += b;
    if (a < 0) a += MOD;
    if (a >= MOD) a -= MOD;
}
int gcd(int a, int b)
{
    if (b == 0) return a;
    if (a == 0) return b;
    if (a % b == 0) return b;
    else  return gcd(b % a, a);
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
string to_equal(string p)
{
    string r = p;
    for(int i = 0; i < r.size(); i++)
    {
        if(r[i] >= 'A' && r[i] <= 'Z')
        {
            r[i] = r[i] - 'A' + 'a';
        }
    }
    for(int i = 0; i < r.size(); i++)
    {
        if(r[i] == '1' || r[i] == 'l') r[i] = 'i';
    }
    for(int i = 0; i < r.size(); i++)
    {
        if(r[i] == 'o') r[i] = '0';
    }
    return r;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int n;
    cin >> n;
    s = to_equal(s);
    for(int i = 0; i < n; i++)
    {
        string t;
        cin >> t;
        t = to_equal(t);
        //cout << s << " " << t << "\n";
        if(s == t)
        {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes" << "\n";
    return 0;
}