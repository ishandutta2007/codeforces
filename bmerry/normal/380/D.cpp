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

// m must be positive
template<typename T>
static T mod(T a, T m)
{
    a %= m;
    if (a < 0)
        a += m;
    return a;
}

// a must be relatively prime to m
template<typename T>
static T inverse(T a, T m)
{
    a = mod(a, m);
    if (a == 1)
        return a;
    return mod((1 - inverse(m, a) * m) / a, m);
}

/*** TEMPLATE CODE ENDS HERE */

#define MOD 1000000007LL

struct fitem
{
    int pos;
    int v;
};

static ll fact[100001];
static ll pow2[100001];

static ll choose(int n, int r)
{
    if (r < 0 || r > n)
        return 0;
    ll nom = fact[n];
    ll den = (fact[r] * fact[n - r]) % MOD;
    return (nom * inverse(den, MOD)) % MOD;
}

int main(int argc, const char **argv)
{
    fact[0] = 1;
    pow2[0] = 1;
    for (ll i = 1; i <= 100000; i++)
    {
        fact[i] = (fact[i - 1] * i) % MOD;
        pow2[i] = (pow2[i - 1] * 2) % MOD;
    }

    redirect(argc, argv);
    int N;
    cin >> N;
    vector<fitem> fixed;
    int min_idx = -1;
    int min_v = N;
    for (int i = 0; i < N; i++)
    {
        int v;
        cin >> v;
        v--;
        if (v != -1)
        {
            if (v < min_v)
            {
                min_v = v;
                min_idx = fixed.size();
            }
            fixed.push_back({i, v});
        }
    }

    ll ans = 0;
    bool bad = false;
    for (int i = 0; i < min_idx; i++)
        if (fixed[i].v < fixed[i + 1].v)
            bad = true;
    for (int i = min_idx; i < SZ(fixed) - 1; i++)
        if (fixed[i].v > fixed[i + 1].v)
            bad = true;

    if (min_idx == -1)
        ans = pow2[N - 1];
    else if (!bad)
    {
        for (int start = min_idx - 1; start <= min_idx; start++)
        {
            if (start == min_idx && min_v == 0)
                continue;
            int l = start;
            int r = start + 1;
            ll sub = pow2[max(min_v - 1, 0)];
            int p, q;
            if (start == min_idx)
            {
                p = fixed[min_idx].pos + 1;
                q = p + min_v;
            }
            else
            {
                q = fixed[min_idx].pos;
                p = q - min_v;
            }

            while (l >= 0 || r < SZ(fixed))
            {
                if (r >= SZ(fixed) || (l >= 0 && fixed[l].v < fixed[r].v))
                {
                    int p2 = fixed[l].pos + 1;
                    int q2 = p2 + fixed[l].v;
                    if (p2 > p || q2 < q)
                        goto skip;
                    sub = (sub * choose(p - p2 + q2 - q, p - p2)) % MOD;
                    p = p2 - 1;
                    q = q2;
                    l--;
                }
                else
                {
                    int q2 = fixed[r].pos;
                    int p2 = q2 - fixed[r].v;
                    if (p2 > p || q2 < q)
                        goto skip;
                    sub = (sub * choose(p - p2 + q2 - q, p - p2)) % MOD;
                    p = p2;
                    q = q2 + 1;
                    r++;
                }
            }
            sub = (sub * choose(p + N - q, p)) % MOD;
            ans = (ans + sub) % MOD;
skip:;
        }
    }
    cout << ans << '\n';

    return 0;
}