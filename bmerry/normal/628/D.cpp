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

typedef MR<ll, 1000000007> mr;

static mr solve(string b, int magic, int M, bool inclusive)
{
    int forbid = magic * 11;
    int goal = 0;
    vi permitted;
    reverse(RA(b));
    if (SZ(b) & 1)
    {
        goal = magic % M;
        for (int i = 0; i < SZ(b); i++)
            goal = goal * 10 % M;
        b.push_back(magic + '0');
        for (int i = 10 * magic; i < 10 * magic + 10; i++)
            if (i != forbid)
                permitted.push_back(i);
    }
    else
    {
        for (int i = magic; i < 100; i += 10)
            if (i != forbid)
                permitted.push_back(i);
    }

    vector<int> hbits(SZ(b) / 2);
    for (int i = 0; i < SZ(b) / 2; i++)
        hbits[i] = (b[2 * i] - '0') + 10 * (b[2 * i + 1] - '0');
    int D = SZ(hbits);

    vector<mr> dist(M);
    dist[0] = 1;
    int good = D;
    while (good - 1 >= 0 && count(RA(permitted), hbits[good - 1]))
        good--;
    int p100 = 1;
    mr ans = 0;
    for (int R = 0; R < D; R++, p100 = p100 * 100 % M)
    {
        if (R >= good - 1)
        {
            int hi = hbits[R];
            if (R == 0 && inclusive)
                hi++;
            int base = 0;
            int q100 = p100 * 100 % M;
            for (int i = R + 1; i < D; i++, q100 = q100 * 100 % M)
            {
                base += hbits[i] * q100 % M;
                base %= M;
            }
            for (int i : permitted)
            {
                if (i >= hi)
                    break;
                int ofs = (base + i * p100) % M;
                ans += dist[(goal + M - ofs) % M];
            }
        }

        vector<mr> dist2(M);
        for (int i : permitted)
        {
            for (int j = 0; j < M; j++)
            {
                int s = (j + i * p100) % M;
                dist2[s] += dist[j];
            }
        }
        dist = move(dist2);
    }
    return ans;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int m, d;
    string a, b;
    cin >> m >> d >> a >> b;
    mr hi = solve(b, d, m, true);
    mr lo = solve(a, d, m, false);
    cout << hi - lo << '\n';

    return 0;
}