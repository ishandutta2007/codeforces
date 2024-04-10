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
    int w, N, M;
    cin >> w >> N >> M;
    vi f(1 << w);
    int w2 = 1 << w;
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        f[a]++;
    }
    vi mob = f;
    vector<vi> dont(w2, vi(w2));
    for (int mask = 0; mask < w2; mask++)
    {
        for (int i = 0; i < w2; i++)
            dont[mask][i & ~mask] += f[i];
    }

    for (int i = 0; i < M; i++)
    {
        int sum = 0;
        string query;
        cin >> query;
        int gates[6] = {};
        for (int j = 0; j < w; j++)
        {
            int g = 0;
            switch (query[j])
            {
            case 'A': g = 0; break;
            case 'O': g = 1; break;
            case 'X': g = 2; break;
            case 'a': g = 3; break;
            case 'o': g = 4; break;
            case 'x': g = 5; break;
            default: abort();
            }
            gates[g] |= w2 >> (j + 1);
        }

        for (int i = 0; i < w2; i++)
        {
            int dc = 0;
            int bits = 0;
            if (i & gates[1])
                continue;
            if (~i & gates[3])
                continue;
            bits |= (i & gates[3]);
            dc |= (~i & gates[0]);
            bits |= (i & gates[2]);
            bits |= (~i & gates[5]);
            dc |= i & gates[4];
            bits |= (~i & gates[4]);
            sum += f[i] * dont[dc][bits & ~dc];
        }
        cout << sum << '\n';
    }

    return 0;
}