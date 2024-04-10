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
#include <limits>

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

template<typename T, T Modulus>
class MR
{
private:
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

public:
    typedef T value_type;
    static const T modulus = Modulus;

    MR() : value(0) {}
    MR(T value) : value(value) { reduce(); }

    MR &operator=(T value) { this->value = value; reduce(); return *this; }

    MR operator +(MR b) const { return MR(value + b.value); }
    MR operator -(MR b) const { return MR(value - b.value); }
    MR operator *(MR b) const { return MR(value * b.value); }
    MR operator -() const { return MR(-value); }

    MR &operator +=(MR b) { value += b.value; reduce(); return *this; }
    MR &operator -=(MR b) { value -= b.value; reduce(); return *this; }
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

int main(int argc, const char **argv)
{
    redirect(argc, argv);

    ll N, Q, T;
    cin >> N >> Q >> T;
    vector<ll> a(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];

    vector<int> domby(N, -1);
    vector<int> doms(N, -1);
    for (int i = 0; i < Q; i++)
    {
        int b, c;
        cin >> b >> c;
        b--;
        c--;
        domby[c] = b;
        doms[b] = c;
    }

    for (int i = 0; i < Q; i++)
    {
        int s = 0;
        while (s < N && !(domby[s] == -1 && doms[s] != -1))
            s++;
        if (s == N)
        {
            cout << "0\n";
            return 0;
        }

        T -= a[s];
        a[doms[s]] += a[s];
        domby[doms[s]] = -1;
        doms[s] = -1;
    }
    if (T < 0)
    {
        cout << "0\n";
        return 0;
    }

    typedef MR<ll, 1000000007> mr;
    vector<mr> dp(T + 1);
    dp[0] = mr(1);
    for (int i = 0; i < N; i++)
        for (int j = a[i]; j <= T; j++)
            dp[j] += dp[j - a[i]];
    cout << dp[T] << '\n';

    return 0;
}