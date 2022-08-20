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
    vector<ll> pos[3];
    for (int i = 0; i < N; i++)
    {
        int p;
        char c;
        cin >> p >> c;
        int part = (c == 'G') ? 0 : (c == 'R') ? 1 : 2;
        pos[part].push_back(p);
    }

    ll ans = 0;
    if (!pos[0].empty())
        ans += pos[0].back() - pos[0][0];
    else
    {
        for (int s = 1; s <= 2; s++)
            if (!pos[s].empty())
                ans += pos[s].back() - pos[s][0];
        cout << ans << '\n';
        return 0;
    }
    pos[0].insert(pos[0].begin(), LLONG_MIN / 8);
    pos[0].push_back(LLONG_MAX / 8);

    const auto &green = pos[0];
    int p[2] = {0, 0};
    for (int i = 0; i < SZ(green) - 1; i++)
    {
        ll h[2] = {0, 0};
        for (int j = 0; j < 2; j++)
        {
            const auto &red = pos[j + 1];
            int q = p[j];
            while (q < SZ(red) && red[q] < green[i + 1])
                q++;
            if (q != p[j])
            {
                ll gap = max(red[p[j]] - green[i], green[i + 1] - red[q - 1]);
                for (int k = p[j]; k < q - 1; k++)
                    gap = max(gap, red[k + 1] - red[k]);
                h[j] = green[i + 1] - green[i] - gap;
                p[j] = q;
            }
        }
        ll add = min(h[0] + h[1], green[i + 1] - green[i]);
        ans += add;
    }
    cout << ans << '\n';

    return 0;
}