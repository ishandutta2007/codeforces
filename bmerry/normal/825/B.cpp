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

static const int dr[4] = {-1, 0, 1, 1};
static const int dc[4] = {1, 1, 1, 0};

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    vs grid(10);
    for (int i = 0; i < 10; i++)
        cin >> grid[i];
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            for (int d = 0; d < 4; d++)
            {
                int r = i, c = j;
                int cross = 0;
                for (int k = 0; k < 5; k++)
                {
                    if (r < 0 || r >= 10 || c < 0 || c >= 10 || grid[r][c] == 'O')
                    {
                        cross = -1;
                        break;
                    }
                    cross += grid[r][c] == 'X';
                    r += dr[d];
                    c += dc[d];
                }
                if (cross == 4)
                {
                    cout << "YES\n";
                    return 0;
                }
            }
    cout << "NO\n";

    return 0;
}