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

template<typename T, T Modulus>
class MR
{
private:
    struct tag_plus {}; // indicates value is in range [0, 2 * Modulus)
    struct tag_minus {}; // indicates value is in range (-Modulus, Modulus)

    T value;

    enum
    {
        ASSERT_FALSE = 0,
        ASSERT_TEST = (T(1) << (std::numeric_limits<T>::digits - 1)) / Modulus / Modulus > 0 ? 1 : 0
    };

    void reduce()
    {
        value %= Modulus;
        if (value < 0)
            value += Modulus;
    }

    void reduce(tag_plus)
    {
        if (value >= Modulus)
            value -= Modulus;
    }

    void reduce(tag_minus)
    {
        if (value < 0)
            value += Modulus;
    }

public:
    typedef T value_type;
    static const T modulus = Modulus;

    MR() : value(0) {}
    MR(T value) : value(value) { reduce(); }
    template<typename tag_t>
    MR(T value, tag_t tag) : value(value) { reduce(tag); }

    MR &operator=(T value) { this->value = value; reduce(); return *this; }

    MR operator +(MR b) const { return MR(value + b.value, tag_plus()); }
    MR operator -(MR b) const { return MR(value - b.value, tag_minus()); }
    MR operator *(MR b) const { return MR(value * b.value); }
    MR operator -() const { return MR(-value); }

    MR &operator +=(MR b) { value += b.value; reduce(tag_plus()); return *this; }
    MR &operator -=(MR b) { value -= b.value; reduce(tag_minus()); return *this; }
    MR &operator *=(MR b) { value *= b.value; reduce(); return *this; }

    bool operator==(MR b) const { return value == b.value; }
    bool operator!=(MR b) const { return value != b.value; }

    T get() const { return value; }
};

template<typename T, T Modulus>
static inline std::ostream &operator<<(std::ostream &o, MR<T, Modulus> mr)
{
    return o << mr.get();
}

/*** TEMPLATE CODE ENDS HERE */

struct SAEntry
{
    int str;
    int ofs;
    ll score;
    int share;

    SAEntry() : share(0) {}
    SAEntry(int str, int ofs, ll score) : str(str), ofs(ofs), score(score), share(0) {}

    bool operator<(const SAEntry &b) const
    {
        return tie(score, str) < tie(b.score, b.str);
    }
};

template<typename Container>
std::vector<SAEntry> make_suffix_array(const Container &strings)
{
    int N = strings.size();
    std::vector<std::vector<int> > rank(N);
    int ae = 0;
    int mchars = 0;
    for (int i = 0; i < N; i++)
    {
        rank[i].resize(strings[i].size() + 1);
        ae += rank[i].size();
        mchars = std::max(mchars, int(strings[i].size()));
    }

    std::vector<SAEntry> ans;
    ans.reserve(ae);
    for (int i = 0; i < N; i++)
    {
        for (std::size_t j = 0; j < strings[i].size(); j++)
        {
            ans.push_back(SAEntry(i, j, strings[i][j]));
        }
        ans.push_back(SAEntry(i, strings[i].size(), 0));
    }
    assert(ans.size() == ae);
    sort(ans.begin(), ans.end());

    for (int step = 1; step <= mchars; step *= 2)
    {
        ll pscore = -1;
        int r = -1;
        for (int i = 0; i < ae; i++)
        {
            if (ans[i].score != pscore)
            {
                pscore = ans[i].score;
                r++;
            }
            rank[ans[i].str][ans[i].ofs] = r;
        }

        for (int i = 0; i < ae; i++)
        {
            int s = ans[i].str;
            int o = ans[i].ofs;
            ans[i].score = rank[s][o];
            ans[i].score <<= 32;
            if (o + step < rank[s].size())
                ans[i].score += rank[s][o + step];
        }
        sort(ans.begin(), ans.end());
    }

    for (int i = 0; i < ae; i++)
        rank[ans[i].str][ans[i].ofs] = i;

    for (int i = 0; i < N; i++)
    {
        int s = 0;
        int L = strings[i].size();
        for (int j = 0; j <= L; j++)
        {
            s--;
            if (s < 0)
                s = 0;
            int p = rank[i][j];
            if (p > 0)
            {
                const int pi = ans[p - 1].str;
                const int pj = ans[p - 1].ofs;
                const int pL = strings[pi].size();
                while (j + s < L && pj + s < pL && strings[i][j + s] == strings[pi][pj + s])
                    s++;
            }
            else
                s = 0;
            ans[p].share = s;
        }
    }

    return ans;
}

#define MOD 1000000007

typedef MR<ll, MOD> mr;

static mr countit(int p, int q, const vector<int> ac[3])
{
    mr prod = 1;
    for (int i = 0; i < 3; i++)
    {
        mr t = ac[i][q] - ac[i][p];
        prod *= t;
    }
    return prod;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    array<string, 3> S;
    cin >> S[0] >> S[1] >> S[2];
    int minL = min({SZ(S[0]), SZ(S[1]), SZ(S[2])});

    vector<SAEntry> sa = make_suffix_array(S);
    vector<int> ac[3];
    for (int i = 0; i < 3; i++)
    {
        ac[i].resize(sa.size() + 1);
        int tot = 0;
        for (int j = 0; j < SZ(sa); j++)
        {
            ac[i][j] = tot;
            tot += (sa[j].str == i);
        }
        ac[i].back() = tot;
    }
    set<int> cuts{0, SZ(sa)};
    vector<pii> splits;
    for (int i = 1; i < SZ(sa); i++)
    {
        splits.emplace_back(sa[i].share, i);
    }
    sort(RA(splits));

    int ns = 0;
    mr prod = countit(0, SZ(sa), ac);
    for (int l = 1; l <= minL; l++)
    {
        while (ns < SZ(splits) && splits[ns].first < l)
        {
            int c = splits[ns++].second;
            auto p = cuts.upper_bound(c);
            auto q = p;
            --p;
            prod -= countit(*p, *q, ac);
            prod += countit(*p, c, ac);
            prod += countit(c, *q, ac);
            cuts.insert(c);
        }
        cout << prod << ' ';
    }
    cout << '\n';

    return 0;
}