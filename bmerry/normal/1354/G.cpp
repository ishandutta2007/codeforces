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

enum class Cmp
{
    FIRST,
    SECOND,
    EQUAL
};

template<typename Itx, typename Ity>
static Cmp compare(Itx xfirst, Itx xlast, Ity yfirst, Ity ylast)
{
    cout << "? " << distance(xfirst, xlast) << ' ' << distance(yfirst, ylast) << '\n';
    for (auto x = xfirst; x != xlast; ++x)
        cout << *x + 1 << ' ';
    cout << '\n';
    for (auto y = yfirst; y != ylast; ++y)
        cout << *y + 1 << ' ';
    cout << endl;
    string ans;
    cin >> ans;
    if (ans[0] == 'F')
        return Cmp::FIRST;
    else if (ans[0] == 'S')
        return Cmp::SECOND;
    else if (ans[0] == 'E')
        return Cmp::EQUAL;
    else
        exit(0);
}

static Cmp compare(const vi &x, const vi &y)
{
    return compare(RA(x), RA(y));
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int T;
    cin >> T;
    for (int cas = 0; cas < T; cas++)
    {
        int N, K;
        cin >> N >> K;
        vi perm(N);
        for (int i = 0; i < N; i++)
            perm[i] = i;
        mt19937 engine(time(NULL));
        shuffle(RA(perm), engine);
        int H = perm[0];
        for (int i = 1; i < min(26, N); i++)
        {
            if (compare({H}, {perm[i]}) == Cmp::SECOND)
                H = perm[i];
        }
        if (H != 0 && compare({0}, {H}) == Cmp::SECOND)
        {
            cout << "! 1\n" << flush;
            continue;
        }
        vi stones{0};
        int a = 1;
        int b;
        vi rhs;
        while (a < N)
        {
            b = min(N, a + int(SZ(stones)));
            rhs.clear();
            for (int i = a; i < b; i++)
                rhs.push_back(i);
            auto result = compare(stones.begin(), stones.begin() + SZ(rhs), RA(rhs));
            if (result == Cmp::EQUAL)
                stones.insert(stones.end(), RA(rhs));
            else
                break;
            a = b;
        }
        int lo = 0;
        int hi = b - a;
        while (hi - lo > 1)
        {
            int mid = (lo + hi) / 2;
            auto result = compare(stones.begin(), stones.begin() + mid,
                                  rhs.begin(), rhs.begin() + mid);
            if (result == Cmp::EQUAL)
                lo = mid;
            else
                hi = mid;
        }
        cout << "! " << rhs[lo] + 1 << endl;
    }

    return 0;
}