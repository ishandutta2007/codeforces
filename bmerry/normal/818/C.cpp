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

struct sofa
{
    int x1, y1, x2, y2;
    int idx;
    int hits = 0;
};

static void solve_x(vector<sofa> &sofas, int cL)
{
    sort(RA(sofas), [](const sofa &a, const sofa &b) { return a.x2 < b.x2; });
    auto alt = sofas;
    sort(RA(alt), [](const sofa &a, const sofa &b) { return a.x1 < b.x1; });

    int lft = 0;
    for (sofa &s : sofas)
    {
        while (lft < SZ(alt) && alt[lft].x1 < s.x2)
            lft++;
        int cur = lft - (s.x1 < s.x2);
        if (cur == cL)
            s.hits++;
    }
}

static void rotate(sofa &s)
{
    sofa tmp = s;
    s.x1 = tmp.y1;
    s.x2 = tmp.y2;
    s.y1 = -tmp.x2;
    s.y2 = -tmp.x1;
}

static void rotate(vector<sofa> &sofas)
{
    for (sofa &s : sofas)
        rotate(s);
}

static void solve()
{
    int N, C, R;
    cin >> N >> C >> R;
    vector<sofa> sofas(N);
    for (int i = 0; i < N; i++)
    {
        cin >> sofas[i].x1 >> sofas[i].y1 >> sofas[i].x2 >> sofas[i].y2;
        if (sofas[i].x1 > sofas[i].x2)
            swap(sofas[i].x1, sofas[i].x2);
        if (sofas[i].y1 > sofas[i].y2)
            swap(sofas[i].y1, sofas[i].y2);
        sofas[i].idx = i;
    }

    int cL, cR, cT, cB;
    cin >> cL >> cR >> cT >> cB;

    solve_x(sofas, cL);
    rotate(sofas);
    solve_x(sofas, cT);
    rotate(sofas);
    solve_x(sofas, cR);
    rotate(sofas);
    solve_x(sofas, cB);
    int found = 0;
    for (int i = 0; i < N; i++)
    {
        if (sofas[i].hits == 4)
        {
            cout << sofas[i].idx + 1 << '\n';
            found++;
        }
    }
    if (!found)
        cout << "-1\n";
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    solve();

    return 0;
}