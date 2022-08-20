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
typedef complex<double> pnt;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define RA(x) begin(x), end(x)
#define FE(i, x) for (auto i = begin(x); i != end(x); ++i)
#define SZ(x) ((int) (x).size())

template<class T>
void splitstr(const string &s, vector<T> &out)
{
    istringstream in(s);
    out.clear();
    copy(istream_iterator<T>(in), istream_iterator<T>(), back_inserter(out));
}

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

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

struct polygon
{
    int idx;
    int V;
    vi verts;
};

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N;
    cin >> N;
    vi boundary;
    vector<polygon> poly(N);
    for (int i = 0; i < N; i++)
    {
        cin >> poly[i].V;
        poly[i].idx = i;
    }
    sort(RA(poly), [](const auto &a, const auto &b) { return a.V > b.V; });

    set<pii> used;
    int V = poly[0].V;
    for (int i = 0; i < poly[0].V; i++)
        poly[0].verts.push_back(i);
    boundary = poly[0].verts;

    for (int i = 0; i < V - 1; i++)
        used.insert(pii(i, i + 1));
    used.insert(pii(V - 1, 0));

    for (int i = 1; i < N; i++)
    {
        int limit = (i == N - 1) ? 3 : poly[i + 1].V;
        int share = (SZ(boundary) + poly[i].V - limit) / 2;
        share = min(share, SZ(boundary) - 1);
        share = min(share, poly[i].V - 1);
        assert(share >= 1);
        if (share == poly[i].V - 1
            && used.count(pii(boundary.back(), boundary[SZ(boundary) - 1 - share])))
            rotate(boundary.begin(), boundary.begin() + 1, boundary.end());

        poly[i].verts.reserve(poly[i].V);
        for (int j = 0; j < poly[i].V - share - 1; j++)
            poly[i].verts.push_back(V++);
        for (int j = 0; j <= share; j++)
            poly[i].verts.push_back(boundary[SZ(boundary) - 1 - j]);
        for (int j = 0; j < poly[i].V - 1; j++)
            used.insert(pii(poly[i].verts[j], poly[i].verts[j + 1]));
        used.insert(pii(poly[i].verts.back(), poly[i].verts[0]));

        boundary.erase(boundary.end() - share, boundary.end());
        for (int j = 0; j < poly[i].V - share; j++)
            boundary.push_back(poly[i].verts[j]);
    }

    sort(RA(poly), [](const auto &a, const auto &b) { return a.idx < b.idx; });
    cout << V << '\n';
    for (int i = 0; i < N; i++)
    {
        for (int v : poly[i].verts)
            cout << v + 1 << ' ';
        cout << '\n';
    }

    return 0;
}