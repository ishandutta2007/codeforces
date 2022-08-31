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

static void bit_add(vi &bit, int pos, int v)
{
    while (pos < SZ(bit))
    {
        bit[pos] += v;
        pos += pos & ~(pos - 1);
    }
}

static int bit_get(const vi &bit, int pos)
{
    int ans = 0;
    while (pos > 0)
    {
        ans += bit[pos];
        pos &= pos - 1;
    }
    return ans;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N;
    cin >> N;
    vector<pii> items;
    items.reserve(N);
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        items.emplace_back(a, i + 1);
    }
    sort(RA(items));
    vector<ll> ans(N);
    vi bit(N + 1);
    for (const pii &item : items)
    {
        int p = item.second;
        for (int k = 1; k < N; k++)
        {
            int lo = k * (p - 1) + 2;
            int hi = k * p + 2;
            if (lo > N)
                break;
            hi = min(hi, N + 1);
            ans[k] += bit_get(bit, hi - 1) - bit_get(bit, lo - 1);
        }
        bit_add(bit, p, 1);
    }
    for (int k = 1; k < N; k++)
        cout << ans[k] << ' ';
    cout << '\n';

    return 0;
}