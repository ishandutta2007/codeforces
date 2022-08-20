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
    cin.exceptions(ios::failbit);
}

/*** TEMPLATE CODE ENDS HERE */

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int T;
    cin >> T;
    for (int cas = 0; cas < T; cas++)
    {
        string s;
        cin >> s;
        if (SZ(s) == 1)
        {
            cout << "YES\nabcdefghijklmnopqrstuvwxyz\n";
            continue;
        }
        vector<set<int>> edges(26);
        for (int i = 1; i < SZ(s); i++)
        {
            int a = s[i - 1] - 'a';
            int b = s[i] - 'a';
            edges[a].insert(b);
            edges[b].insert(a);
        }
        int x = -1;
        string ans;
        vector<bool> used(26);
        for (int i = 0; i < 26; i++)
        {
            int d = edges[i].size();
            if (d > 2)
            {
                cout << "NO\n";
                goto skip;
            }
            if (d == 1)
                x = i;
        }
        if (x == -1)
        {
            cout << "NO\n";
            goto skip;
        }

        while (true)
        {
            ans += 'a' + x;
            used[x] = true;
            if (edges[x].empty())
                break;
            int y = *edges[x].begin();
            edges[x].erase(y);
            edges[y].erase(x);
            x = y;
        }
        for (int i = 0; i < 26; i++)
            if (!used[i])
                ans += 'a' + i;
        cout << "YES\n" << ans << '\n';
skip:;
    }

    return 0;
}