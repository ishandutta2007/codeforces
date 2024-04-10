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

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N;
    cin >> N;
    array<int, 26> follow;
    for (int i = 0; i < 26; i++)
        follow[i] = -1;
    int use = 0;
    for (int i = 0; i < N; i++)
    {
        string word;
        cin >> word;
        for (char c : word)
            use |= 1 << (c - 'a');
        for (int j = 0; j < SZ(word) - 1; j++)
        {
            int a = word[j] - 'a';
            int b = word[j + 1] - 'a';
            if (follow[a] != -1 && follow[a] != b)
            {
                cout << "NO\n";
                return 0;
            }
            follow[a] = b;
        }
    }
    array<int, 26> deg{};
    for (int i = 0; i < 26; i++)
        if (follow[i] != -1)
            deg[follow[i]]++;
    for (int i = 0; i < 26; i++)
        if (deg[i] > 1)
        {
            cout << "NO\n";
            return 0;
        }
    vector<string> chains;
    for (int i = 0; i < 26; i++)
    {
        if ((use & (1 << i)) && !deg[i])
        {
            string chain;
            for (int j = i; j != -1; j = follow[j])
                chain += 'a' + j;
            chains.push_back(chain);
        }
    }
    sort(RA(chains));
    string out;
    for (const string &c : chains)
        out += c;
    if (SZ(out) != __builtin_popcount(use))
        cout << "NO\n";
    else
        cout << out << "\n";

    return 0;
}