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

struct edge
{
    int trg;
    ll label;
};

#define MOD 1000000007

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N, M;
    cin >> N >> M;
    vector<vector<edge>> edges(N);
    for (int i = 0; i < M; i++)
    {
        int x, y;
        ll t;
        cin >> x >> y >> t;
        x--;
        y--;
        edges[x].push_back(edge{y, t});
        edges[y].push_back(edge{x, t});
    }

    vector<bool> seen(N);
    vector<ll> direct(N, -1);
    ll ans = 0;
    for (int root = 0; root < N; root++)
    {
        if (!seen[root])
        {
            queue<int> q;
            q.push(root);
            seen[root] = true;
            direct[root] = 0;
            vector<int> comp;
            while (!q.empty())
            {
                int cur = q.front();
                q.pop();
                comp.push_back(cur);
                for (const auto &e : edges[cur])
                {
                    if (!seen[e.trg])
                    {
                        seen[e.trg] = true;
                        direct[e.trg] = direct[cur] ^ e.label;
                        q.push(e.trg);
                    }
                }
            }

            vector<ll> cover;
            for (int i : comp)
                for (const edge &e : edges[i])
                    if (e.trg > i)
                        cover.push_back(direct[i] ^ direct[e.trg] ^ e.label);

            int basis = 0;
            for (ll bit = 1LL << 62; bit > 0; bit >>= 1)
            {
                int i = basis;
                while (i < SZ(cover) && !(cover[i] & bit))
                    i++;
                if (i < SZ(cover))
                {
                    swap(cover[basis], cover[i]);
                    for (int j = i + 1; j < SZ(cover); j++)
                        if (cover[j] & bit)
                            cover[j] ^= cover[basis];
                    basis++;
                }
            }
            ll any = 0;
            for (int i = 0; i < SZ(cover); i++)
                any |= cover[i];

            ll S = comp.size();
            ll opts = S * (S - 1) / 2 % MOD;
            ll half = (1LL << (basis - 1)) % MOD;
            ll full = (1LL << basis) % MOD;
            for (ll bit = 1LL << 62; bit > 0; bit >>= 1)
            {
                ll bmod = bit % MOD;
                if (any & bit)
                    ans = (ans + opts * half % MOD * bmod % MOD) % MOD;
                else
                {
                    ll hi = 0;
                    for (int i : comp)
                        hi += (direct[i] & bit) ? 1 : 0;
                    ll lo = S - hi;
                    ans = (ans + lo * hi % MOD * full % MOD * bmod % MOD) % MOD;
                }
            }
        }
    }
    cout << ans << '\n';

    return 0;
}