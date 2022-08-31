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

static vi random_poly(mt19937 &engine, int deg)
{
    vi out;
    uniform_int_distribution<int> dist(0, 1);
    for (int i = 0; i < deg; i++)
        out.push_back(dist(engine) * 2 - 1);
    out.push_back(1);
    return out;
}

static vi mod(const vi &a, const vi &b)
{
    vi out = a;
    while (SZ(out) >= SZ(b))
    {
        int scale = out.back();
        for (int &v : out)
            v *= b.back();
        int up = SZ(out) - SZ(b);
        for (int i = 0; i < SZ(b); i++)
            out[i + up] -= scale * b[i];
        while (!out.empty() && out.back() == 0)
            out.pop_back();
    }
    return out;
}

static bool good(vi a, vi b)
{
    int N = SZ(a) - 1;
    for (int i = 0; i < N; i++)
    {
        vi m = mod(a, b);
        if (SZ(m) != N - 1 - i)
            return false;
        if (!m.empty() && (*max_element(RA(m)) > 1000 || *min_element(RA(m)) < -1000))
            return false;
        a = move(b);
        b = move(m);
    }
    return true;
}

static void write_poly(const vi &a)
{
    cout << SZ(a) - 1 << '\n';
    for (int c : a)
    {
        c = (c % 3 + 3) % 3;
        if (c == 2)
            c -= 3;
        cout << c << ' ';
    }
    cout << '\n';
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N;
    cin >> N;
    vi a{1};
    vi b{};
    for (int i = 0; i < N; i++)
    {
        vi c(i + 2);
        for (int j = 0; j < SZ(b); j++)
            c[j] += b[j];
        for (int j = 0; j < SZ(a); j++)
            c[j + 1] += a[j];
        for (int &v : c)
            v %= 3;
        b = move(a);
        a = move(c);
    }
    write_poly(a);
    write_poly(b);

    return 0;
}