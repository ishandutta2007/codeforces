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
#define SZ(x) ((ll) (x).size())

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

typedef array<int, 18> link_t;

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N, M;
    cin >> N >> M;
    vector<pii> a(N);
    for (int i = 0; i < N; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    sort(RA(a), [](const pii &x, const pii &y) { return pii(x.first, -x.second) < pii(y.first, -y.second); });

    vector<pii> a2;
    a2.reserve(N + 1);
    for (const pii &x : a)
    {
        if (a2.empty() || x.second > a2.back().second)
            a2.push_back(x);
    }
    a = move(a2);
    N = SZ(a);
    a.emplace_back(INT_MAX / 2, INT_MAX / 2);

    vector<link_t> links(N + 1);
    int p = 0;
    for (int i = 0; i < N; i++)
    {
        while (p + 1 < N && a[p + 1].first <= a[i].second)
            p++;
        links[i][0] = (p > i) ? p : N;
    }
    links[N][0] = N;
    for (int i = 1; i < 18; i++)
    {
        for (int j = 0; j <= N; j++)
            links[j][i] = links[links[j][i - 1]][i - 1];
    }

    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        int pos = upper_bound(RA(a), pii(u, INT_MAX)) - a.begin();
        pos--;
        if (pos == -1)
        {
            cout << "-1\n";
            continue;
        }
        int end = pos;
        int dist = 1;
        for (int j = 17; j >= 0; j--)
        {
            int nxt = links[end][j];
            if (a[nxt].second < v)
            {
                end = nxt;
                dist += (1 << j);
            }
        }
        while (a[end].second < v)
        {
            end = links[end][0];
            dist++;
        }
        if (end < N)
            cout << dist << '\n';
        else
            cout << "-1\n";
    }

    return 0;
}