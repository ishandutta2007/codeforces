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

static set<string> elems{
"h",
"he",
"li",
"be",
"b",
"c",
"n",
"o",
"f",
"ne",
"na",
"mg",
"al",
"si",
"p",
"s",
"cl",
"ar",
"k",
"ca",
"sc",
"ti",
"v",
"cr",
"mn",
"fe",
"co",
"ni",
"cu",
"zn",
"ga",
"ge",
"as",
"se",
"br",
"kr",
"rb",
"sr",
"y",
"zr",
"nb",
"mo",
"tc",
"ru",
"rh",
"pd",
"ag",
"cd",
"in",
"sn",
"sb",
"te",
"i",
"xe",
"cs",
"ba",
"la",
"ce",
"pr",
"nd",
"pm",
"sm",
"eu",
"gd",
"tb",
"dy",
"ho",
"er",
"tm",
"yb",
"lu",
"hf",
"ta",
"w",
"re",
"os",
"ir",
"pt",
"au",
"hg",
"tl",
"pb",
"bi",
"po",
"at",
"rn",
"fr",
"ra",
"ac",
"th",
"pa",
"u",
"np",
"pu",
"am",
"cm",
"bk",
"cf",
"es",
"fm",
"md",
"no",
"lr",
"rf",
"db",
"sg",
"bh",
"hs",
"mt",
"ds",
"rg",
"cn",
"nh",
"fl",
"mc",
"lv",
"ts",
"og",
};

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    string s;
    cin >> s;
    for (char &c : s)
        c = tolower(c);
    int L = SZ(s);
    vector<bool> dp(L + 1);
    dp[0] = true;
    for (int i = 1; i <= L; i++)
    {
        for (int j = 1; j <= min(i, 2); j++)
            if (dp[i - j] && elems.count(s.substr(i - j, j)))
                dp[i] = true;
    }
    cout << (dp[L] ? "YES\n" : "NO\n");

    return 0;
}