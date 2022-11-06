// Dmitry _kun_ Sayutin (2019)

#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::cerr;

using std::vector;
using std::map;
using std::array;
using std::set;
using std::string;
using std::queue;

using std::pair;
using std::make_pair;

using std::tuple;
using std::make_tuple;
using std::get;

using std::min;
using std::abs;
using std::max;
using std::swap;

using std::unique;
using std::sort;
using std::generate;
using std::reverse;
using std::min_element;
using std::max_element;

#ifdef LOCAL
#define LASSERT(X) assert(X)
#else
#define LASSERT(X) {}
#endif

template <typename T>
T input() {
    T res;
    cin >> res;
    LASSERT(cin);
    return res;
}

template <typename IT>
void input_seq(IT b, IT e) {
    std::generate(b, e, input<typename std::remove_reference<decltype(*b)>::type>);
}

#define SZ(vec)         int((vec).size())
#define ALL(data)       data.begin(),data.end()
#define RALL(data)      data.rbegin(),data.rend()
#define TYPEMAX(type)   std::numeric_limits<type>::max()
#define TYPEMIN(type)   std::numeric_limits<type>::min()

int mod = 1000 * 1000 * 1000 + 7;
int add(int a, int b) {
    return (a + b >= mod ? a + b - mod : a + b);
}

int sub(int a, int b) {
    return (a >= b ? a - b : mod + a - b);
}

int mult(int a, int b) {
    return (int64_t(a) * b) % mod;
}

const int max_n = 6.1e5;
int fact[max_n];
int rfact[max_n];

int fpow(int a, int n)  {
    int r = 1;
    
    while (n) {
        if (n % 2)
            r = mult(r, a);

        n /= 2;
        a = mult(a,a);
    }
    return r;
}

int C(int a, int b) {
    return mult(fact[a + b], mult(rfact[a], rfact[b]));
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    fact[0] = rfact[0] = 1;
    for (int i = 1; i < max_n; ++i) {
        fact[i] = mult(i, fact[i - 1]);
        rfact[i] = fpow(fact[i], mod - 2);
    }
    
    // code here
    int n00, n01, n10, n11;

    auto get = [&](string s) {
        int explen = 1 + n00 + n01 + n10 + n11;
        if (SZ(s) < explen)
            return 0;
        if (SZ(s) > explen) {
            s = string(explen, '1');
        }

        int c[4] = {n00, n01, n10, n11};
        int ans = 0;
        for (int common = 1; common <= SZ(s); ++common) {
            if (common >= 2) {
                int id = (s[common - 2] - '0') * 2 + (s[common - 1] - '0');
                if (c[id] == 0)
                    break;

                c[id] -= 1;
            }

            if (common == SZ(s)) {
                if (c[0] + c[1] + c[2] + c[3] == 0)
                    ans = add(ans, 1);
                continue;
            }

            if (s[common] == '1') { // trying to decrease
                int id = (s[common - 1] - '0') * 2 + 0;
                if (c[id] == 0)
                    continue;
                c[id] -= 1;

                int ngo1 = c[0 * 2 + 1];
                int ngo0 = c[1 * 2 + 0];

                if (ngo1 == ngo0 or ngo1 == ngo0 + 1) {
                    int g0 = 1 + ngo0;
                    int g1 = ngo1;

                    if (not (c[3] != 0 and g1 == 0)) {
                        int delta = 1;
                        if (g1 != 0)
                            delta = mult(delta, C(c[3], g1 - 1));
                        if (g0 != 0)
                            delta = mult(delta, C(c[0], g0 - 1));
                        
                        ans = add(ans, delta);
                    }
                }

                c[id] += 1;
            }            
        }

        return ans;
    };
    
    string a, b;
        
    cin >> a >> b;
    cin >> n00 >> n01 >> n10 >> n11;

    int ans = get(b);
    if (a != "1") {
        int pos = SZ(a) - 1;

        while (a[pos] != '1') {
            a[pos] = '1';
            --pos;
        }
        a[pos] = '0';
        if (pos == 0)
            a.erase(a.begin());

        ans = sub(ans, get(a));
    }

    cout << ans << "\n";
    
    return 0;
}