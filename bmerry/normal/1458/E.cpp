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

struct position
{
    int x, y;

    bool operator<(const position &other) const
    {
        return pair(x, y) < pair(other.x, other.y);
    }
};

struct query
{
    int idx;
    int x, y;

    bool operator<(const query &other) const
    {
        return pair(x, y) < pair(other.x, other.y);
    }
};

static void solve()
{
    int N, M;
    cin >> N >> M;
    vector<position> sch(N), scl;
    set<position> scs;
    vector<query> queries(M);
    vector<bool> lose(M);
    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        sch[i] = position{x, y};
        scs.insert(sch[i]);
    }
    scs.insert(position{0, 0});
    for (int i = 0; i < M; i++)
    {
        int x, y;
        cin >> x >> y;
        queries[i] = query{i, x, y};
        if (scs.count(position{x, y}))
            lose[i] = true;
    }
    sort(RA(queries));

    scl = sch;
    sort(RA(scl), [](auto a, auto b) { return pair(a.x, a.y) < pair(b.x, b.y); });
    sort(RA(sch), [](auto a, auto b) { return pair(a.y, a.x) < pair(b.y, b.x); });
    int pl = 0, ph = 0;
    int x = 0, y = 0, q = 0;
    while (q < M)
    {
        while (ph < N && sch[ph].y < y)
            ph++;
        while (pl < N && scl[pl].x < x)
            pl++;
        int ylim = ph < N ? sch[ph].y : INT_MAX / 2;
        int xlim = pl < N ? scl[pl].x : INT_MAX / 2;
        int steps = min(xlim - x, ylim - y);

        int nx = x + steps;
        int ny = y + steps;
        if (ph < N && sch[ph].y == ny && sch[ph].x < nx)
            ny++;
        else if (pl < N && scl[pl].x == nx && scl[pl].y < ny)
            nx++;
        else if (steps == 0)
        {
            steps++;
            nx++;
            ny++;
        }

        while (q < M && queries[q].x < x)
            q++;
        while (q < M && queries[q].x < x + steps)
        {
            if (queries[q].x - queries[q].y == x - y)
                lose[queries[q].idx] = true;
            q++;
        }

        x = nx;
        y = ny;
    }

    for (int i = 0; i < M; i++)
        cout << (lose[i] ? "LOSE\n" : "WIN\n");
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    solve();

    return 0;
}