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

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N;
    cin >> N;
    string a, b;
    cin >> a >> b;
    vi delta(N);
    delta[0] = b[0] - a[0];
    ll ans = abs(delta[0]);
    for (int i = 1; i < N; i++)
    {
        delta[i] = (b[i] - a[i]) - delta[i - 1];
        ans += abs(delta[i]);
    }

    if (delta[N - 1] != 0)
    {
        cout << "-1\n";
        return 0;
    }
    cout << ans << '\n';

    auto is_valid = [&](int i) {
        return ((delta[i] > 0 && a[i] < '9' && a[i + 1] < '9')
                || (delta[i] < 0 && a[i] > '0' && a[i + 1] > '0'));
    };

    set<int> valid;
    for (int i = 0; i < N - 1; i++)
        if (is_valid(i))
            valid.insert(i);

    int lines = 0;
    while (lines < 100000 && !valid.empty())
    {
        int cur = *valid.begin();
        int s = (delta[cur] > 0) ? 1 : -1;
        cout << cur + 1 << ' ' << s << '\n';
        a[cur] += s;
        a[cur + 1] += s;
        assert(a[cur] >= '0' && a[cur] <= '9');
        assert(a[0] != '0');
        delta[cur] -= s;
        for (int i = cur - 1; i <= cur + 1; i++)
        {
            if (i < 0 || i >= N - 1)
                continue;
            if (is_valid(i))
                valid.insert(i);
            else
                valid.erase(i);
        }
        lines++;
    }
    //assert(*max_element(RA(delta)) == 0);
    //assert(*min_element(RA(delta)) == 0);
    //assert(a == b);

    return 0;
}