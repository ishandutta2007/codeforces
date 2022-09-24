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
int d[800005 + 1000], t[800005 + 1000], n;

int mid(int l, int r)
{
    return (r - l) / 2 + l;
}
int gcd(int a , int b)
{
    if(b == 0) return a;
    return gcd(b, a % b);
}
void build(int u, int l, int r)
{
    if (l + 1 == r)
    {
        t[u] = d[l];
        return;
    }
    int m = mid(l, r);
    build(2 * u + 1, l, m);
    build(2 * u + 2, m, r);
    t[u] = gcd(t[2 * u + 1] , t[2 * u + 2]);
}

void build()
{
    build(0, 0, n);
}

int x;
void upd(int u, int l, int r, int L, int R, int v)
{
    if (l == L && r == R)
    {
        d[l] = v;
        t[u] = d[l];
        return;
    }
    int m = mid(l, r);
    if (L < m) upd(2 * u + 1, l, m, L, min(m, R), v);
    if (R > m) upd(2 * u + 2, m, r, max(L, m), R, v);
    t[u] = gcd(t[2 * u + 1] , t[2 * u + 2]);
}

void upd(int l, int r, int v)
{
    upd(0, 0, n, l, r, v);
}
int cnt = 0;
int dfs(int u , int l , int r)
{
 //   cout << "    " << l << " " << r <<"\n";
    if(l == r - 1)
    {
        return (t[u] % x != 0);
    }
    if(t[2 * u + 1] % x != 0 && t[2 * u + 2] % x != 0)
    {
        return 2;
    }
    int m = mid(l , r);
    if( t[2 * u + 1] % x != 0) return dfs(2 * u + 1 , l , m);
    if( t[2 * u + 2] % x != 0) return dfs(2 * u + 2 , m , r);
    return 0;
}
void get(int u, int l, int r, int L, int R)
{
    if(cnt >= 2) return ;
    if (l == L && r == R)
    {
    //    cout << l << " " << r << " " << t[u] << " " << x << " " ;
        if(t[u] % x != 0)
        {
          cnt += dfs(u , l , r);
        }
      //  cout << cnt << "\n";
        return ;
    }
    int m = mid(l, r);
    int ans = 0;
    if (L < m) get(2 * u + 1, l, m, L, min(R, m));
    if (R > m) get(2 * u + 2, m, r, max(L, m), R);
    return ;
}
void get(int l, int r)
{
    return get(0, 0, n, l, r);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> d[i];
    build();
    cin >> q;
    while(q--)
    {
        int t;
        cin >> t;
        if(t == 1)
        {
            int l , r ;
            cin >> l >> r >> x;
            l--;
            cnt = 0;
            get(l , r);
            if(cnt >= 2)
            {
                cout << "NO" << "\n";
            }
            else
            {
                cout << "YES" << "\n";
            }
        }
        if(t == 2)
        {
            int l , x;
            cin >> l >> x;
            l--;
            upd(l, l + 1, x);
        }
    }
    return 0;
}