
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
const int N = 1e5;
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

long long d[800005 + 1000], t[800005 + 1000], n;

int mid(int l, int r){
    return (r - l) / 2 + l;
}

void build(int u, int l, int r){
    if (l + 1 == r){
        t[u] = 0;
        return;
    }
    int m = mid(l, r);
    build(2 * u + 1, l, m);
    build(2 * u + 2, m, r);
    t[u] = t[2 * u + 1] + t[2 * u + 2];
}

void build(){
    for (int i = 0; i < 4 * n; ++i)
        d[i] = 0;
    build(0, 0, n);
}

void push(int u, int l, int r)
{
    if (d[u] == -1e9 - 7)
        return;
    if (r - l > 1)
    {
        d[2 * u + 1] += d[u];
        d[2 * u + 2] += d[u];
    }
    t[u] += d[u] * (r - l);
    d[u] = 0;
}

void upd(int u, int l, int r, int L, int R, int v)
{
    push(u, l, r);
    if (l == L && r == R)
    {
        d[u] += v;
        push(u, l, r);
        return;
    }
    int m = mid(l, r);
    if (L < m) upd(2 * u + 1, l, m, L, min(m, R), v);
    if (R > m) upd(2 * u + 2, m, r, max(L, m), R, v);
    push(2 * u + 1, l, m);
    push(2 * u + 2, m, r);
    t[u] = t[2 * u + 1] + t[2 * u + 2];
}

void upd(int l, int r, int v)
{
    upd(0, 0, n, l, r, v);
}

long long get(int u, int l, int r, int L, int R)
{
    push(u, l, r);
    if (l == L && r == R)
    {
        return t[u];
    }
    int m = mid(l, r);
    long long ans = 0;
    if (L < m) ans += get(2 * u + 1, l, m, L, min(R, m));
    if (R > m) ans += get(2 * u + 2, m, r, max(L, m), R);
    push(2 * u + 1, l, m);
    push(2 * u + 2, m, r);
    return ans;
}

long long get(int l, int r){
    return get(0, 0, n, l, r);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int k;
    n = 2e5 + 5;
    cin >> k;
    build();
    double sum = 0;
    int cur = 1;
    while (k--)
    {
        int c;
        cin >> c;
        if(c == 1)
        {
            int a , x;
            cin >> a >> x;
            upd(0 , a , x);
            sum = get(0 , cur );
            cout << setprecision(10) << fixed << sum / cur << "\n";
        }
        if(c == 2)
        {
            int a , x;
            cin >> x;
            cur++;
            upd(cur - 1 , cur , x);
            sum = get(0 , cur );
            cout << setprecision(10) << fixed << sum / cur << "\n";
            
        }
        if(c == 3)
        {
           // cout << " sdfsdf " << -get(cur - 1,cur ) << "\n";
            upd(cur - 1 , cur , -get(cur - 1 , cur));
            cur--;
            sum = get(0 , cur );
            cout << setprecision(10) << fixed << sum / cur << "\n";
            
        }

    }
    return 0;
}