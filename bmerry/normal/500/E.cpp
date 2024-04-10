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

struct plan
{
    ll y;
    int id;
};

struct se
{
    ll x;
    ll cost;
    ll sum;

    bool operator<(ll x2) const
    {
        return x > x2;
    }
};

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N;
    cin >> N;
    vector<ll> p(N);
    vector<ll> l(N);
    for (int i = 0; i < N; i++)
        cin >> p[i] >> l[i];
    int Q;
    cin >> Q;
    vector<vector<plan> > plans(N);
    for (int i = 0; i < Q; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        plans[x].push_back(plan{y, i});
    }
    vector<ll> ans(Q);

    vector<se> st;
    st.push_back(se{LLONG_MAX / 2, 0, 0});
    for (int i = N - 1; i >= 0; i--)
    {
        ll e = p[i] + l[i];
        while (e >= st.back().x)
            st.pop_back();
        ll d = st.back().x - e;
        if (d < st.back().cost)
        {
            st.back().sum -= st.back().cost - d;
            st.back().cost = d;
        }

        for (const plan &pl : plans[i])
        {
            ll cost = st.back().sum;
            auto pos = prev(lower_bound(RA(st), p[pl.y]));
            cost -= pos->sum;
            ans[pl.id] = cost;
        }

        st.push_back(se{p[i], LLONG_MAX / 4, st.back().sum + LLONG_MAX / 4});
    }

    for (int i = 0; i < Q; i++)
        cout << ans[i] << '\n';

    return 0;
}