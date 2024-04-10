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

static const int MOD = 1000000007;

static void done(ll ans)
{
    ans %= MOD;
    cout << ans << '\n';
    exit(0);
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    ll N, R, C;
    string pattern;
    cin >> N >> R >> C >> pattern;
    vector<pii> pos(N + 1);
    pos[0] = pii(0, 0);
    for (int i = 0; i < N; i++)
    {
        pos[i + 1] = pos[i];
        switch (pattern[i])
        {
        case 'U':
            pos[i + 1].first--;
            break;
        case 'D':
            pos[i + 1].first++;
            break;
        case 'L':
            pos[i + 1].second--;
            break;
        case 'R':
            pos[i + 1].second++;
            break;
        }
    }
    ll ans = 0;
    vector<ll> records;
    ll minr = 0, maxr = 0, minc = 0, maxc = 0;
    auto at_time = [&] (ll t, ll r, ll c) -> bool
    {
        if (r < minr || r > maxr)
        {
            minr = min(minr, r);
            maxr = max(maxr, r);
            ans = (ans + t * (C + minc - maxc)) % MOD;
            if (maxr - minr == R)
                return true;
        }
        if (c < minc || c > maxc)
        {
            minc = min(minc, c);
            maxc = max(maxc, c);
            ans = (ans + t * (R + minr - maxr)) % MOD;
            if (maxc - minc == C)
                return true;
        }
        return false;
    };
    for (ll i = 1; i <= N; i++)
    {
        if (at_time(i, pos[i].first, pos[i].second))
            done(ans);
    }
    ll tminr = minr, tmaxr = maxr, tminc = minc, tmaxc = maxc;
    ll dr = pos[N].first;
    ll dc = pos[N].second;
    if (dr == 0 && dc == 0)
    {
        cout << "-1\n";
        return 0;
    }
    for (ll i = 1; i <= N; i++)
    {
        ll r = pos[i].first + dr;
        ll c = pos[i].second + dc;
        if (r < tminr || r > tmaxr || c < tminc || c > tmaxc)
        {
            records.push_back(i);
            tminr = min(r, tminr);
            tmaxr = max(r, tmaxr);
            tminc = min(c, tminc);
            tmaxc = max(c, tmaxc);
        }
    }
    for (ll pass = 1; ; pass++)
    {
        for (int t0 : records)
        {
            ll t = t0 + pass * N;
            ll r = pos[t0].first + pass * dr;
            ll c = pos[t0].second + pass * dc;
            if (at_time(t, r, c))
                done(ans);
        }
    }
    return 0;
}