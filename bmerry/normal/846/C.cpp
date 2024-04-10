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
    int N;
    cin >> N;
    vector<ll> a(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];
    vector<ll> b(N + 1);
    partial_sum(RA(a), b.begin() + 1);

    tuple<int, int, int> ans{};
    ll best_sum = LLONG_MIN;
    for (int y = 0; y <= N; y++)
    {
        int best_x = -1;
        ll best_pre = LLONG_MIN;
        for (int x = 0; x <= y; x++)
        {
            ll pre = 2 * b[x] - b[0] - b[y];
            if (pre > best_pre)
            {
                best_pre = pre;
                best_x = x;
            }
        }
        int best_z = -1;
        ll best_suf = LLONG_MIN;
        for (int z = y; z <= N; z++)
        {
            ll suf = 2 * b[z] - b[y] - b[N];
            if (suf > best_suf)
            {
                best_suf = suf;
                best_z = z;
            }
        }

        ll sum = best_pre + best_suf;
        if (sum > best_sum)
        {
            best_sum = sum;
            ans = make_tuple(best_x, y, best_z);
        }
    }

    cout << get<0>(ans) << ' ' << get<1>(ans) << ' ' << get<2>(ans) << '\n';
    return 0;
}