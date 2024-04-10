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

struct node
{
    int dp[5][5];

    node()
    {
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i <= 4; i++)
            dp[i][i] = 0;
    }
};

static node join(const node &a, const node &b)
{
    node out;
    for (int i = 0; i <= 4; i++)
        for (int j = i; j <= 4; j++)
        {
            int best = INT_MAX;
            for (int k = i; k <= j; k++)
                if (a.dp[i][k] != -1 && b.dp[k][j] != -1)
                    best = min(best, a.dp[i][k] + b.dp[k][j]);
            if (best != INT_MAX)
                out.dp[i][j] = best;
            else
                out.dp[i][j] = -1;
        }
    return out;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N, Q;
    string s;
    cin >> N >> Q >> s;
    int ofs = 1;
    while (ofs < N)
        ofs *= 2;
    vector<node> nodes(2 * ofs);
    for (int i = 0; i < N; i++)
    {
        node &cur = nodes[i + ofs];
        switch (s[i])
        {
        case '2':
            cur.dp[0][1] = 0;
            cur.dp[0][0] = 1;
            break;
        case '0':
            cur.dp[1][2] = 0;
            cur.dp[1][1] = 1;
            break;
        case '1':
            cur.dp[2][3] = 0;
            cur.dp[2][2] = 1;
            break;
        case '6':
            cur.dp[3][3] = 1;
            cur.dp[4][4] = 1;
            break;
        case '7':
            cur.dp[3][4] = 0;
            cur.dp[3][3] = 1;
            break;
        }
    }

    for (int i = ofs - 1; i > 0; i--)
        nodes[i] = join(nodes[2 * i], nodes[2 * i + 1]);

    for (int i = 0; i < Q; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        a += ofs;
        b += ofs;
        node lft, rgt;
        while (a < b)
        {
            if (a & 1)
                lft = join(lft, nodes[a++]);
            if (b & 1)
                rgt = join(nodes[--b], rgt);
            a >>= 1;
            b >>= 1;
        }
        node ans = join(lft, rgt);
        cout << ans.dp[0][4] << '\n';
    }

    return 0;
}