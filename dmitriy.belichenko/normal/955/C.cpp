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
#define integ __int128
#define ld long double
#define mt make_tuple
const double PI = acos(-1);
const int N = 2e5 + 7;
const int INF = 1e9 + 7;
const int MAXN = 26;
const ll MOD = 1e18 + 9;
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


ll poww(ll a, long long b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b % 2) res = (res * a);
        a = (a * a);
        b >>= 1;
    }
    return res;
}
vector<ll> sp;
unordered_map<ll, bool> used;
vector<int> primes;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q = 0;
    int n;
    n = 100;
    vector<char> prime (n+1, true);
    prime[0] = prime[1] = false;
    for (int i=2; i<=n; ++i)
        if (prime[i])
        {
            primes.pb(i);
            if (i * 1ll * i <= n)
                for (int j=i*i; j<=n; j+=i)
                    prime[j] = false;
        }
    // cin >>
    for(ll i = 2; i <= 1e6 + 1; i++)
    {
        ll p = i * i;
        while((ld)p * i < (1e18 + 10 ))
        {
            p *= i;
            //   cout << i << " " << p << "\n";
            if(used[p]) break;
            sp.pb(p);
            used[p] = 1;
        }
    }
    int m = sp.size();
    //    cout << m << "\n";
    for(int i = 0; i < m; i++)
    {
        ll p = sqrt(sp[i]);
        if(p * p == sp[i])
        {
            swap(sp[i] , sp[sp.size() - 1]);
            sp.pop_back();
            m = sp.size();
        }
    }
    sort(sp.begin(), sp.end());
    //    for(int i = 0; i < 100; i++) cout << sp[i] << " ";
    cin >> q;
    while(q--)
    {
        ll l , r;
        cin >> l >> r;
        ll cl =  lower_bound(sp.begin(), sp.end(), l  ) - sp.begin();
        ll cr =  upper_bound(sp.begin(), sp.end(), r  ) - sp.begin();
        ll rr = sqrt(r);
        ll lr = sqrt(l);
        int cnt = 0;
        if(lr * lr < l) lr++;
        cout <<  cr - cl  + max(rr - lr + 1 , 0LL) << "\n";
    }
    
}