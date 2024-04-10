// WRONG: *any* two diplomas must satisfy cx <= 2cy

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

struct student
{
    int a;
    int id;

    bool operator<(const student &other) const
    {
        return a > other.a;
    };
};

static void solve()
{
    int N;
    cin >> N;
    vector<student> s(N);
    for (int i = 0; i < N; i++)
    {
        cin >> s[i].a;
        s[i].id = i;
    }
    sort(RA(s));
    vector<vector<pii>> gaps(1);
    gaps[0].resize(N + 1);
    for (int i = 0; i <= N; i++)
        gaps[0][i] = pii(s[max(0, i - 1)].a - (i == N ? 0 : s[i].a), i);
    int p = 1;
    while (p <= N)
    {
        gaps.emplace_back(N + 1);
        const auto &pg = gaps[SZ(gaps) - 2];
        for (int i = 0; i <= N - p; i++)
            gaps.back()[i] = max(pg[i], pg[i + p]);
        for (int i = N - p + 1; i <= N; i++)
            gaps.back()[i] = pg[i];
        p *= 2;
    }

    array<int, 3> ans = {-1, -1, -1};
    array<int, 3> ans_cut = {-1, -1, -1};
    for (int a = 1; a < N - 1; a++)
        for (int b = a + 1; b < N; b++)
        {
            int A = a;
            int B = b - a;
            if (A > 2 * B || B > 2 * A)
                continue;
            int minC = max(1, (max(A, B) + 1) / 2);
            int maxC = min(2 * A, 2 * B);
            int minc = b + minC;
            int maxc = min(N, b + maxC);
            if (minc > maxc)
                continue;
            int d = maxc - minc + 1;
            int r = 0;
            while ((2 << r) < d)
                r++;
            pii best = max(gaps[r][minc], gaps[r][maxc - (1 << r) + 1]);
            array<int, 3> score = {s[a - 1].a - s[a].a, s[b - 1].a - s[b].a, best.first};
            if (score > ans)
            {
                ans =score;
                ans_cut[0] = a;
                ans_cut[1] = b;
                ans_cut[2] = best.second;
            }
        }

    vi dip(N, -1);
    for (int i = 0; i < ans_cut[0]; i++)
        dip[s[i].id] = 1;
    for (int i = ans_cut[0]; i < ans_cut[1]; i++)
        dip[s[i].id] = 2;
    for (int i = ans_cut[1]; i < ans_cut[2]; i++)
        dip[s[i].id] = 3;

    for (int v : dip)
        cout << v << ' ';
    cout << '\n';
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    solve();

    return 0;
}