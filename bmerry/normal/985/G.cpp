//#pragma GCC optimize("O3")
//#pragma GCC target("arch=corei7-avx")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
# include <sys/time.h>
# include <sys/resource.h>
#endif

/*** TEMPLATE CODE STARTS HERE ***/

#ifndef M_PI
#define M_PI 3.1415926535897932384626433832795028841971693993751
#endif

using namespace std;

typedef vector<string> vs;
typedef long long ll;
typedef unsigned long long ull;
typedef complex<double> pnt;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define RA(x) begin(x), end(x)
#define FE(i, x) for (auto i = begin(x); i != end(x); ++i)
#define SZ(x) ((ll) (x).size())

template<class T>
void splitstr(const string &s, vector<T> &out)
{
    istringstream in(s);
    out.clear();
    copy(istream_iterator<T>(in), istream_iterator<T>(), back_inserter(out));
}

static void redirect(int argc, const char **argv)
{
#ifndef ONLINE_JUDGE
    struct rlimit rlim;
    getrlimit(RLIMIT_STACK, &rlim);
    rlim.rlim_cur = 256 * 1024 * 1024;
    setrlimit(RLIMIT_STACK, &rlim);
#ifndef __SANITIZE_ADDRESS__
    getrlimit(RLIMIT_DATA, &rlim);
    rlim.rlim_cur = 256 * 1024 * 1024;
    setrlimit(RLIMIT_DATA, &rlim);
#endif
#endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    if (argc > 1)
    {
        static filebuf f;
        f.open(argv[1], ios::in);
        cin.rdbuf(&f);
        if (!cin)
        {
            cerr << "Failed to open '" << argv[1] << "'" << endl;
            exit(1);
        }
    }

    if (argc > 2)
    {
        static filebuf f;
        f.open(argv[2], ios::out | ios::trunc);
        cout.rdbuf(&f);
        if (!cout)
        {
            cerr << "Failed to open '" << argv[2] << "'" << endl;
        }
    }
    cin.exceptions(ios::failbit);
}

/*** TEMPLATE CODE ENDS HERE */

static ll rsum(ll p, ll q)
{
    return (p + q - 1) * (q - p) / 2;
}

static void solve()
{
    ll N;
    int M;
    ull A, B, C;
    cin >> N >> M >> A >> B >> C;
    vector<pii> conflict(M);
    vector<vi> edge_lo(N), edge_hi(N);
    set<pii> conflict_set;
    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        if (u > v)
            swap(u, v);
        conflict[i] = pair(u, v);
        conflict_set.insert(conflict[i]);
        edge_lo[v].push_back(u);
        edge_hi[u].push_back(v);
    }

    ull ans = 0;
    // all triples
    for (ll i = 0; i < N; i++)
    {
        ans += i * (N - 1 - i) * (N - 2 - i) / 2 * A;
        ans += i * i * (N - 1 - i) * B;
        ans += i * i * (i - 1) / 2 * C;
    }
    for (const auto [u, v] : conflict)
    {
        // conflict A-B
        ans -= (A * u + B * v) * (N - 1 - v) + rsum(v + 1, N) * C;
        // conflict B-C
        ans -= (B * u + C * v) * u + rsum(0, u) * A;
        // conflict A-C
        ans -= (A * u + C * v) * (v - u - 1) + rsum(u + 1, v) * B;
    }
    for (int i = 0; i < N; i++)
    {
        sort(RA(edge_hi[i]));
        sort(RA(edge_lo[i]));
        ll nhi = SZ(edge_hi[i]);
        ll nlo = SZ(edge_lo[i]);
        // conflicts A-B, A-C
        ull shi = 0;
        for (int j = 0; j < nhi; j++)
        {
            ull v = edge_hi[i][j];
            ans += (A * i + C * v) * j + B * shi;
            shi += v;
        }
        // conflicts A-C, B-C
        ull slo = 0;
        for (int j = 0; j < nlo; j++)
        {
            ull v = edge_lo[i][j];
            ans += (B * v + C * i) * j + A * slo;
            slo += v;
        }
        // conflicts A-B, B-C
        ans += B * i * nlo * nhi + A * slo * nhi + C * shi * nlo;
    }

    // triangles
    constexpr int MAJOR_THRESH = 100;
    auto edges = move(edge_lo);
    vector<int> major;
    for (int i = 0; i < N; i++)
    {
        copy(RA(edge_hi[i]), back_inserter(edges[i]));
        edge_hi[i].clear();
        edge_hi[i].shrink_to_fit();
        if (SZ(edges[i]) >= MAJOR_THRESH)
            major.push_back(i);
    }
    for (int i = 0; i < N; i++)
    {
        if (SZ(edges[i]) < MAJOR_THRESH)
        {
            for (int j = 0; j < SZ(edges[i]); j++)
                for (int k = 0; k < j; k++)
                {
                    int u = edges[i][j];
                    int v = edges[i][k];
                    if (u > v)
                        swap(u, v);
                    if (conflict_set.count(pair(u, v)))
                    {
                        array<int, 3> x{i, u, v};
                        sort(RA(x));
                        for (int z = 0; x[z] != i; z++)
                            if (SZ(edges[x[z]]) < MAJOR_THRESH)
                                goto dup;
                        ans -= A * x[0] + B * x[1] + C * x[2];
dup:;
                    }
                }
        }
    }

    typedef bitset<200000 / MAJOR_THRESH> bs;
    vector<bs> cover(SZ(major));
    for (int i = 0; i < SZ(major); i++)
        for (int j = i + 1; j < SZ(major); j++)
            if (conflict_set.count(pair(major[i], major[j])))
            {
                cover[i].set(j);
                cover[j].set(i);
            }

    for (int i = 0; i < SZ(major); i++)
        for (int j = i + 1; j < SZ(major); j++)
            if (cover[i][j])
            {
                bs overlap = cover[i] & cover[j];
                for (int k = j + 1; k < SZ(major); k++)
                    if (overlap[k])
                    {
                        ans -= A * major[i] + B * major[j] + C * major[k];
                    }
            }
    cout << ans << '\n';
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    solve();

    return 0;
}