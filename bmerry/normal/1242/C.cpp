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

static void no()
{
    cout << "No\n";
    exit(0);
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int K;
    cin >> K;
    vector<vll> boxes(K);
    vll sums(K);
    map<ll, int> rmap;
    for (int i = 0; i < K; i++)
    {
        int N;
        cin >> N;
        ll sum = 0;
        for (int j = 0; j < N; j++)
        {
            ll x;
            cin >> x;
            boxes[i].push_back(x);
            rmap[x] = i;
            sum += x;
        }
        sums[i] = sum;
    }

    ll grand = accumulate(RA(sums), 0LL);
    if (grand % K != 0)
        no();
    grand /= K;
    for (auto &s : sums)
        s -= grand;

    vector<ll> poss(1 << K, LLONG_MAX);
    poss[0] = LLONG_MAX - 1;
    for (int i = 0; i < K; i++)
        for (ll x : boxes[i])
        {
            int used = 0;
            ll y = x;
            int trg = i;
            do
            {
                y -= sums[trg];
                if (!rmap.count(y))
                    goto bad;
                trg = rmap[y];
                if (used & (1 << trg))
                    goto bad;
                used |= 1 << trg;
            } while (trg != i);
            if (y == x)
                poss[used] = x;
bad:;
        }

    for (int i = 1; i < (1 << K); i++)
    {
        if (poss[i] != LLONG_MAX)
            continue;
        for (int j = (i - 1) & i; j != 0; j = (j - 1) & i)
        {
            if (poss[j] != LLONG_MAX && poss[i - j] != LLONG_MAX)
            {
                poss[i] = poss[j];
                break;
            }
        }
    }

    int mask = (1 << K) - 1;
    if (poss[mask] == LLONG_MAX)
        no();

    cout << "Yes\n";
    vector<pii> ans(K);
    while (mask)
    {
        ll x = poss[mask];
        ll y = x;
        int trg = rmap[y];
        do
        {
            int old_trg = trg;
            y -= sums[trg];
            trg = rmap.find(y)->second;
            ans[trg] = pair(y, old_trg);
            mask ^= 1 << trg;
        } while (trg != rmap[x]);
    }
    for (const auto &row : ans)
        cout << row.first << ' ' << row.second + 1 << '\n';

    return 0;
}