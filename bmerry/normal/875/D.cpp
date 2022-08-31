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

constexpr int BITS = 30;

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N;
    cin >> N;
    vi a(N);
    vector<vi> bpos(BITS);
    vector<pii> ordered(N);
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
        ordered[i] = pii(a[i], i);
        for (int j = 0; j < BITS; j++)
            if (a[i] & (1 << j))
                bpos[j].push_back(i);
    }
    for (int j = 0; j < BITS; j++)
        bpos[j].push_back(N);
    sort(RA(ordered));
    ll ans = 0;
    for (int i = 0; i < N; i++)
    {
        int r = i;
        int cur = a[i];
        vector<int> addbit;
        for (int j = 0; j < BITS; j++)
            if (!(cur & (1 << j)))
                addbit.push_back(*upper_bound(RA(bpos[j]), i));
        sort(RA(addbit));
        addbit.push_back(N);
        addbit.resize(unique(RA(addbit)) - addbit.begin());
        int nxt = 0;
        while (r < N)
        {
            int s = addbit[nxt++];
            int stop = s;
            auto stoppos = lower_bound(RA(ordered), pii(cur, i));
            if (stoppos != ordered.end() && stoppos->first == cur && stoppos->second < stop)
                stop = stoppos->second;
            ans += stop - r;
            if (s < N)
                cur |= a[s];
            r = s;
        }
    }
    cout << ans << '\n';

    return 0;
}