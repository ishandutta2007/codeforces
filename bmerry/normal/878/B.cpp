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

struct run
{
    int city;
    int freq;
};

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N, K, M;
    cin >> N >> K >> M;
    vector<run> runs;
    for (int i = 0; i < N; i++)
    {
        int city;
        cin >> city;
        if (runs.empty() || runs.back().city != city)
            runs.push_back(run{city, 0});
        runs.back().freq++;
        if (runs.back().freq == K)
            runs.pop_back();
    }
    vector<run> pre, post;
    int p = 0, q = SZ(runs);
    while (q > p + 1)
    {
        if (runs[p].city == runs[q - 1].city && runs[p].freq + runs[q - 1].freq >= K)
        {
            pre.emplace_back(runs[p]);
            post.emplace_back(runs[q - 1]);
            runs[q - 1].freq += runs[p].freq - K;
            p++;
            if (runs[q - 1].freq == 0)
                q--;
            else
            {
                M--;
                for (int i = q - 2; i >= p; i--)
                    post.push_back(runs[i]);
                break;
            }
        }
        else
            break;
    }

    ll ans = 0;
    if (q - p == 1)
    {
        runs[p].freq = (ll) M * runs[p].freq % K;
        if (runs[p].freq > 0)
            pre.push_back(runs[p]);
    }
    else
    {
        for (int i = p; i < q; i++)
            ans += (ll) M * runs[i].freq;
        pre.push_back(run{-3, 0});
    }
    pre.insert(pre.end(), post.rbegin(), post.rend());
    runs.clear();
    for (const run &r : pre)
    {
        if (runs.empty() || runs.back().city != r.city)
            runs.push_back(run{r.city, 0});
        runs.back().freq += r.freq;
        if (runs.back().freq >= K)
            runs.back().freq -= K;
        if (runs.back().freq == 0 && runs.back().city >= 0)
            runs.pop_back();
    }
    for (const run &r : runs)
        ans += r.freq;
    cout << ans << '\n';

    return 0;
}