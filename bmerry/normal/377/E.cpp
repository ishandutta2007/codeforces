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

struct build
{
    ll v;
    ll c;

    bool operator<(const build &b) const
    {
        return tie(c, b.v) < tie(b.c, v);
    }
};

struct state
{
    ll t;
    ll v;
    ll y;
};

static ll cookies_at(const state &s, ll t)
{
    return t * s.v + s.y;
}

static ll divup(ll a, ll b)
{
    return (a + b - 1) / b;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);

    int N;
    ll S;
    cin >> N >> S;
    vector<build> b(N);
    for (int i = 0; i < N; i++)
    {
        cin >> b[i].v >> b[i].c;
    }
    sort(RA(b));

    vector<state> st;
    st.push_back(state{0LL, 0LL, 0LL});
    for (int i = 0; i < N; i++)
    {
        if (i > 0 && b[i].v <= b[i - 1].v)
            continue;

        int lo = -1;
        int hi = SZ(st) - 1;
        while (hi - lo > 1)
        {
            int mid = (lo + hi) / 2;
            ll end = (st[mid + 1].t - 1) * st[mid].v + st[mid].y;
            if (end >= b[i].c)
                hi = mid;
            else
                lo = mid;
        }

        ll t0;
        if (b[i].c == st[hi].y)
            t0 = st[hi].t;
        else
            t0 = divup(b[i].c - st[hi].y, st[hi].v);

        state s;
        s.v = b[i].v;
        s.y = st[hi].v * t0 + st[hi].y - b[i].c - b[i].v * t0;

        while (!st.empty() && st.back().t >= t0
               && cookies_at(st.back(), st.back().t) <= cookies_at(s, st.back().t))
            st.pop_back();

        if (st.empty())
            st.push_back(s);
        else if (st.back().v < s.v)
        {
            s.t = divup(st.back().y - s.y, s.v - st.back().v);
            st.push_back(s);
        }
    }

    int lo = -1;
    int hi = SZ(st) - 1;
    while (hi - lo > 1)
    {
        int mid = (lo + hi) / 2;
        ll end = (st[mid + 1].t - 1) * st[mid].v + st[mid].y;
        if (end >= S)
            hi = mid;
        else
            lo = mid;
    }

    ll t0 = divup(S - st[hi].y, st[hi].v);
    cout << t0 << '\n';

    return 0;
}