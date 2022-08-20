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

struct event
{
    int x;
    int id;
    bool end;

    bool operator<(const event &other) const
    {
        return x < other.x;
    }
};

static int dfs(int cur, const vector<vi> &edges, vector<bool> &seen)
{
    seen[cur] = true;
    int sz = 1;
    for (int y : edges[cur])
        if (!seen[y])
            sz += dfs(y, edges, seen);
    return sz;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N;
    cin >> N;
    vector<vi> edges(N);
    vector<event> events;
    events.reserve(2 * N);
    for (int i = 0; i < N; i++)
    {
        int x1, x2;
        cin >> x1 >> x2;
        events.push_back(event{x1, i, false});
        events.push_back(event{x2, i, true});
    }
    sort(RA(events));
    vector<int> st;
    int E = 0;
    for (const event &e : events)
    {
        if (!e.end)
            st.push_back(e.id);
        else
        {
            int pos = SZ(st) - 1;
            while (st[pos] != e.id)
            {
                int c = st[pos];
                edges[c].push_back(e.id);
                edges[e.id].push_back(c);
                E++;
                if (E >= N)
                {
                    cout << "NO\n";
                    return 0;
                }
                pos--;
            }
            st.erase(st.begin() + pos);
        }
    }

    vector<bool> seen(N);
    bool tree = (E == N - 1) && dfs(0, edges, seen) == N;
    cout << (tree ? "YES\n" : "NO\n");

    return 0;
}