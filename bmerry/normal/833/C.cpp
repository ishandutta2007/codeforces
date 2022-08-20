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

static vector<ll> adjustments[20];

static void adjust_r(vector<ll> &out, int d, int rem, ll key)
{
    if (rem == 0)
        out.push_back(key);
    else if (d >= 0)
    {
        for (ll i = 0; i <= rem; i++)
            adjust_r(out, d - 1, rem - i, key + (i << (5 * d)));
    }
}

static array<int, 10> add(const string &R, int prefix, int nxt)
{
    array<int, 10> f{};
    for (int i = 0; i < prefix; i++)
        f[R[i] - '0']++;
    f[nxt]++;
    return f;
}

static vector<ll> compute(const array<int, 10> &f, int R)
{
    ll key = 0;
    for (ll i = 0; i < 10; i++)
        key |= (ll(f[i]) << (5 * i));
    int prefix = accumulate(RA(f), 0);
    const auto &adj = adjustments[R - prefix];
    vector<ll> out = adj;
    for (ll &v : out)
        v += key;
    return out;
}

static bool dominates(const array<int, 10> &a, const array<int, 10> &b)
{
    for (int i = 0; i < 10; i++)
        if (a[i] < b[i])
            return false;
    return true;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    ll Li, Ri;
    cin >> Li >> Ri;
    string L = to_string(Li - 1);
    string R = to_string(Ri + 1);
    while (SZ(L) < SZ(R))
        L = "0" + L;

    for (int i = 0; i < SZ(L); i++)
    {
        adjust_r(adjustments[i], 9, i, 0LL);
        adjustments[i].shrink_to_fit();
    }

    int len = SZ(L);
    int p = 0;
    while (L[p] == R[p])
        p++;

    vector<array<int, 10>> sets;
    for (int i = len - 1; i > p; i--)
    {
        for (int j = L[i] - '0' + 1; j < 10; j++)
            sets.push_back(add(L, i, j));
        for (int j = 0; j < R[i] - '0'; j++)
            sets.push_back(add(R, i, j));
    }
    for (int i = L[p] + 1; i < R[p]; i++)
        sets.push_back(add(L, p, i - '0'));

    sort(RA(sets));
    vector<array<int, 10>> sets2;
    for (const auto &set : sets)
    {
        bool use = true;
        for (const auto &dom : sets2)
        {
            if (dominates(set, dom))
                use = false;
        }
        if (use)
            sets2.push_back(set);
    }
    reverse(RA(sets2));
    vector<ll> found;
    for (const auto &set : sets2)
    {
        vector<ll> found2;
        auto c = compute(set, SZ(R));
        found2.reserve(SZ(c) + SZ(found));
        set_union(RA(c), RA(found), back_inserter(found2));
        found = move(found2);
    }

    cout << found.size() << '\n';
    return 0;
}