#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops", "omit-frame-pointer", "inline")
#pragma GCC optimization("O3")
using namespace std;

/// Macros
#define int long long
#define it(x) x::iterator
#define pb push_back
#define pf push_front
#define lb lower_bound
#define up upper_bound
#define fs first
#define sc second
#define endl '\n'
#define pf push_front
#define all(x) x.begin(), x.end()
#define mp make_pair
#define sz(x) (int)(x.size())

#define FOR(i, a, n) for (int i = a; i < (n); i++)
#define FO(i, n) for (int i = 0; i < (n); i++)
#define RFOR(i, a, n) for (int i = (n)-1; i >= a; i--)
#define RFO(i, n) for (int i = (n)-1; i >= 0; i--)
#define gof(i, n)     \
    for (auto &i : n) \
        ;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

/// Constraints:
const int inf = ((1ll << 31ll) - 1ll);
const int INF = (((1ll << 59ll) - 1ll) * 2ll) + 1ll;
const ull mod = 1000000007;
const ld pi = acos(-1);
/// Functions:
#define lg2(x) 31 - __builtin_clz(x)
#define lg2ll(x) 63 - __builtin_clzll(x)
#define lgx(x, b) (log(x) / log(b))
#define YN(x) cout << ((x) ? ("YES") : ("NO")) << fl;
#define yn(x) cout << ((x) ? ("Yes") : ("No")) << fl;
/*void print(vector<int>v){for(auto that:v)cout<<that<<" ";cout<<endl;}
vector<int>read(int cnt){vi v(cnt);for(int i=0;i<cnt;i++)cin>>v[i];return v;}*/

/*#include<ext/pb_ds/assoc_container.hpp> // Common file
#include<ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
//comenta el define long long int
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;*/
// find_by_order
// order_of_key

/// Quick Pow------------------------------------------------
int qpow(int b, int e)
{
    if (!e)
        return 1;
    if (e & 1)
        return qpow(b, e - 1) * b % mod;
    int pwur = qpow(b, e >> 1);
    return pwur * pwur % mod;
}
/// Inverso Modular
int InverM(int a, int b)
{
    int eso = a - (a / b) * b;
    if (eso == 0)
        return 0;
    int ans = (1 - b * InverM(b, eso)) / eso;
    if (ans < 0)
        ans += b;
    return ans;
}
const int MAXN = 1000007;
/// Variables------------------------------------------------
int tc, n, m, k, q;
vector<int> Mat;
void Criba()
{
    Mat.resize(MAXN);
    Mat[1] = 1;
    Mat[2] = 2;
    for (int i = 4; i < MAXN; i += 2)
    {
        Mat[i] = 2;
    }
    for (int i = 3; i < MAXN; i += 2)
    {
        if (Mat[i] != 0)
            continue;
        Mat[i] = i;
        for (int j = 2 * i; j < MAXN; j += i)
        {
            Mat[j] = i;
        }
    }
}

vector<int> G[MAXN];
int Nodes[MAXN];
vector<int> Cur;
void BFS(int a)
{
    Cur.resize(0);
    queue<ii> Q;
    Q.push(mp(a, -1));
    Nodes[a] = 1;
    Cur.pb(a);
    while (!Q.empty())
    {
        int p = (Q.front()).fs;
        int j = (Q.front()).sc;
        Q.pop();
        for (int i = 0; i < G[p].size(); i++)
        {
            int v = G[p][i];
            if (v == j)
                continue;

            if (Nodes[v] != 0)
            {
                m = min(m, Nodes[v] + Nodes[p] - 1);
                break;
            }
            Nodes[v] = Nodes[p] + 1;
            Cur.pb(v);
            Q.push(mp(v, p));
        }
    }
    for (int i = 0; i < Cur.size(); i++)
    {
        Nodes[Cur[i]] = 0;
    }
}

void problem()
{
    Criba();
    cin >> n;
    vector<ii> A;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        int c = -1, d = -1, cc = 0,cd = 0;
        while (a != 1)
        {
            if(c==-1)
            {
                cc++;
            }
            else
            {
                cd++;
            }
            if(c==-1 && Mat[a]!=Mat[a/Mat[a]])
            {
                c=Mat[a];
                d=Mat[a/Mat[a]];
            }
            a/=Mat[a];
        }
        // cout << cc << ' ' << cd << '\n';
        // cout << c << ' ' << d << '\n';
        if(cc%2==0)
        {
            c=d;
            d=1;
            cc=cd;
            cd=0;
        }
        if(cc%2==0)
        {
            c=d;
            d=1;
            cc=cd;
            cd=0;
        }
        if(cd%2==0)
        {
            d=1;
            cd=0;
        }

        if (c*d == 1)
        {
            cout << 1;
            return;
        }
        if (d == -1)
            d = 1;
        // cout << c << ' ' << d << '\n';
        A.pb(mp(max(c, d), min(c, d)));
    }
    sort(all(A));
    for (int i = 0; i < sz(A) - 1; i++)
    {
        if (A[i] == A[i + 1])
        {
            cout << 2;
            return;
        }
    }

    for (int i = 0; i < sz(A); i++)
    {
        G[A[i].fs].pb(A[i].sc);
        G[A[i].sc].pb(A[i].fs);
    }
    m = INF;
    for (int i = 1; i < 1001; i++)
    {
        if (i == Mat[i])
        {
            BFS(i);
        }
    }
    if (INF == m)
    {
        cout << -1;
    }
    else
    {
        cout << m;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.setf(ios::fixed);
    cout.precision(12);
    // freopen("a.in","w",stdin)
    // freopen("a.out","w",stdout);

    tc = 1;
    while (tc--)
    {

        problem();
        cout << endl;
    }
    return 0;
}

/// Tips
// Busqueda Binaria
// Precomputing
// Dinamic Programming
// Revisar constraints