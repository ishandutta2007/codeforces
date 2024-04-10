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

static int N;
static vi a;

struct segment
{
    int L = 0, R = 0;
    ll cost = 0;
    vi freq;

    void incL()
    {
        int x = a[L];
        L++;
        freq[x]--;
        cost -= freq[x];
    }

    void incR()
    {
        int x = a[R];
        R++;
        cost += freq[x];
        freq[x]++;
    }

    void decL()
    {
        L--;
        int x = a[L];
        cost += freq[x];
        freq[x]++;
    }

    void Lto(int trg)
    {
        while (L < trg)
            incL();
        while (L > trg)
            decL();
    }

    void incRto(int trg)
    {
        while (R < trg)
            incR();
        assert(R == trg);
    }

    void reset()
    {
        L = R = 0;
        cost = 0;
        fill(RA(freq), 0);
    }
};

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int K;
    cin >> N >> K;
    a.resize(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];

    vector<pair<ll, int>> cut(N + 1);
    segment seg;
    seg.freq.resize(N + 1);
    for (int i = 1; i <= N; i++)
    {
        seg.incR();
        cut[i].first = seg.cost;
    }

    for (int pass = 0; pass < K - 1; pass++)
    {
        vector<pair<ll, int>> cut2(N + 1);
        int step = 1;
        while (step < N)
            step *= 2;
        for (; step >= 1; step >>= 1)
        {
            seg.reset();
            for (int i = step; i <= N; i += 2 * step)
            {
                int lo = cut2[i - step].second;
                int hi;
                if (i + step <= N)
                    hi = cut2[i + step].second;
                else
                    hi = N;
                hi = min(hi, i - 1);
                seg.incRto(i);
                ll bestcost = LLONG_MAX;
                int bestpos = -1;
                for (int j = lo; j <= hi; j++)
                {
                    seg.Lto(j);
                    ll cost = seg.cost + cut[j].first;
                    if (cost < bestcost)
                    {
                        bestcost = cost;
                        bestpos = j;
                    }
                }
                cut2[i] = make_pair(bestcost, bestpos);
            }
        }
        cut = move(cut2);
    }
    cout << cut[N].first << '\n';

    return 0;
}