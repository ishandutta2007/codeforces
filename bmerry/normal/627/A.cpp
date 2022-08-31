#include <bits/stdc++.h>

/*** TEMPLATE CODE STARTS HERE ***/

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef long long ll;
typedef complex<double> pnt;
typedef pair<int, int> pii;

#define RA(x) begin(x), end(x)
#define FE(i, x) for (auto i = begin(x); i != end(x); ++i)
#define SZ(x) ((int) (x).size())

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

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    ll s, x;
    cin >> s >> x;

    ll dp[2] = {1, 0};
    for (ll bit = 45; bit >= 0; bit--)
    {
        ll sb = (s >> bit) & 1;
        ll xb = (x >> bit) & 1;
        ll dp2[2] = {0, 0};
        for (ll i = 0; i < 2; i++)
        {
            ll j = xb ^ i;
            for (ll k = 0; k < 2; k++)
            {
                if (((i + j + k) & 1) != sb)
                    continue;
                dp2[k] += dp[(i + j + k) >> 1];
            }
        }
        copy(dp2, dp2 + 2, dp);
    }

    ll ans = dp[0];
    if (s == x)
        ans -= 2;
    cout << ans << '\n';

    return 0;
}