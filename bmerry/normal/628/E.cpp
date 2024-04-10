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

template<typename T, typename Op = std::plus<T> >
class BIT
{
private:
    std::vector<T> values;
    Op op;
    T identity;

public:
    typedef T value_type;
    typedef typename std::vector<T>::size_type size_type;

    explicit BIT(size_type size = 0, Op op = Op(), T identity = T())
        : values(size + 1, identity), op(op), identity(identity) {}

    size_type size() const { return values.size() - 1; }

    void add(size_type idx, T delta)
    {
        assert(idx < size());
        idx++;
        while (idx < values.size())
        {
            values[idx] = op(values[idx], delta);
            idx += idx & ~(idx - 1);
        }
    }

    // Sum of values up to and including idx
    T sum(size_type idx) const
    {
        assert(idx < size());
        T ans = identity;
        idx++;
        while (idx > 0)
        {
            ans = op(ans, values[idx]);
            idx &= idx - 1;
        }
        return ans;
    }

    // Sum of values up to but excluding idx
    T sum_exclusive(size_type idx) const
    {
        return (idx == 0) ? identity : sum(idx - 1);
    }
};

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int R, C;
    cin >> R >> C;
    vector<string> grid(R);
    for (int i = 0; i < R; i++)
        cin >> grid[i];
    vector<vi> rcol(R, vi(C));
    vector<vi> lcol(R, vi(C));
    for (int i = 0; i < R; i++)
    {
        int s = -1;
        for (int j = 0; j < C; j++)
        {
            if (grid[i][j] != 'z')
                s = j;
            lcol[i][j] = s;
        }
        s = C;
        for (int j = C - 1; j >= 0; j--)
        {
            if (grid[i][j] != 'z')
                s = j;
            rcol[i][j] = s;
        }
    }

    ll ans = 0;
    for (int diag = 0; diag < R + C - 1; diag++)
    {
        int r = 0;
        int c = diag;
        if (c >= C)
        {
            r += c - C;
            c -= c - C;
        }
        bool on = false;
        int frow = R;
        BIT<ll> bit(R);
        priority_queue<pii> expire;
        while (r < R && c >= 0)
        {
            while (!expire.empty() && expire.top().first >= c)
            {
                bit.add(expire.top().second, -1);
                expire.pop();
            }
            if (grid[r][c] == 'z')
            {
                if (!on)
                    frow = r;
                on = true;
                bit.add(r, 1);
                expire.push(pii(lcol[r][c], r));
                int horiz = rcol[r][c] - c;
                int lo = max(frow, r - horiz + 1);
                ans += bit.sum(r) - bit.sum_exclusive(lo);
            }
            else
                on = false;
            r++;
            c--;
        }
    }
    cout << ans << '\n';

    return 0;
}