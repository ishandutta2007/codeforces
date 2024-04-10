#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
# include <sys/time.h>
# include <sys/resource.h>
#endif

/*** TEMPLATE CODE STARTS HERE ***/

using namespace std;

typedef vector<string> vs;
typedef long long ll;
typedef complex<double> pnt;
typedef vector<ll> vi;
typedef pair<ll, ll> pii;

#define RA(x) begin(x), end(x)
#define FE(i, x) for (auto i = begin(x); i != end(x); ++i)
#define SZ(x) ((ll) (x).size())

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
#ifndef ONLINE_JUDGE
    struct rlimit rlim;
    getrlimit(RLIMIT_STACK, &rlim);
    rlim.rlim_cur = 256 * 1024 * 1024;
    setrlimit(RLIMIT_STACK, &rlim);
    getrlimit(RLIMIT_DATA, &rlim);
    rlim.rlim_cur = 256 * 1024 * 1024;
    setrlimit(RLIMIT_DATA, &rlim);
#endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);
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

/*** TEMPLATE CODE ENDS HERE */

static inline int ident(char c)
{
    static const char nuc[4] = {'A', 'C', 'G', 'T'};
    return find(nuc, nuc + 4, c) - nuc;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    string s;
    cin >> s;
    int L = SZ(s);

    BIT<int> bits[11][10][4];
    for (int period = 1; period <= 10; period++)
        for (int phase = 0; phase < period; phase++)
            for (int ch = 0; ch < 4; ch++)
                bits[period][phase][ch] = BIT<int>(L + 1);

    for (int period = 1; period <= 10; period++)
        for (int i = 0; i < L; i++)
        {
            int c = ident(s[i]);
            bits[period][i % period][c].add(i, 1);
        }

    int Q;
    cin >> Q;
    for (int q = 0; q < Q; q++)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int x; char ch;
            cin >> x >> ch;
            x--;
            int oldc = ident(s[x]);
            int newc = ident(ch);
            s[x] = ch;
            for (int period = 1; period <= 10; period++)
            {
                int phase = x % period;
                bits[period][phase][oldc].add(x, -1);
                bits[period][phase][newc].add(x, 1);
            }
        }
        else
        {
            int l, r;
            string e;
            cin >> l >> r >> e;
            l--;
            int period = SZ(e);
            int phase = l % period;
            int ans = 0;
            for (int i = 0; i < period; i++)
            {
                int c = ident(e[i]);
                int part = bits[period][phase][c].sum_exclusive(r) - bits[period][phase][c].sum_exclusive(l);
                ans += part;
                phase++;
                if (phase == period)
                    phase = 0;
            }
            cout << ans << '\n';
        }
    }

    return 0;
}