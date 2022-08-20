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

static void solve(const int *L, const int *R, int last, int mask, int *out)
{
    if (last == -1)
    {
        *out = R - L;
        return;
    }

    int m = 1 << last;
    const int *mid = lower_bound(L, R, mask | m);
    if (L != mid)
        solve(L, mid, last - 1, mask, out);
    if (mid != R)
        solve(mid, R, last - 1, mask | m, out + m);
    for (int i = 0; i < m; i++)
        out[m + i] += out[i];
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N;
    cin >> N;
    vector<int> words;
    for (int i = 0; i < N; i++)
    {
        string w;
        cin >> w;
        int b = 0;
        for (int j = 0; j < SZ(w); j++)
            b |= 1 << (w[j] - 'a');
        words.push_back(b);
    }

    sort(RA(words));
    vector<int> vals(1 << 24);
    solve(words.data(), words.data() + N, 23, 0, vals.data());
    int ans = 0;
    for (int v : vals)
    {
        int c = N - v;
        ans ^= c * c;
    }
    cout << ans << '\n';

    return 0;
}