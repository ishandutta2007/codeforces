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

int main(int argc, const char **argv)
{
    const int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
    const int np = 12;

    redirect(argc, argv);
    int N, M;
    cin >> N >> M;
    vector<int> K(N);
    vector<vector<pair<int, int>>> pos(M + 1);
    for (int i = 0; i < N; i++)
    {
        cin >> K[i];
        for (int j = 0; j < K[i]; j++)
        {
            int v;
            cin >> v;
            pos[v].emplace_back(i, j);
        }
    }

    vector<vector<int>> factors(41);
    for (int i = 1; i <= 40; i++)
    {
        for (int j = 0; j < np; j++)
            for (int v = primes[j]; v <= i; v *= primes[j])
                if (i % v == 0)
                    factors[i].push_back(v);
    }

    for (int i = 1; i <= M; i++)
    {
        int start = 0;
        int stop = 0;
        int best = 0;
        int phase[41];
        int refs[41];
        memset(phase, -1, sizeof(phase));
        memset(refs, 0, sizeof(refs));
        for (const auto &p : pos[i])
        {
            if (p.first > stop)
            {
                start = stop = p.first;
                memset(refs, 0, sizeof(refs));
            }
            int k = K[p.first];
            for (int f : factors[k])
            {
                int ph = p.second % f;
                if (refs[f] != 0 && phase[f] != ph)
                {
                    while (refs[f] != 0)
                    {
                        for (int f2 : factors[K[start]])
                            refs[f2]--;
                        start++;
                    }
                }
                phase[f] = ph;
                refs[f]++;
            }
            stop = p.first + 1;
            best = max(best, stop - start);
        }
        cout << best << '\n';
    }
    return 0;
}