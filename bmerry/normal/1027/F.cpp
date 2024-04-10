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

static bool can_solve(const vector<vi> &edges, int D)
{
    vector<bool> done(D + 1);
    vi st;
    for (int i = 0; i <= D; i++)
    {
        if (!done[i])
        {
            st.push_back(i);
            done[i] = true;
            int delta = 0;
            while (!st.empty())
            {
                int cur = st.back();
                st.pop_back();
                delta += SZ(edges[cur]) - 2;
                for (int v : edges[cur])
                {
                    if (v > D)
                        delta++;
                    else if (!done[v])
                    {
                        done[v] = true;
                        st.push_back(v);
                    }
                }
            }
            if (delta > 0)
                return false;
        }
    }
    return true;
}

static void solve()
{
    int N;
    cin >> N;
    vector<array<int, 2>> exams(N);
    vi days;
    map<int, int> remap;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> exams[i][j];
            days.push_back(exams[i][j]);
        }
    }
    sort(RA(days));
    days.resize(unique(RA(days)) - days.begin());

    int lo = -1;
    int M = SZ(days);
    vector<vi> edges(M);
    for (int i = 0; i < N; i++)
    {
        int a = lower_bound(RA(days), exams[i][0]) - days.begin();
        int b = lower_bound(RA(days), exams[i][1]) - days.begin();
        lo = max(lo, a - 1);
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    int hi = M - 1;
    if (!can_solve(edges, hi))
        cout << "-1\n";
    else
    {
        while (hi - lo > 1)
        {
            int mid = (lo + hi) / 2;
            if (can_solve(edges, mid))
                hi = mid;
            else
                lo = mid;
        }
        cout << days[hi] << '\n';
    }
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    solve();

    return 0;
}