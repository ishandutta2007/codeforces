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
    int x;
    bool start;
    int len;
    int id;

    bool operator<(const event &other) const
    {
        if (x != other.x)
            return x < other.x;
        else if (start != other.start)
            return !start;
        else if (len != other.len)
            return start ? len > other.len : len < other.len;
        else
            return start ? id < other.id : id > other.id;
    }
};

static void solve()
{
    int N;
    cin >> N;
    vector<event> events;
    for (int i = 0; i < N; i++)
    {
        int L, R;
        cin >> L >> R;
        R++;
        events.push_back(event{L, true, R - L, i});
        events.push_back(event{R, false, R - L, i});
    }
    sort(RA(events));
    queue<int> q;
    for (const event &e : events)
    {
        if (e.start)
            q.push(e.id);
        else
        {
            if (q.front() != e.id)
            {
                cout << e.id + 1 << ' ' << q.front() + 1 << '\n';
                return;
            }
            q.pop();
        }
    }
    cout << "-1 -1\n";
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    solve();

    return 0;
}