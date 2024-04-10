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

// m must be positive
template<typename T>
static T mod(T a, T m)
{
    a %= m;
    if (a < 0)
        a += m;
    return a;
}

// a must be relatively prime to m
template<typename T>
static T inverse(T a, T m)
{
    a = mod(a, m);
    if (a <= 1)
        return a;
    return mod((1 - inverse(m, a) * m) / a, m);
}

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

static ll g;
static ll invCg;
static ll Rg, Cg;

static ll find3(ll r, ll c, ll R, ll C)
{
    R *= 2;
    C *= 2;
    if ((r - c) % g != 0)
        return LLONG_MAX;
    ll s = (r - c) / g;
    ll gamma = mod(s * invCg, Rg);
    ll t = c + gamma * C;
    //assert(t >= r && t >= c);
    //assert((t - r) % R == 0);
    //assert((t - c) % C == 0);
    return t;
}

static ll find2(ll r, ll c, ll R, ll C)
{
    return min(find3(r, c, R, C), find3(r, 2 * C - c, R, C));
}

static ll find1(ll r, ll c, ll R, ll C)
{
    return min(find2(r, c, R, C), find2(2 * R - r, c, R, C));
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    ll R, C, K;
    cin >> R >> C >> K;

    R *= 2;
    C *= 2;
    g = gcd(R, C);
    Rg = R / g;
    Cg = C / g;
    invCg = inverse(Cg, Rg);
    R /= 2;
    C /= 2;

    for (ll i = 0; i < K; i++)
    {
        ll r, c;
        cin >> r >> c;
        ll cut = find1(r, c, R, C);
        if (cut == LLONG_MAX)
            cut = -1;
        cout << cut << '\n';
    }

    return 0;
}