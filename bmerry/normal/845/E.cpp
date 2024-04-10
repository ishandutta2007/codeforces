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

struct position
{
    int r, c;
};

struct event
{
    int xy;
    int id;
    int delta;

    bool operator<(const event &other) const
    {
        if (xy != other.xy)
            return xy < other.xy;
        else
            return delta > other.delta;
    }
};

static void solve()
{
    int R, C, K;
    cin >> R >> C >> K;
    vector<position> pos(K);
    for (int i = 0; i < K; i++)
    {
        cin >> pos[i].r >> pos[i].c;
        pos[i].r--;
        pos[i].c--;
    }

    int lo = -1;
    int hi = max(R, C);
    while (hi - lo > 1)
    {
        int mid = (hi + lo) / 2;
        vector<event> er, ec;
        for (int i = 0; i < K; i++)
        {
            er.push_back(event{max(0, pos[i].r - mid), i, 1});
            er.push_back(event{min(R, pos[i].r + mid + 1), i, -1});
            ec.push_back(event{max(0, pos[i].c - mid), i, 1});
            ec.push_back(event{min(C, pos[i].c + mid + 1), i, -1});
        }
        er.push_back(event{0, -1, 0});
        er.push_back(event{R, -1, 0});
        ec.push_back(event{0, -1, 0});
        ec.push_back(event{C, -1, 0});
        sort(RA(er));
        sort(RA(ec));
        vector<bool> active(K);
        int pr = 0;
        bool gaps = false;
        int minr = INT_MAX, maxr = -1, minc = INT_MAX, maxc = -1;
        while (pr < SZ(er))
        {
            int curr = er[pr].xy;
            if (gaps)
            {
                minr = min(minr, curr - 1);
                maxr = max(maxr, curr - 1);
            }
            int qr = pr;
            while (qr < SZ(er) && er[qr].xy == curr)
            {
                if (er[qr].id != -1)
                    active[er[qr].id] = er[qr].delta == 1;
                qr++;
            }
            pr = qr;
            if (curr == R)
                break;

            int pc = 0;
            int lvl = 0;
            gaps = false;
            while (pc < SZ(ec))
            {
                int curc = ec[pc].xy;
                if (curc > 0 && lvl == 0)
                {
                    gaps = true;
                    minc = min(minc, curc - 1);
                    maxc = max(maxc, curc - 1);
                }
                int qc = pc;
                while (qc < SZ(ec) && ec[qc].xy == curc)
                {
                    if (ec[qc].id != -1 && active[ec[qc].id])
                        lvl += ec[qc].delta;
                    qc++;
                }
                if (lvl == 0 && curc < C)
                {
                    gaps = true;
                    minc = min(minc, curc);
                    maxc = max(maxc, curc);
                }
                pc = qc;
            }

            if (gaps)
            {
                maxr = max(maxr, curr);
                minr = min(minr, curr);
            }
        }
        if (maxr == -1
            || max(maxr - minr, maxc - minc) <= 2 * mid)
            hi = mid;
        else
            lo = mid;
    }
    cout << hi << '\n';
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    solve();

    return 0;
}