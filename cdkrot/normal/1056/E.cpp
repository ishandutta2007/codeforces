// 2018, Sayutin Dmitry.

#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::cerr;

using std::vector;
using std::map;
using std::array;
using std::set;
using std::string;

using std::pair;
using std::make_pair;

using std::tuple;
using std::make_tuple;
using std::get;

using std::min;
using std::abs;
using std::max;

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

#define pb push_back
#define eb emplace_back

template <int MOD>
struct mod_t {
    int add(int a, int b) const {
        return (a + b >= MOD ? a + b - MOD : a + b);
    }
        
    int sub(int a, int b) const {
        return (a >= b ? a - b : MOD + a - b);
    }

    int mult(int a, int b) const {
        return (int64_t(a) * b) % MOD;
    }
};
    
const mod_t<1000 * 1000 * 1000 + 7> mod1;
const mod_t<1000 * 1000 * 1000 + 9> mod2;

const int p = 29 + (size_t(new char()) % 100);

pair<int, int> add(pair<int, int> a, pair<int, int> b) {
    return make_pair(mod1.add(a.first, b.first),
                     mod2.add(a.second, b.second));
}

pair<int, int> sub(pair<int, int> a, pair<int, int> b) {
    return make_pair(mod1.sub(a.first, b.first),
                     mod2.sub(a.second, b.second));
}

pair<int, int> mult(pair<int, int> a, pair<int, int> b) {
    return make_pair(mod1.mult(a.first, b.first),
                     mod2.mult(a.second, b.second));
}


int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // code here
    string s = input<string>();
    string t = input<string>();

    int n0 = std::count(ALL(s), '0');
    int n1 = std::count(ALL(s), '1');

    if (n0 < n1) {
        std::swap(n0, n1);
        for (auto& elem: s)
            elem = '0' + '1' - elem;
    }

    // n0 >= n1

    vector<pair<int, int>> hashes(SZ(t) + 1);
    for (int i = 0; i != SZ(t); ++i)
        hashes[i + 1] = add(mult(make_pair(p, p), hashes[i]), make_pair(t[i] - 'a' + 1, t[i] - 'a' + 1));

    vector<pair<int, int>> ppow(SZ(t) + 1);
    ppow[0] = make_pair(1, 1);
    for (int i = 0; i != SZ(t); ++i)
        ppow[i + 1] = mult(make_pair(p, p), ppow[i]);

    auto get_hash = [&](int l, int r) {
        return sub(hashes[r + 1], mult(hashes[l], ppow[r - l + 1]));
    };
    
    int ans = 0;
    for (int len0 = 1; len0 * n0 < SZ(t); ++len0)
        if ((SZ(t) - len0 * n0) % n1 == 0) {
            int len1 = (SZ(t) - len0 * n0) / n1;

            pair<int, int> h0 = make_pair(-1, -1);
            pair<int, int> h1 = make_pair(-1, -1);

            int ptr = 0;
            bool ok = true;
            for (char ch: s) {
                int cur_len = (ch == '0' ? len0 : len1);
                auto h = get_hash(ptr, ptr + cur_len - 1);

                auto& ref = (ch == '0' ? h0 : h1);

                if (ref.first == -1)
                    ref = h;
                else if (ref != h) {
                    ok = false;
                    break;
                }
                
                ptr += cur_len;
            }

            if (ok and h0 != h1)
                ++ans;
        }

    cout << ans << "\n";
    
    return 0;
}