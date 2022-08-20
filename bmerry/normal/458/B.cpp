#include <bits/stdc++.h>

/*** TEMPLATE CODE STARTS HERE ***/

using namespace std;

typedef vector<string> vs;
typedef long long ll;
typedef complex<double> pnt;
typedef pair<int, int> pii;
typedef vector<ll> vll;

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

static ll solve(vll a, vll b)
{
    ll totalA = accumulate(RA(a), 0LL);
    ll totalB = accumulate(RA(b), 0LL);

    ll best = totalA + totalB;
    ll cur = best;
    sort(RA(b), greater<ll>());
    for (ll i = 0; i < SZ(b); i++)
    {
        cur -= b[i];
        best = min(best, cur);
        cur += totalA;
        if (cur > 2 * (totalA + totalB))
            break;
    }
    return best;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);

    ll A, B;
    cin >> A >> B;
    vll a(A), b(B);
    for (int i = 0; i < A; i++)
        cin >> a[i];
    for (int i = 0; i < B; i++)
        cin >> b[i];

    ll ans1 = solve(a, b);
    ll ans2 = solve(b, a);
    ll ans = min(ans1, ans2);
    cout << ans << '\n';

    return 0;
}