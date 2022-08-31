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

struct wevent
{
    int x;
    int t;
    bool start;

    wevent() {}
    wevent(int x, int t, bool start) : x(x), t(t), start(start) {}

    bool operator<(const wevent &other) const
    {
        if (x != other.x)
            return x < other.x;
        else if (t != other.t)
            return t < other.t;
        else
            return start < other.start;
    }
};

struct sevent
{
    int t0;
    int delta;

    sevent() {}
    sevent(int t0, int delta) : t0(t0), delta(delta) {}

    bool operator<(const sevent &other) const
    {
        return t0 < other.t0;
    }
};

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N, M;
    cin >> N >> M;
    vector<wevent> wevents;
    vector<sevent> sevents;
    for (int i = 0; i < M; i++)
    {
        int l, r, t;
        cin >> l >> r >> t;
        wevents.push_back(wevent(l, t, true));
        wevents.push_back(wevent(r, t, false));
    }
    sort(RA(wevents));
    int p = 0;
    multiset<int> active;
    while (p < SZ(wevents))
    {
        int q = p;
        int x = wevents[p].x;
        if (!active.empty())
            sevents.push_back(sevent(*active.begin() - x, +1));
        while (q < SZ(wevents) && wevents[q].x == x)
        {
            if (wevents[q].start)
                active.insert(wevents[q].t);
            else
                active.erase(active.find(wevents[q].t));
            q++;
        }
        if (!active.empty())
            sevents.push_back(sevent(*active.begin() - x, -1));
        p = q;
    }

    sort(RA(sevents));
    ll slope = 0;
    ll v = 0;
    ll t0 = INT_MIN;
    p = 0;
    for (int i = 0; i < N; i++)
    {
        ll q;
        cin >> q;
        while (p < SZ(sevents) && sevents[p].t0 <= q)
        {
            v += slope * (sevents[p].t0 - t0);
            slope += sevents[p].delta;
            t0 = sevents[p].t0;
            p++;
        }
        ll ans = v + slope * (q - t0);
        cout << ans << '\n';
    }

    return 0;
}