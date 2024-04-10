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

static const int MAXK = 16;

struct word
{
    string prefix, suffix;
    vector<vector<bool>> have;

    word()
    {
        have.resize(MAXK + 1);
        for (int i = 0; i <= MAXK; i++)
            have[i].resize(1 << i);
        have[0][0] = true;
    }
};

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N;
    cin >> N;
    vector<word> words;
    words.reserve(N);
    for (int i = 0; i < N; i++)
    {
        string w;
        cin >> w;
        word cur;
        cur.prefix = (SZ(w) < MAXK) ? w : w.substr(0, MAXK);
        cur.suffix = (SZ(w) < MAXK) ? w : w.substr(SZ(w) - MAXK);
        for (int i = 1; i <= min(SZ(w), ll(MAXK)); i++)
        {
            int v = 0;
            for (int j = 0; j < i - 1; j++)
                v = v * 2 + (w[j] - '0');
            for (int j = i - 1; j < SZ(w); j++)
            {
                v = v * 2 + (w[j] - '0');
                v &= (1 << i) - 1;
                cur.have[i][v] = true;
            }
        }
        words.push_back(move(cur));
    }

    int M;
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        word nxt;
        const word &A = words[a];
        const word &B = words[b];
        nxt.prefix = (A.prefix + B.prefix).substr(0, MAXK);
        nxt.suffix = (A.suffix + B.suffix);
        if (SZ(nxt.suffix) > MAXK)
            nxt.suffix = nxt.suffix.substr(SZ(nxt.suffix) - MAXK);
        string mid = A.suffix + B.prefix;
        for (int i = 1; i <= MAXK; i++)
        {
            for (int j = 0; j < (1 << i); j++)
                nxt.have[i][j] = A.have[i][j] || B.have[i][j];
            if (SZ(mid) >= i)
            {
                int v = 0;
                for (int j = 0; j < i - 1; j++)
                    v = v * 2 + (mid[j] - '0');
                for (int j = i - 1; j < SZ(mid); j++)
                {
                    v = v * 2 + (mid[j] - '0');
                    v &= (1 << i) - 1;
                    nxt.have[i][v] = true;
                }
            }
        }
        int k = 0;
        while (k <= MAXK && !count(RA(nxt.have[k]), false))
            k++;
        cout << k - 1 << '\n';
        words.push_back(move(nxt));
    }

    return 0;
}