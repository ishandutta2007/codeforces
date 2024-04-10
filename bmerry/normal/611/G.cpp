#include <bits/stdc++.h>

/*** TEMPLATE CODE STARTS HERE ***/

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef long long ll;
typedef complex<ll> pnt;
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

static ll cross(const pnt &a, const pnt &b)
{
    return imag(conj(a) * b);
}

static ll cross(const pnt &a, const pnt &b, const pnt &c)
{
    return cross(b - a, c - a);
}

static const int MOD = 1000000007;

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N;
    cin >> N;
    vector<pnt> pnts;
    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        pnts.emplace_back(x, y);
    }
    reverse(RA(pnts));

    auto wrap = [N] (int idx) { return idx >= N ? idx - N : idx; };

    ll area = 0;
    for (int i = 0; i < N; i++)
        area += cross(pnts[i ? i - 1 : N - 1], pnts[i]);

    ll ans = 0;
    ll cur_area = 0;
    ll cur_sum = 0;
    pnt cur_psum = pnts[1];
    int end = 1;
    ll M = 1;
    auto fix = [&] ()
    {
        cur_sum %= MOD;
        cur_psum = pnt(cur_psum.real() % MOD, cur_psum.imag() % MOD);
    };
    for (int i = 0; i < N; i++)
    {
        if (i > 0)
        {
            cur_area -= cross(pnts[i - 1], pnts[i], pnts[end]);
            pnt sub = cur_psum - M * pnts[i - 1];
            sub = pnt(sub.real() % MOD, sub.imag() % MOD);
            cur_sum -= cross(pnts[i] - pnts[i - 1], sub);
            cur_psum -= pnts[i];
            M--;
            fix();
        }
        while (true)
        {
            ll next_tri = cross(pnts[i], pnts[end], pnts[wrap(end + 1)]);
            if (cur_area + next_tri <= area / 2)
            {
                end = wrap(end + 1);
                cur_area += next_tri;
                cur_sum += cur_area;
                cur_psum += pnts[end];
                M++;
                fix();
            }
            else
                break;
        }
        ans = (ans + (M - 1) * (area % MOD) % MOD - 2 * cur_sum % MOD) % MOD;
    }
    if (ans < 0)
        ans += MOD;
    cout << int(ans) << '\n';
    return 0;
}