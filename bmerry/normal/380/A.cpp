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

struct op
{
    ll l;
    ll c;
    ll len;
};

int main(int argc, const char **argv)
{
    redirect(argc, argv);

    int M;
    cin >> M;
    vector<op> ops;

    ll len = 0;
    vector<int> start;
    start.reserve(100000);
    unordered_map<ll, int> added;
    for (int i = 0; i < M; i++)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int x;
            cin >> x;
            if (len < 100000)
                start.push_back(x);
            added[len] = x;
            len++;
        }
        else
        {
            op o;
            cin >> o.l >> o.c;
            o.len = len;
            ll len2 = len + o.l * o.c;
            ll limit = min(100000LL, len2);
            ll next = 0;
            for (ll i = len; i < limit; i++)
            {
                start.push_back(start[next]);
                next++;
                if (next == o.l)
                    next = 0;
            }
            len = len2;
            ops.push_back(o);
        }
    }

    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        ll q;
        ll ans;
        cin >> q;
        q--;
        if (added.count(q))
            ans = added[q];
        else
        {
            auto p = upper_bound(RA(ops), q, [](ll v, const op &o) { return v < o.len; });
            --p;
            assert(p->len + p->l * p->c > q);
            ans = start[(q - p->len) % p->l];
        }
        cout << ans << ' ';
    }
    cout << '\n';

    return 0;
}