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
}

/*** TEMPLATE CODE ENDS HERE */

static vector<int> query_chain(const vi &chain)
{
    int N = SZ(chain);
    vector<int> flip(N);
    if (N >= 2)
    {
        cout << "Q " << N / 2;
        for (int i = 1; i < N; i += 2)
            cout << ' ' << chain[i - 1] + 1 << ' ' << chain[i] + 1;
        cout << endl;
        string ans;
        cin >> ans;
        for (int i = 1; i < N; i += 2)
            if (ans[i / 2] == '0')
                flip[i] = true;
    }
    if (N >= 3)
    {
        cout << "Q " << (N - 1) / 2;
        for (int i = 2; i < N; i += 2)
            cout << ' ' << chain[i - 1] + 1 << ' ' << chain[i] + 1;
        cout << endl;
        string ans;
        cin >> ans;
        for (int i = 2; i < N; i += 2)
            if (ans[i / 2 - 1] == '0')
                flip[i] = true;
    }
    return flip;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int T;
    cin >> T;
    for (int cas = 0; cas < T; cas++)
    {
        int N;
        cin >> N;
        vector<int> all;
        all.reserve(N);
        for (int i = 0; i < N; i++)
            all.push_back(i);
        vector<int> flip = query_chain(all);

        vector<int> u;
        for (int i = 0; i < N; i++)
            if (i == 0 || flip[i])
                u.push_back(i);
        vi chains[2];
        for (int i = 0; i < SZ(u); i++)
            chains[i % 2].push_back(u[i]);

        vector<int> th(N);
        for (int i = 0; i < 2; i++)
        {
            vector<int> q = query_chain(chains[i]);
            for (int j = 1; j < SZ(q); j++)
                 th[chains[i][j]] = q[j];
        }

        vector<int> sets[3];
        int cur = 0;
        int prev = 1;
        for (int i = 0; i < N; i++)
        {
            if (flip[i])
            {
                if (th[i])
                {
                    int nxt = 3 - cur - prev;
                    prev = cur;
                    cur = nxt;
                }
                else
                    swap(cur, prev);
            }
            sets[cur].push_back(i);
        }

        cout << "A " << SZ(sets[0]) << ' ' << SZ(sets[1]) << ' ' << SZ(sets[2]) << endl;
        for (int i = 0; i < 3; i++)
        {
            for (int j : sets[i])
                cout << j + 1 << ' ';
            cout << endl;
        }
    }

    return 0;
}