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

struct event
{
    ll phase;
    ll rep;
    ll x, y;

    bool operator<(const event &b) const
    {
        return phase < b.phase;
    }
};

static void bad()
{
    cout << "NO\n";
    exit(0);
}

static ll div_down(ll p, ll q)
{
    ll r = p / q;
    if (r * q > p)
        r--;
    return r;
}

static ll div_up(ll p, ll q)
{
    ll r = p / q;
    if (r * q < p)
        r++;
    return r;
}

static ll parity(ll x)
{
    return (unsigned long long) x & 1;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    ll N, L;
    cin >> N >> L;
    vector<event> events;
    events.reserve(N + 2);
    for (ll i = 0; i < N; i++)
    {
        ll t, p, q;
        cin >> t >> p >> q;
        ll x = p + q;
        ll y = p - q;
        if (parity(x) != parity(t))
            bad();
        events.push_back(event{t % L, t / L, x, y});
    }
    events.push_back(event{0, 0, 0, 0});
    events.push_back(event{L, -1, 0, 0});
    N += 2;
    sort(RA(events));
    ll minx = -L;
    ll maxx = L;
    ll miny = -L;
    ll maxy = L;
    for (ll i = 1; i < N; i++)
    {
        event e1 = events[i - 1];
        event e2 = events[i];
        ll rep = e1.rep - e2.rep;
        if (rep < 0)
        {
            swap(e1, e2);
            rep = -rep;
        }
        ll dt = llabs(e1.phase - e2.phase);
        ll dx = e1.x - e2.x;
        ll dy = e1.y - e2.y;
        if (rep == 0)
        {
            if (llabs(dx) > dt || llabs(dy) > dt)
                bad();
        }
        else
        {
            minx = max(minx, div_up(dx - dt, rep));
            maxx = min(maxx, div_down(dx + dt, rep));
            miny = max(miny, div_up(dy - dt, rep));
            maxy = min(maxy, div_down(dy + dt, rep));
        }
    }

    if (parity(minx) != parity(L))
        minx++;
    if (parity(miny) != parity(L))
        miny++;
    if (parity(maxx) != parity(L))
        maxx--;
    if (parity(maxy) != parity(L))
        maxy--;

    if (minx > maxx || miny > maxy)
        bad();

    string seq;
    for (event &e : events)
    {
        e.x -= e.rep * minx;
        e.y -= e.rep * miny;
        e.rep = 0;
    }
    for (ll i = 1; i < N; i++)
    {
        ll dx = events[i].x - events[i - 1].x;
        ll dy = events[i].y - events[i - 1].y;
        for (int j = events[i - 1].phase; j < events[i].phase; j++)
        {
            char c;
            if (dx > 0 && dy > 0)
                c = 'R', dx--, dy--;
            else if (dx > 0)
                c = 'U', dx--, dy++;
            else if (dy > 0)
                c = 'D', dx++, dy--;
            else
                c = 'L', dx++, dy++;
            seq += c;
        }
        assert(dx == 0 && dy == 0);
    }
    cout << seq << '\n';

    return 0;
}