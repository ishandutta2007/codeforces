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
}

/*** TEMPLATE CODE ENDS HERE */

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N;
    cin >> N;
    vi trg(N);
    vi inv(N);
    for (int i = 0; i < N; i++)
    {
        cin >> trg[i];
        trg[i]--;
    }
    vs grid(N, string(N, '.'));
    int ans = N;
    if (!is_sorted(RA(trg)))
    {
        ans--;
        int y = N - 1;
        int hole = N - 1;

        auto moveto = [&](int a, int b)
        {
            assert(a != b);
            if (a < b)
            {
                grid[y][a] = '/';
                grid[y][b] = '/';
            }
            else
            {
                grid[y][a] = '\\';
                grid[y][b] = '\\';
            }
            y--;
        };
        auto moveto3 = [&](int a, int b, int c)
        {
            assert(a < b && b < c);
            grid[y][a] = '/';
            grid[y][b] = '/';
            grid[y][c] = '/';
            y--;
        };

        vector<bool> done(N);
        vector<vi> cycles;
        for (int i = N - 1; i >= 0; i--)
            if (!done[i])
            {
                vi c;
                int j = i;
                do
                {
                    c.push_back(j);
                    done[j] = true;
                    j = trg[j];
                } while (j != i);
                cycles.push_back(move(c));
            }

        for (int i = 1; i < SZ(cycles); i++)
        {
            const auto &c = cycles[i];
            if (SZ(c) == 1)
                continue;
            moveto3(c.back(), c[0], hole);
            for (int i = SZ(c) - 2; i > 0; i--)
                moveto(c[i], c[i + 1]);
            moveto(hole, c[1]);
        }

        const auto &c = cycles[0];
        for (int i = SZ(c) - 1; i > 0; i--)
            moveto(c[i], c[(i + 1) % SZ(c)]);
    }

    cout << ans << '\n';
    for (int i = 0; i < N; i++)
        cout << grid[i] << '\n';

    return 0;
}