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

int main(int argc, const char **argv)
{
    constexpr ll FULL = 100000;
    redirect(argc, argv);
    ll N, R;
    cin >> N >> R;
    vector<ll> dtimes;
    vector<ll> l(N), t(N);
    for (ll i = 0; i < N; i++)
        cin >> l[i];
    for (ll i = 0; i < N; i++)
    {
        cin >> t[i];
        if (t[i] < l[i])
        {
            cout << "-1\n";
            return 0;
        }
    }
    ll used = 0;
    ll rem = 0;
    ll T = 0;
    for (ll i = 0; i < N; i++)
    {
        ll L = l[i];
        ll cfast = min(rem, L);
        ll use = 0;
        ll start = T + rem;
        ll over = rem - cfast;
        if (2 * L - cfast > t[i])
        {
            ll gap = 2 * L - cfast - t[i];
            use = (gap + R - 1) / R;
            over = use * R - gap;
            start = T + rem + 2 * (L - rem - gap);
            cfast += gap;
        }
        ll dt = start;
        for (ll i = 0; i < use && SZ(dtimes) < FULL; i++)
        {
            dtimes.push_back(dt);
            dt += R;
        }
        used += use;
        T += 2 * L - cfast;
        rem = over;
    }
    cout << used << '\n';
    if (used <= FULL)
    {
        bool first = true;
        for (ll v : dtimes)
        {
            if (!first)
                cout << ' ';
            first = false;
            cout << v;
        }
        cout << '\n';
    }

    return 0;
}