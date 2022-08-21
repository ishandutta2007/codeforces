#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <iostream>
#include <sstream>
#include <cstddef>
#include <algorithm>
#include <utility>
#include <iterator>
#include <numeric>
#include <list>
#include <complex>
#include <cstdio>
#include <climits>
#include <iostream>
#include <fstream>

/*** TEMPLATE CODE STARTS HERE ***/

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef long long ll;
typedef complex<double> pnt;
typedef pair<int, int> pii;
typedef vector<ll> vll;

#define RA(x) (x).begin(), (x).end()
#define FE(i, x) for (typeof((x).begin()) i = (x).begin(); i != (x).end(); i++)
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

#define MOD 1000000007

static pair<int, ll> find(vi &parent, vll &weight, int x)
{
    int y = x;
    ll w = 0;
    while (parent[y] >= 0)
    {
        w = (w + weight[y]) % MOD;
        y = parent[y];
    }

    ll ws = 0;
    while (parent[x] >= 0)
    {
        int n = parent[x];
        ll wn = weight[x];

        parent[x] = y;
        weight[x] = (w - ws) % MOD;
        ws = (ws + wn) % MOD;
        x = n;
    }

    return make_pair(y, w);
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);

    int N;
    cin >> N;
    vi parent(N, -1);
    vll weight(N, 0);
    ll ans = 0;
    for (int i = 0; i < N; i++)
    {
        int K;
        cin >> K;
        for (int j = 0; j < K; j++)
        {
            int v;
            ll x;
            cin >> v >> x;
            v--;
            pair<int, ll> root = find(parent, weight, v);
            ll w = (root.second + x) % MOD;
            ans = (ans + w) % MOD;
            parent[root.first] = i;
            weight[root.first] = w;
            cerr << i << ' ' << root.first << ' ' << w << '\n';
        }
    }
    ans %= MOD;
    if (ans < 0)
        ans += MOD;
    cout << ans << '\n';

    return 0;
}