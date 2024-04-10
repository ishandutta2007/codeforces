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

static vi factorise(int n)
{
    vi out;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            out.push_back(i);
            out.push_back(n / i);
        }
    }
    return out;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int T;
    cin >> T;
    for (int cas = 0; cas < T; cas++)
    {
        int N;
        cin >> N;
        vi p(N), c(N);
        for (int i = 0; i < N; i++)
        {
            cin >> p[i];
            p[i]--;
        }
        for (int i = 0; i < N; i++)
        {
            cin >> c[i];
            c[i]--;
        }
        vector<bool> seen(N);
        int ans = INT_MAX;
        for (int i = 0; i < N; i++)
        {
            if (seen[i])
                continue;
            int x = i;
            vi cycle;
            do
            {
                seen[x] = true;
                cycle.push_back(c[x]);
                x = p[x];
            } while (x != i);

            int L = SZ(cycle);
            for (int f : factorise(L))
            {
                if (f >= ans)
                    continue;
                vi seen(f, -1);
                int p = 0;
                for (int c : cycle)
                {
                    if (seen[p] == -1)
                        seen[p] = c;
                    else if (seen[p] != c)
                        seen[p] = -2;
                    if (++p == f)
                        p = 0;
                }
                if (*max_element(RA(seen)) >= 0)
                    ans = f;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}