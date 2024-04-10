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
typedef pair<int, int> pii;

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

struct person
{
    int p;
    int s;
    int idx;

    bool operator<(const person &other) const
    {
        return p > other.p;
    }
};

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N, P, S;
    cin >> N >> P >> S;
    vector<person> v(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i].p;
        v[i].idx = i;
    }
    for (int i = 0; i < N; i++)
        cin >> v[i].s;
    sort(RA(v));

    int psum, pssum, ssum;
    set<pii> psset, sset;
    set<pii>::iterator pscut, scut;

    int ans = -1;
    int ansm = -1;
    for (int pass = 0; pass < 2; pass++)
    {
        psum = 0;
        pssum = 0;
        ssum = 0;
        psset.clear();
        sset.clear();
        for (int i = 0; i < P; i++)
        {
            psum += v[i].p;
            psset.emplace(v[i].s - v[i].p, i);
        }
        pscut = psset.end();

        for (int i = P; i < N; i++)
            sset.emplace(v[i].s, i);
        scut = sset.end();
        for (int i = 0; i < S; i++)
        {
            --scut;
            ssum += scut->first;
        }
        int best = psum + pssum + ssum;
        int bestm = P;
        for (int m = P + 1; m <= P + S; m++)
        {
            if (best == ans)
                break;
            psum += v[m - 1].p;
            pii psadd(v[m - 1].s - v[m - 1].p, m - 1);
            psset.insert(psadd);
            if (pscut != psset.end() && *pscut < psadd)
                pssum += psadd.first;
            else
            {
                --pscut;
                pssum += pscut->first;
            }

            pii srm(v[m - 1].s, m - 1);
            if (*scut < srm)
                ssum -= srm.first;
            else
            {
                ssum -= scut->first;
                ++scut;
            }
            sset.erase(srm);

            int score = psum + pssum + ssum;
            if (score > best)
            {
                best = score;
                bestm = m;
            }
            best = max(best, score);
            if (best == ans)
                break;
        }
        ans = best;
        ansm = bestm;
    }

    set<int> pteam, steam;
    for (int i = 0; i < ansm; i++)
        pteam.insert(i);
    for (auto i = pscut; i != psset.end(); i++)
    {
        pteam.erase(i->second);
        steam.insert(i->second);
    }
    for (auto i = scut; i != sset.end(); i++)
        steam.insert(i->second);
    cout << ans << '\n';
    bool first = true;
    for (int i : pteam)
    {
        if (!first)
            cout << ' ';
        first = false;
        cout << v[i].idx + 1;
    }
    cout << '\n';
    first = true;
    for (int i : steam)
    {
        if (!first)
            cout << ' ';
        first = false;
        cout << v[i].idx + 1;
    }
    cout << '\n';
    return 0;
}