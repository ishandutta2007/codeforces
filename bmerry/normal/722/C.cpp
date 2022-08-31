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

struct interval
{
    int first;
    int last;
    ll sum;
};

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N;
    cin >> N;
    vector<ll> a(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];
    vector<int> perm(N);
    for (int i = 0; i < N; i++)
    {
        cin >> perm[i];
        perm[i]--;
    }
    vector<ll> ans(N);

    map<int, interval> ivs;
    ivs.emplace(N + 2, interval{N + 2, N + 2, 0LL});
    ivs.emplace(-2, interval{-2, -2, 0LL});
    ll top = 0;
    for (int i = N - 1; i > 0; i--)
    {
        top = max(top, a[perm[i]]);
        auto q = ivs.upper_bound(perm[i]);
        auto p = prev(q);
        if (p->second.last == perm[i])
        {
            p->second.last = perm[i] + 1;
            p->second.sum += a[perm[i]];
            top = max(top, p->second.sum);
        }
        else
            p = ivs.insert(q, make_pair(perm[i], interval{perm[i], perm[i] + 1, a[perm[i]]}));
        if (q->first == perm[i] + 1)
        {
            p->second.last = q->second.last;
            p->second.sum += q->second.sum;
            top = max(top, p->second.sum);
            ivs.erase(q);
        }
        ans[i - 1] = top;
    }
    for (int i = 0; i < N; i++)
        cout << ans[i] << '\n';

    return 0;
}