#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
# include <sys/time.h>
# include <sys/resource.h>
#endif

/*** TEMPLATE CODE STARTS HERE ***/

using namespace std;

typedef vector<string> vs;
typedef long long ll;
typedef complex<double> pnt;
typedef vector<ll> vi;
typedef pair<ll, ll> pii;

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
    getrlimit(RLIMIT_DATA, &rlim);
    rlim.rlim_cur = 256 * 1024 * 1024;
    setrlimit(RLIMIT_DATA, &rlim);
#endif

    ios::sync_with_stdio(false);
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

struct domino
{
    int r[2], c[2];
    domino(int r0, int c0, int r1, int c1)
    {
        r[0] = r0;
        r[1] = r1;
        c[0] = c0;
        c[1] = c1;
    }
};

static vector<pair<int, int>> solve(int R, int C, vector<domino> &dom)
{
    int D = SZ(dom);
    vector<vector<int>> rev(R, vector<int>(C, -1));
    for (int i = 0; i < D; i++)
        for (int s = 0; s < 2; s++)
            rev[dom[i].r[s]][dom[i].c[s]] = i;
    vector<pair<int, int>> out;

    auto rotate = [&] (int r, int c)
    {
        assert(r < R - 1 && c < C - 1);
        assert((rev[r][c] == rev[r + 1][c] && rev[r][c + 1] == rev[r + 1][c + 1])
               || (rev[r][c] == rev[r][c + 1] && rev[r + 1][c] == rev[r + 1][c + 1]));
        int d0 = rev[r][c];
        int d1 = rev[r + 1][c];
        if (d1 == d0)
            d1 = rev[r][c + 1];
        swap(dom[d0].r[1], dom[d1].r[0]);
        swap(dom[d0].c[1], dom[d1].c[0]);
        swap(rev[r][c + 1], rev[r + 1][c]);
        out.emplace_back(r, c);
    };

restart:
    for (int i = 0; i < R - 1; i++)
        for (int j = 0; j < C; j++)
        {
            int d = rev[i][j];
            if (dom[d].c[0] == j && dom[d].c[1] == j + 1)
            {
                int b0 = rev[i + 1][j];
                int b1 = rev[i + 1][j + 1];
                if (b0 == b1)
                {
                    rotate(i, j);
                    goto restart;
                }
                else if (dom[b0].r[1] == i + 2
                         && dom[b1].r[1] == i + 2)
                {
                    rotate(i + 1, j);
                    rotate(i, j);
                    goto restart;
                }
            }
        }
    return out;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int R, C;
    cin >> R >> C;
    vector<domino> dom[2];
    for (int pass = 0; pass < 2; pass++)
    {
        for (int i = 0; i < R; i++)
        {
            string line;
            cin >> line;
            for (int j = 0; j < C; j++)
            {
                if (line[j] == 'U')
                    dom[pass].emplace_back(i, j, i + 1, j);
                else if (line[j] == 'L')
                    dom[pass].emplace_back(i, j, i, j + 1);
            }
        }
    }

    bool flip = false;
    if (R & 1)
    {
        swap(R, C);
        for (int pass = 0; pass < 2; pass++)
            for (auto &d : dom[pass])
            {
                swap(d.r[0], d.c[0]);
                swap(d.r[1], d.c[1]);
            }
        flip = true;
    }

    auto path0 = solve(R, C, dom[0]);
    auto path1 = solve(R, C, dom[1]);
    copy(path1.rbegin(), path1.rend(), back_inserter(path0));
    cout << SZ(path0) << '\n';
    for (const auto &item : path0)
    {
        int r = item.first + 1;
        int c = item.second + 1;
        if (flip)
            swap(r, c);
        cout << r << ' ' << c << '\n';
    }

    return 0;
}