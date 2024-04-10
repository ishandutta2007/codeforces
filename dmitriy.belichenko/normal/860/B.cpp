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
const int N = 1e6 + 7;
const int MOD = 1e9 + 7;
const int INF = 1e8;
template<class A, class B>
void sum(A &a, B b)
{
    a += b;
    if (a < 0) a += MOD;
    if (a >= MOD) a -= MOD;
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
int gcd(int a, int b)
{
    if (b == 0) return a;
    if (a == 0) return b;
    if (a % b == 0) return b;
    else  return gcd(b % a, a);
}
unordered_map<string, int> has;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<string> num(n);
    for(int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    for(int i = 0; i < n; i++)
    {
        unordered_set<string> hs;
        for(int j = 0; j < num[i].size(); j++)
        {
            for(int k = 0; k + j <= num[i].size(); k++)
            {
                string p = num[i].substr(j , k);
                if(p.size() > 0)
                hs.insert(p);
            }
        }
        for(auto p : hs)
        {
            has[p]++;
        }
    }
    for(int i = 0; i < n; i++)
    {
        string mn = "9999999999";
      //  cout << num[i] << "\n";
        for(int j = 0; j < num[i].size(); j++)
        {
            for(int k = 0; k + j <= num[i].size(); k++)
            {
                string p = num[i].substr(j , k);
              //  cout << p  << " " << has[p] << "\n";
                if( has[p] == 1)
                {
                    if(mn.size() > p.size()) mn = p;
                }
            }
        }
        cout << mn << "\n";
    }
}