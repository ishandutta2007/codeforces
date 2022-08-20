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

#define RA(x) std::begin(x), std::end(x)
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

struct state
{
    int x = -1;
    int i = -1;
    int score = INT_MAX / 2;
    int start = -1, pend = -1;
    bool lr = false;
};

static int dist(int a, int b, int N)
{
    int d = abs(b - a);
    return min(d, N - d);
}

static int cwdist(int a, int b, int N)
{
    int d = b - a;
    if (d < 0)
        d += N;
    return d;
}

static void solve()
{
    int N, S;
    cin >> N >> S;
    S--;
    map<int, vi> pos;
    vi a(N);
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
        pos[a[i]].push_back(i);
    }

    vector<state> prev{state{S, -1, 0, -1, -1}};
    vector<vector<state>> history;
    for (const auto &entry : pos)
    {
        const vi &ap = entry.second;
        int M = SZ(ap);
        vector<state> starts(M);
        for (int i = 0; i < M; i++)
        {
            state &start = starts[i];
            start.x = ap[i];
            start.i = i;
            start.start = i;
            for (const state &s : prev)
            {
                int c = s.score + dist(s.x, ap[i], N);
                if (c < start.score)
                {
                    start.score = c;
                    start.pend = s.i;
                }
            }
        }

        vector<state> cur(M);
        for (int i = 0; i < M; i++)
        {
            cur[i].x = ap[i];
            cur[i].i = i;
            if (M == 1)
            {
                cur[i].score = starts[i].score;
                cur[i].start = 0;
            }
            else
            {
                int turn1 = (i + 1) % M;
                int clr = starts[turn1].score + cwdist(ap[turn1], ap[i], N);
                int turn2 = (i + M - 1) % M;
                int crl = starts[turn2].score + cwdist(ap[i], ap[turn2], N);
                if (clr < crl)
                {
                    cur[i].score = clr;
                    cur[i].start = turn1;
                    cur[i].lr = true;
                }
                else
                {
                    cur[i].score = crl;
                    cur[i].start = turn2;
                }
            }
            cur[i].pend = starts[cur[i].start].pend;
        }

        history.push_back(move(prev));
        prev = move(cur);
    }

    int ans = INT_MAX;
    int end = -1;
    for (int i = 0; i < SZ(prev); i++)
    {
        if (prev[i].score < ans)
        {
            ans = prev[i].score;
            end = i;
        }
    }
    cout << ans << '\n';

    vi steps;
    while (!pos.empty())
    {
        const vi &ap = pos.rbegin()->second;
        state track = prev[end];
        int M = SZ(prev);
        int p = end;
        if (M > 1)
        {
            int dir = track.lr ? 1 : -1;
            while (p != track.start)
            {
                steps.push_back(ap[p]);
                p = (p - dir + M) % M;
            }
        }
        steps.push_back(ap[p]);
        pos.erase(--pos.end());
        prev = move(history.back());
        history.pop_back();
        end = track.pend;
    }
    steps.push_back(S);
    reverse(RA(steps));
    for (int i = 1; i < SZ(steps); i++)
    {
        int d1 = cwdist(steps[i - 1], steps[i], N);
        int d2 = cwdist(steps[i], steps[i - 1], N);
        if (d1 <= d2)
            cout << "+" << d1 << '\n';
        else
            cout << "-" << d2 << '\n';
    }
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    solve();

    return 0;
}