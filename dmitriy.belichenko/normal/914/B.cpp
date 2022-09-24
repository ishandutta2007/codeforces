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
const int N = 2e6 + 5;
int MOD = 1e9 + 7;
template<class A, class B>

void sum(A &a , B b)
{
    a += b;
    if(a < 0) a += MOD;
    if(a >= MOD) a -= MOD;
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
bool isprime(int n)
{
    for(int i = 2; i * i <= n; i++ )
    {
        if(n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
int n , k;
ll ans = 0 , st = 0;
map<int , int> cnt;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.rbegin(), a.rend());
    for(int i = 0; i < n; i++)
    {
        cnt[a[i]]++;
    }
    if(cnt[a[0]] == 1)
    {
        cout << "Conan";
        return 0;
    }
    else
    {
        if(cnt[a[0]] % 2 == 1)
        {
            cout << "Conan" << "\n";
        }
        else
        {
            if(cnt[a[0]] == n)
            {
             cout << "Agasa" << "\n";
                return 0;
            }
            else
            {
            for(int i = 1; i < n; i++)
                if(cnt[a[i]] % 2 == 1)
                {
                    cout << "Conan";
                    return 0;
                }
                {
                    cout << "Agasa";
                }
            }
        }
    }
    return 0;
}