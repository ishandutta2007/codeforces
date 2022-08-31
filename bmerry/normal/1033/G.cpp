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
}

/*** TEMPLATE CODE ENDS HERE */

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N, M;
    cin >> N >> M;
    vll v(N);
    for (int i = 0; i < N; i++)
        cin >> v[i];
    ll ans[4] = {};
    for (ll s = 2; s <= 2 * M; s++)
    {
        int low = max(1LL, s - M);
        int high = (s - 1) / 2;

        vi r(N);
        vi spec{high};
        for (int i = 0; i < N; i++)
        {
            r[i] = v[i] % s;
            spec.push_back(r[i]);
            spec.push_back(s - r[i] - 1);
            spec.push_back(r[i] / 2);
        }
        sort(RA(r));
        sort(RA(spec));
        int prev = low - 1;
        int bidx = 0;
        int aidx = N;
        int b2idx = 0;
        for (int b : spec)
        {
            if (b < low || b > high)
                continue;
            int a = s - b;
            while (bidx < N && r[bidx] < b)
                bidx++;
            while (b2idx < N && r[b2idx] < 2 * b)
                b2idx++;
            while (aidx > 0 && r[aidx - 1] >= a)
                aidx--;

            bool bwin = bidx < aidx;
            int bnear = 0;
            int par = 0;
            bnear = N - max(aidx, b2idx);
            par = N - aidx;
            par &= 1;
            int idx;
            if (bwin || bnear > 1 || (bnear == 1 && par == 0))
                idx = 1;
            else if (par == 1)
                idx = 2;
            else
                idx = 3;
            ans[idx] += b - prev;
            prev = b;
        }
    }
    ans[0] = ans[1];
    ans[2] *= 2;
    ans[3] *= 2;
    for (int a = 1; a <= M; a++)
    {
        int par = 0;
        for (int i = 0; i < N; i++)
            par ^= v[i] / a;
        if (par & 1)
            ans[2]++;
        else
            ans[3]++;
    }
    cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << ' ' << ans[3] << '\n';

    return 0;
}