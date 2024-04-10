#include <iostream>
#include <map>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <vector>
#include <deque>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <unordered_map>
#include <string>
#include <set>
#include <iomanip>
#include <bitset>
#include <queue>
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
#define fst first
#define snd second
#define ld long double
const double PI = acos(-1);
const int N = 3e5 + 5;
int MOD = 998244353;
template<class A, class B>

void sum(A &a, B b)
{
    a += b;
    if (a < 0) a += MOD;
    if (a >= MOD) a -= MOD;
}
template <class T>
inline void hash_combine(std::size_t & seed, const T & v)
{
    std::hash<T> hasher;
    seed ^= hasher(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

namespace std
{
    template<typename S, typename T> struct hash<pair<S, T>>
    {
        inline size_t operator()(const pair<S, T> & v) const
        {
            size_t seed = 0;
            ::hash_combine(seed, v.first);
            ::hash_combine(seed, v.second);
            return seed;
        }
    };
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
int n;
unordered_map< pair<int , int>, int> has;
set<int>unused;
int cnt = 0;
vector<int> comp;
bool used[N];
int dp = 0;
pair<int , int> deg[N];
bool fuck = false;

int iters = 0;

void bfs(int u)
{
    if (fuck) {
        return;
    }
    
    queue<int> q;
    q.push(u);
    unused.erase(u);
    dp++;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        iters++;
        if (iters % 100 == 0) {
            if ((double)clock() / CLOCKS_PER_SEC > 1.9) {
                fuck = true;
                return;
            }
        }
        vector<int>trash;
        for (auto i:unused) {
            if (unused.count(i)) {
                if (!has[mp(u, i)]) {
                    q.push(i);
                    dp++;
                    trash.push_back(i);
                }
            }
        }
        for(auto x:trash){
          unused.erase(x);
        }
    }
}
int main()
{
    srand(time(0));
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int  m ;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        unused.insert(i);
        deg[i].first = n - 1;
        deg[i].second = i;
    }
    for(int i = 0; i < m; i++)
    {
        int u , v;
        cin >> u >> v;
        u--;
        v--;
        has[mp(v, u)] = 1;
        has[mp(u , v)] = 1;
        deg[u].first--;
        deg[v].first--;
    }
    int sum = 0;

    sort(deg, deg + n);
    for(int i = 0; i < n; i++)
    {
        int j = deg[i].second;
        if(unused.count(j))
        {
            bfs(j);
            comp.pb(dp);
            sum += dp;
            dp = 0;
        }
    }
    if(sum < n)
    {
        comp.pb(n - sum);
        sort(comp.begin(), comp.end());
    }
    cout << comp.size() << "\n";
    sort(comp.begin(), comp.end());
    for(int i =0 ; i < comp.size(); i++)
    {
        cout << comp[i] << " ";
    }
    
    fprintf(stderr, "%.6f\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}