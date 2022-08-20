//#pragma GCC optimize("O3")
//#pragma GCC target("arch=corei7-avx")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
# include <sys/time.h>
# include <sys/resource.h>
#endif

/*** TEMPLATE CODE STARTS HERE ***/

#ifndef M_PI
#define M_PI 3.1415926535897932384626433832795028841971693993751
#endif

using namespace std;

typedef vector<string> vs;
typedef long long ll;
typedef complex<double> pnt;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

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
#ifndef __SANITIZE_ADDRESS__
    getrlimit(RLIMIT_DATA, &rlim);
    rlim.rlim_cur = 256 * 1024 * 1024;
    setrlimit(RLIMIT_DATA, &rlim);
#endif
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
    cin.exceptions(ios::failbit);
}

/*** TEMPLATE CODE ENDS HERE */

class bits
{
public:
    typedef uint64_t word;

private:
    size_t size;
    vector<word> words;
    static constexpr size_t W = sizeof(word) * CHAR_BIT;

public:
    explicit bits(size_t size = 0);

    bool operator[](size_t idx) const;
    size_t count() const;
    void flip_range(size_t first, size_t last);

    pair<int, int> signature(const bits &other) const;
};

bits::bits(size_t size) : size(size), words((size + W - 1) / W) {}

bool bits::operator[](size_t idx) const
{
    return (words[idx / W] >> (idx % W)) & 1;
}

size_t bits::count() const
{
    size_t ans = 0;
    for (auto w : words)
        ans += (sizeof(w) <= sizeof(int) ? __builtin_popcount(w) : __builtin_popcountll(w));
    return ans;
}

void bits::flip_range(size_t first, size_t last)
{
    if (first == last)
        return;
    size_t wfirst = first / W;
    size_t wlast = last / W;
    size_t ofirst = first % W;
    size_t olast = last % W;
    word sfirst = (word(1) << ofirst) - 1;
    word slast = (word(1) << olast) - 1;
    if (wfirst == wlast)
        words[wfirst] ^= slast - sfirst;
    else
    {
        words[wfirst] ^= ~sfirst;
        for (size_t i = wfirst + 1; i < wlast; i++)
            words[i] = ~words[i];
        if (slast)
            words[wlast] ^= slast;
    }
}

pii bits::signature(const bits &other) const
{
    int x = -1, y = -1;
    for (size_t i = 0; i < words.size(); i++)
    {
        word u = words[i];
        word v = other.words[i];
        word a = u & ~v;
        word b = v & ~u;
        if (a)
            x = i * W + __builtin_ctzll(a);
        if (b)
            y = i * W + __builtin_ctzll(b);
    }
    if (x != -1 && y != -1)
        return make_pair(x, y);
    else
        return make_pair(-1, -1);
}

struct certificate
{
    int r1, r2;
    int c1, c2;

    bool operator<(const certificate &other) const
    {
        return tie(r1, r2, c1, c2) < tie(other.r1, other.r2, other.c1, other.c2);
    }
};

int main(int argc, const char **argv)
{
    redirect(argc, argv);

    int R, C, Q;
    cin >> R >> C >> Q;
    vector<bits> rows(R, bits(C));
    set<pii> order;
    set<certificate> certs;
    for (int i = 0; i < R; i++)
        order.emplace(0, i);

    auto join = [&](int r1, int r2)
    {
        pii sig = rows[r1].signature(rows[r2]);
        if (sig.first != -1)
        {
            certificate cert{r1, r2, sig.first, sig.second};
            certs.insert(cert);
        }
    };

    auto split = [&](int r1, int r2)
    {
        pii sig = rows[r1].signature(rows[r2]);
        if (sig.first != -1)
        {
            certificate cert{r1, r2, sig.first, sig.second};
            certs.erase(cert);
        }
    };

    for (int q = 0; q < Q; q++)
    {
        int a, l, r;
        cin >> a >> l >> r;
        a--;
        l--;
        int c = rows[a].count();
        auto old_pos = order.find(pii(c, a));
        if (old_pos != order.begin())
            split(prev(old_pos)->second, a);
        auto p = next(old_pos);
        if (p != order.end())
            split(a, p->second);
        if (p != order.end() && old_pos != order.begin())
            join(prev(old_pos)->second, p->second);
        order.erase(old_pos);

        rows[a].flip_range(l, r);
        c = rows[a].count();
        auto new_pos = order.emplace(c, a).first;
        if (new_pos != order.begin())
            join(prev(new_pos)->second, a);
        p = next(new_pos);
        if (p != order.end())
            join(a, p->second);
        if (p != order.end() && new_pos != order.begin())
            split(prev(new_pos)->second, p->second);

        if (certs.empty())
            cout << "-1\n";
        else
        {
            auto c = *certs.begin();
            auto sig = rows[c.r1].signature(rows[c.r2]);
            if (c.r1 > c.r2)
                swap(c.r1, c.r2);
            if (c.c1 > c.c2)
                swap(c.c1, c.c2);
            cout << c.r1 + 1 << ' ' << c.c1 + 1 << ' ' << c.r2 + 1 << ' ' << c.c2 + 1 << '\n';
        }
    }

    return 0;
}