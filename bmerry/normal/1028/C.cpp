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
}

/*** TEMPLATE CODE ENDS HERE */

typedef array<int, 2> pnt;
typedef array<pnt, 2> rect;

struct event
{
    int x;
    bool start;
    int idx;

    bool operator<(const event &other) const
    {
        return make_pair(x, !start) < make_pair(other.x, !other.start);
    }
};

static set<int> can_excl(const vector<rect> &rects, int a)
{
    int N = SZ(rects);
    unordered_set<int> dead;
    dead.reserve(N);
    for (int i = 0; i < N; i++)
        dead.insert(i);

    vector<event> evs;
    evs.reserve(2 * N);
    for (int i = 0; i < N; i++)
    {
        evs.push_back(event{rects[i][0][a], true, i});
        evs.push_back(event{rects[i][1][a], false, i});
    }
    sort(RA(evs));
    int depth = 0;
    set<int> ans;
    for (const auto &e : evs)
    {
        if (e.start)
        {
            dead.erase(e.idx);
            depth++;
            if (depth == N)
            {
                for (int i = 0; i < N; i++)
                    ans.insert(i);
                return ans;
            }
            else if (depth == N - 1)
            {
                ans.insert(*dead.begin());
            }
        }
        else
        {
            dead.insert(e.idx);
            depth--;
        }
    }
    return ans;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N;
    cin >> N;
    vector<rect> rects(N);
    for (int i = 0; i < N; i++)
        cin >> rects[i][0][0] >> rects[i][0][1] >> rects[i][1][0] >> rects[i][1][1];

    auto ex = can_excl(rects, 0);
    auto ey = can_excl(rects, 1);
    for (int idx : ex)
        if (ey.count(idx))
        {
            int x = INT_MIN;
            int y = INT_MIN;
            for (int i = 0; i < N; i++)
                if (i != idx)
                {
                    x = max(x, rects[i][0][0]);
                    y = max(y, rects[i][0][1]);
                }
            cout << x << ' ' << y << '\n';
            return 0;
        }
    cout << "IMPOSSIBLE\n";

    return 0;
}