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

typedef bitset<4096> bits;

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N, K, Q;
    cin >> N >> K >> Q;
    vector<vector<int>> props(N, vi(K));
    for (int i = 0; i < K; i++)
        for (int j = 0; j < N; j++)
            cin >> props[j][i];
    vector<bits> creat;
    creat.reserve(K + Q);
    creat.resize(K);
    for (int i = 0; i < K; i++)
    {
        for (int j = 0; j < (1 << K); j++)
            creat[i][j] = (j >> i) & 1;
    }

    for (int i = 0; i < Q; i++)
    {
        int t, x, y;
        cin >> t >> x >> y;
        x--;
        y--;
        switch (t)
        {
        case 1:
            creat.push_back(creat[x] & creat[y]);
            break;
        case 2:
            creat.push_back(creat[x] | creat[y]);
            break;
        case 3:
            {
                int ans = INT_MAX;
                for (int i = 0; i < K; i++)
                {
                    int value = props[y][i];
                    int mask = 0;
                    for (int j = 0; j < K; j++)
                        mask |= int(props[y][j] <= value) << j;
                    if (creat[x][mask])
                        ans = min(ans, value);
                }
                cout << ans << '\n';
            }
            break;
        }
    }

    return 0;
}