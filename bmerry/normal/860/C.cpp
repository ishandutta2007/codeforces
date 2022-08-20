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
typedef vector<ll> vi;
typedef pair<ll, ll> pii;

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

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N;
    cin >> N;
    set<string> init[2], trg[2];
    int nex = 0;
    for (int i = 0; i < N; i++)
    {
        string s;
        int ex;
        cin >> s >> ex;
        nex += ex;
        init[!ex].insert(move(s));
    }
    for (int i = 0; i < nex; i++)
        trg[0].insert(to_string(i + 1));
    for (int i = nex; i < N; i++)
        trg[1].insert(to_string(i + 1));
    for (int i = 0; i < 2; i++)
    {
        vector<string> shared;
        for (const auto &s : init[i])
            if (trg[i].count(s))
                shared.push_back(s);
        for (const auto &s : shared)
        {
            init[i].erase(s);
            trg[i].erase(s);
        }
    }

    vector<pair<string, string>> ans;
    if (!init[0].empty() && init[0] == trg[1] && init[1] == trg[0])
    {
        ans.emplace_back(*init[0].begin(), "tmp");
        init[0].erase(*init[0].begin());
        init[0].insert("tmp");
    }

    set<string> both[2], one[2];
    for (int i = 0; i < 2; i++)
    {
        set_intersection(RA(trg[i]), RA(init[!i]), inserter(both[i], both[i].end()));
        set_difference(RA(trg[i]), RA(init[!i]), inserter(one[i], one[i].end()));
    }

    while (!init[0].empty() || !init[1].empty())
    {
        int side = one[0].empty() ? 1 : 0;
        string t = *one[side].begin();
        string s = (both[!side].empty()) ? *init[side].begin() : *both[!side].begin();
        ans.emplace_back(s, t);
        both[!side].erase(s);
        init[side].erase(s);
        trg[side].erase(t);
        one[side].erase(t);
        if (trg[!side].count(s))
            one[!side].insert(s);
    }

    cout << SZ(ans) << '\n';
    for (const auto &a : ans)
        cout << "move " << a.first << ' ' << a.second << '\n';
    return 0;
}