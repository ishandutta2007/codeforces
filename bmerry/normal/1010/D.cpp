//#pragma GCC optimize("O3")
//#pragma GCC target("arch=native,tune=native")
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

struct node
{
    char op;
    int value = -1;
    int ch[2] = {-1, -1};
    bool dp = false;
};

static vector<node> nodes;

static int combine(char op, int x, int y)
{
    switch (op)
    {
    case 'A':
        return x && y;
    case 'O':
        return x || y;
    case 'X':
        return x ^ y;
    }
    return -1;
}

static int calc(int idx)
{
    node &n = nodes[idx];
    switch (n.op)
    {
    case 'A':
    case 'O':
    case 'X':
        n.value = combine(n.op, calc(n.ch[0]), calc(n.ch[1]));
        break;
    case 'N':
        n.value = !calc(n.ch[0]);
        break;
    }
    return n.value;
}

static void dp(int idx)
{
    node &n = nodes[idx];
    n.dp = true;
    int x, y, z = n.value;
    switch (n.op)
    {
    case 'A':
    case 'O':
    case 'X':
        x = nodes[n.ch[0]].value;
        y = nodes[n.ch[1]].value;
        if (combine(n.op, !x, y) != z)
            dp(n.ch[0]);
        if (combine(n.op, x, !y) != z)
            dp(n.ch[1]);
        break;
    case 'N':
        dp(n.ch[0]);
        break;
    }
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N;
    cin >> N;
    nodes.resize(N);
    for (int i = 0; i < N; i++)
    {
        char t[8];
        cin >> t;
        node &n = nodes[i];
        n.op = t[0];
        switch (n.op)
        {
        case 'A':
        case 'O':
        case 'X':
            cin >> n.ch[0] >> n.ch[1];
            n.ch[0]--;
            n.ch[1]--;
            break;
        case 'N':
            cin >> n.ch[0];
            n.ch[0]--;
            break;
        case 'I':
            cin >> n.value;
            break;
        }
    }

    calc(0);
    dp(0);
    for (int i = 0; i < N; i++)
        if (nodes[i].op == 'I')
        {
            int out = nodes[0].value;
            if (nodes[i].dp)
                out = !out;
            cout << out;
        }
    cout << '\n';

    return 0;
}