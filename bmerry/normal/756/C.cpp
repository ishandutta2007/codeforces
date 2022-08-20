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

struct node
{
    int sum = 0;
    int lo = 0;
    int hi = 0;

    void set(int v)
    {
        sum = lo = hi = v;
    }

    node operator+(const node &other) const
    {
        node out;
        out.sum = sum + other.sum;
        out.lo = min(other.lo, lo + other.sum);
        out.hi = max(other.hi, hi + other.sum);
        return out;
    }
};

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
    redirect(argc, argv);
    int N;
    cin >> N;
    int T = 1;
    while (T < N)
        T *= 2;
    vector<node> nodes(2 * T);
    vector<int> vals(N);
    for (int i = 0; i < N; i++)
    {
        int p, t;
        cin >> p >> t;
        p--;
        if (t == 1)
        {
            cin >> vals[p];
            nodes[p + T].set(1);
        }
        else
            nodes[p + T].set(-1);
        for (int j = (p + T) / 2; j >= 1; j >>= 1)
            nodes[j] = nodes[2 * j] + nodes[2 * j + 1];

        if (nodes[1].hi <= 0)
            cout << "-1\n";
        else
        {
            int trg = 1;
            int cur = 1;
            while (cur < T)
            {
                if (nodes[2 * cur + 1].lo <= trg && nodes[2 * cur + 1].hi >= trg)
                    cur = 2 * cur + 1;
                else
                {
                    trg -= nodes[2 * cur + 1].sum;
                    cur = 2 * cur;
                }
            }
            assert(trg == 1 && nodes[cur].sum == 1);
            cout << vals[cur - T] << '\n';
        }
    }

    return 0;
}