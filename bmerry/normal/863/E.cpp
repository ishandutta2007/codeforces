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

struct event
{
    int t;
    int id;
    int d;

    bool operator<(const event &other) const
    {
        return t < other.t;
    }
};

static void solve()
{
    int N;
    cin >> N;
    list<int> active;
    vector<list<int>::iterator> pos(N, active.end());
    vector<event> events;
    events.reserve(2 * N);
    for (int i = 0; i < N; i++)
    {
        int L, R;
        cin >> L >> R;
        R++;
        events.push_back(event{L, i, 1});
        events.push_back(event{R, i, -1});
    }
    sort(RA(events));

    int p = 0;
    int lvl = 0;
    vector<bool> crit(N);
    while (p < SZ(events))
    {
        int q = p;
        while (q < SZ(events) && events[q].t == events[p].t)
        {
            lvl += events[q].d;
            if (events[q].d == 1)
            {
                active.insert(active.begin(), events[q].id);
                pos[events[q].id] = active.begin();
            }
            else
                active.erase(pos[events[q].id]);
            q++;
        }
        if (lvl == 1)
            crit[*active.begin()] = true;
        p = q;
    }

    int r = 0;
    while (r < N && crit[r])
        r++;
    if (r == N)
        r = -2;
    cout << r + 1 << '\n';
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    solve();

    return 0;
}