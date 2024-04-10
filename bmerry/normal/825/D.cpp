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
    string s, t;
    cin >> s >> t;
    vi tfreq(26), sfreq(26), qpos;
    for (char c : t)
        tfreq[c - 'a']++;
    int pos = 0;
    for (char c : s)
    {
        if (c == '?')
            qpos.push_back(pos);
        else
            sfreq[c - 'a']++;
        pos++;
    }

    ll lo = 0, hi = SZ(s) + 1;
    while (hi - lo > 1)
    {
        ll mid = lo + (hi - lo) / 2;
        ll need = 0;
        for (int i = 0; i < 26; i++)
            need += max(0LL, mid * tfreq[i] - sfreq[i]);
        if (need <= SZ(qpos))
            lo = mid;
        else
            hi = mid;
    }

    for (int i = 0; i < 26; i++)
    {
        int use = max(0LL, lo * tfreq[i] - sfreq[i]);
        for (int j = 0; j < use; j++)
        {
            s[qpos.back()] = 'a' + i;
            qpos.pop_back();
        }
    }
    for (int pos : qpos)
        s[pos] = 'a';
    cout << s << '\n';
    return 0;
}