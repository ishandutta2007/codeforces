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

struct gadget
{
    ll cost;
    ll id;

    bool operator<(const gadget &other) const
    {
        return cost < other.cost;
    }
};

static void solve()
{
    vector<gadget> gadgets[2];
    int N, M, K;
    ll S;
    cin >> N >> M >> K >> S;
    vll exchange[2];
    exchange[0].resize(N);
    exchange[1].resize(N);
    for (int i = 0; i < N; i++)
        cin >> exchange[0][i];
    for (int i = 0; i < N; i++)
        cin >> exchange[1][i];
    for (int i = 0; i < M; i++)
    {
        int t, c;
        cin >> t >> c;
        t--;
        gadgets[t].push_back(gadget{c, i});
    }

    vll psum[2];
    vi bday[2];
    for (int i = 0; i < 2; i++)
    {
        int G = SZ(gadgets[i]);
        sort(RA(gadgets[i]));
        psum[i].resize(G + 1);
        for (int j = 0; j < G; j++)
            psum[i][j + 1] = psum[i][j] + gadgets[i][j].cost;

        bday[i].resize(N);
        bday[i][0] = 0;
        ll best = exchange[i][0];
        for (int j = 1; j < N; j++)
        {
            if (exchange[i][j] < best)
            {
                bday[i][j] = j;
                best = exchange[i][j];
            }
            else
            {
                bday[i][j] = bday[i][j - 1];
                exchange[i][j] = best;
            }
        }
    }

    int bestK = N;
    int besti = -1;
    for (int i = 0; i <= SZ(gadgets[0]); i++)
    {
        if (i > K || K - i > SZ(gadgets[1]))
            continue;
        int lo = -1;
        int hi = N;
        while (hi - lo > 1)
        {
            int mid = (lo + hi) / 2;
            ll cost = exchange[0][mid] * psum[0][i] + exchange[1][mid] * psum[1][K - i];
            if (cost <= S)
                hi = mid;
            else
                lo = mid;
        }
        if (hi < bestK)
        {
            bestK = hi;
            besti = i;
        }
    }

    if (bestK == N)
        cout << "-1\n";
    else
    {
        cout << bestK + 1 << '\n';
        int day[2] = {bday[0][bestK], bday[1][bestK]};
        for (int i = 0; i < besti; i++)
            cout << gadgets[0][i].id + 1 << ' ' << day[0] + 1 << '\n';
        for (int i = 0; i < K - besti; i++)
            cout << gadgets[1][i].id + 1 << ' ' << day[1] + 1 << '\n';
    }
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    solve();

    return 0;
}