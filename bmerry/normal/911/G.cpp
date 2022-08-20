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
}

/*** TEMPLATE CODE ENDS HERE */

static void adjust(list<int> &X, list<int> &Y, int l, int r)
{
    auto it = X.begin();
    while (it != X.end())
    {
        auto nxt = next(it);
        if (*it >= l && *it < r)
            Y.splice(Y.begin(), X, it);
        it = nxt;
    }
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N;
    cin >> N;
    int S = min(500, N);
    int M = (N + S - 1) / S;
    int H = 101;
    vector<vector<list<int>>> pos(H, vector<list<int>>(M));
    for (int i = 0; i < N; i++)
    {
        int s = i / S;
        int a;
        cin >> a;
        pos[a][s].push_back(i);
    }
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        int l, r, x, y;
        cin >> l >> r >> x >> y;
        l--;
        if (x == y)
            continue;
        int sl = l / S;
        int sr = (r - 1) / S;
        adjust(pos[x][sl], pos[y][sl], l, r);
        if (sl != sr)
            adjust(pos[x][sr], pos[y][sr], l, r);
        for (int i = sl + 1; i < sr; i++)
            pos[y][i].splice(pos[y][i].begin(), std::move(pos[x][i]));
    }

    vi a(N);
    for (int i = 0; i < M; i++)
        for (int j = 0; j < H; j++)
            for (int p : pos[j][i])
                a[p] = j;

    for (int i = 0; i < N; i++)
        cout << a[i] << ' ';
    cout << '\n';

    return 0;
}