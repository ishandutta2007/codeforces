#pragma ("sse4")
#pragma ("unroll_loops")
#include <iostream>
#include <map>
#include <vector>
#include <deque>
#include <algorithm>
#include <bitset>
#include <cstring>
#include <math.h>
#include <string>
#include <set>
#include <valarray>
#include <iomanip>
#include <bitset>
#include <random>
#include <complex>
#include <random>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
#define fdeg firdeg
#define snd second
#define ld long double
#define mt make_tuple
#define fst first
const double PI = acos(-1);
// = 5e5 + 17;
ll MOD = 1e9 + 7;
const ll INF = 1e18 + 9;
const int MaXN = 26;
const int N = 2e5 + 15;
const int maxlog = 18;
ld ecr = 1e-8;
random_device rd;
mt19937 rnd(rd());
uniform_int_distribution<ll> nextRand(0,(ll)1e9);
template<class A, class B>
void sum(A &a, B b)
{
    a += b;
    if (a < 0LL) a += MOD;
    if (a >= MOD) a -= MOD;
}
ll add(ll a, ll b)
{
    a += b;
    if (a < 0) a += MOD;
    if (a >= MOD) a -= MOD;
    return a;
    
}
int to_i(char c)
{
    return c - 'a';
}
ll mult(ll a, ll b) {
    ll val = a * b - (ll) ((ld) a * b / MOD) * MOD;
    if (val < 0) {
        val += MOD;
    }
    if (val >= MOD) {
        val -= MOD;
    }
    return val;
}
ll calc( ll i,  ll n)
{
    ll j = i;
    ll t = 0;
    while (j <= n)
    {
        t += n / j;
        j *= i;
    }
    return t;
}
ll gcd (ll a, ll b)
{
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}
ll gcd_eu (ll a, ll b, ll & x, ll & y)
{
    if (a == 0)
    {
        x = 0LL; y = 1LL;
        return b;
    }
    ll x1, y1;
    ll d = gcd_eu (b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}
long long poww(long long a, long long b)
{
    long long val = 1;
    a %= MOD;
    while (b > 0)
    {
        if (b % 2) val = mult(a, val);
        a = mult(a, a);
        b >>= 1;
    }
    return val % MOD;
}
ll inv(ll a)
{
    return poww(a , MOD - 2);
}
const int maxn = 12000000;
int buffer[10001000], lb = 0;
struct trie
{
    int* nxt;
    int val;
    void InitNxt(int l)
    {
        nxt = buffer + lb;
        for (int i = 0; i < l; i++)
        {
            nxt[i] = -1;
        }
        lb += l;
    }
} arr[maxn];
int larr;
inline void addword(vector<int> str, int val)
{
    int l = str.size();
    arr[0].val += val;
    pair<int, int> q[30];
    int lq = 0;
    q[lq++] = mp(0, 0);
    for(int ii = 0; ii < lq; ii++)
    {
        int no = q[ii].first, i = q[ii].second;
        if (arr[no].nxt == nullptr)
        {
            arr[no].InitNxt(i >= l - 2 ? 6 : 3);
        }
        auto GetNext = [&](int cate)
        {
            int nxt = arr[no].nxt[cate];
            if(nxt == -1)
            {
                nxt = arr[no].nxt[cate] = larr++;
            }
            return nxt;
        };
        auto upd = [&](int cate)
        {
            int nxt = GetNext(cate);
            arr[nxt].val += val;
            if (i + 1 < (int)str.size())
            {
                q[lq++] = mp(nxt, i + 1);
            }
        };
        upd(str[i]);
        if (i >= l - 2)
        {
            if (str[i] != 2)
            {
                upd(3);
            }
            if (str[i] != 1)
            {
                upd(4);
            }
            if (str[i] != 0)
            {
                upd(5);
            }
        }
    }
}
int nb, n, nq;
int cnt[maxn], rcnt[600000];
int pq[maxn], lpq;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> nb >> n >> nq;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        cnt[val]++;
    }
    for (int i = 0; i < 1 << nb; i++) for (int j = 0; j < 1 << nb; j++) if (cnt[i] && cnt[j])
    {
        int val = 0;
        for (int k = 0; k < nb; k++)
        {
            val = val * 3;
            if ((i & (1 << k)) && (j & (1 << k)))
            {
                val += 2;
            }
            else
            {
                if ((i & (1 << k)) || (j & (1 << k)))
                {
                    val += 1;
                }
            }
        }
        rcnt[val] += cnt[i] * cnt[j];
    }
    vector<int>str(nb, 0);
    larr = 1;
    for (int num = 0; num < 600000; num++) 
    {
        if (rcnt[num])
        {
            for (int i = 0, rnum = num; i < nb; i++, rnum /= 3)
            {
                str[i] = rnum % 3;
            }
            addword(str, rcnt[num]);
        }
    }
    for (int ii = 0; ii < nq; ii++)
    {
        char str[20];
        cin >> str;
        lpq = 0;
        pq[lpq++] = 0;
        int now = 0;
        for (int i = 0; i < nb - 2; i++)
        {
            int rlpq = lpq;
            for (int j = now; j < rlpq; j++)
            {
                int no = pq[j];
                switch(str[i])
                {
                    case 'A':
                    {
                        if (arr[no].nxt[0] != -1)
                        {
                            pq[lpq++] = arr[no].nxt[0];
                        }
                        if (arr[no].nxt[1] != -1)
                        {
                            pq[lpq++] = arr[no].nxt[1];
                        }
                        break;
                    }
                    case 'O':
                    {
                        if (arr[no].nxt[0] != -1)
                        {
                            pq[lpq++] = arr[no].nxt[0];
                        }
                        break;
                    }
                    case 'X':
                    {
                        if (arr[no].nxt[0] != -1)
                        {
                            pq[lpq++] = arr[no].nxt[0];
                        }
                        if (arr[no].nxt[2] != -1)
                        {
                            pq[lpq++] = arr[no].nxt[2];
                        }
                        break;
                    }
                    case 'a':
                    {
                        if (arr[no].nxt[2] != -1)
                        {
                            pq[lpq++] = arr[no].nxt[2];
                        }
                        break;
                    }
                    case 'o':
                    {
                        if (arr[no].nxt[1] != -1)
                        {
                            pq[lpq++] = arr[no].nxt[1];
                        }
                        if (arr[no].nxt[2] != -1)
                        {
                            pq[lpq++] = arr[no].nxt[2];
                        }
                        break;
                    }
                    case 'x':
                    {
                        if (arr[no].nxt[1] != -1)
                        {
                            pq[lpq++] = arr[no].nxt[1];
                        }
                        break;
                    }
                    default:
                    {
                        break;
                    }
                }
            }
            now = rlpq;
        }
        int ans = 0;
        for (int i = now; i < lpq; i++)
        {
            int no = pq[i];
            for (int j = max(0, nb - 2); j < nb && no != -1; j++)
            {
                switch(str[j])
                {
                    case 'A':
                    {
                        no = arr[no].nxt[3];
                        break;
                    }
                    case 'O':
                    {
                        no = arr[no].nxt[0];
                        break;
                    }
                    case 'X':
                    {
                        no = arr[no].nxt[4];
                        break;
                    }
                    case 'a':
                    {
                        no = arr[no].nxt[2];
                        break;
                    }
                    case 'o':
                    {
                        no = arr[no].nxt[5];
                        break;
                    }
                    case 'x':
                    {
                        no = arr[no].nxt[1];
                        break;
                    }
                    default:
                    {
                        break;
                    }
                }
            }
            if (no != -1) ans += arr[no].val;
        }
        cout << ans << "\n";
    }
    return 0;
}