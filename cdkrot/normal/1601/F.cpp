// Dmitry _kun_ Sayutin (2020)

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

const int mod = 998244353;

string toString(__int128_t num) {
    if (not num)
        return "0";
    string res;

    while (num) {
        res += char('0' + num % 10);
        num /= 10;
    }

    std::reverse(ALL(res));
    return res;
}

void solve(vector<int> variables, int base, __int128_t& ans) {
    int cur, until;

    vector<int> rem1, rem2;
    
    std::function<void(int)> brute = [&](int pos) {
        if (pos == until) {
            rem1.push_back(cur);
            return;
        }

        auto oldcur = cur;
        for (int t = 0; t < 10; ++t) {
            brute(pos + 1);
            cur += variables[pos];
            if (cur >= mod)
                cur -= mod;
        }
        cur = oldcur;
    };

    cur = base;
    until = SZ(variables) / 2;
    brute(0);

    rem2 = std::move(rem1);
    cur = 0;
    until = SZ(variables);
    brute(SZ(variables) / 2);

    sort(ALL(rem1));
    sort(ALL(rem2));

    int64_t totalrsum = 0;
    for (int b: rem2)
        totalrsum += b;

    int j = SZ(rem2) - 1;
    for (int a: rem1) {
        while (j >= 0 and a + rem2[j] >= mod)
            --j;

        ans += a * int64_t(SZ(rem2)) + totalrsum - (SZ(rem2) - 1 - j) * int64_t(mod);
    }
}

int64_t pw10[17];

int64_t count_with_prefix(const string& s, int64_t n, const string& n_str) {
    int64_t ans = 0;

    int64_t s_val = 0;
    for (char ch: s)
        s_val = 10 * s_val + ch - '0';
    
    for (int len = SZ(s); len <= SZ(n_str); ++len) {
        if (len < SZ(n_str))
            ans += pw10[len - SZ(s)];
        else {
            int t = strncmp(s.c_str(), n_str.c_str(), SZ(s));
            if (t < 0)
                ans += pw10[len - SZ(s)];
            else if (t == 0) {
                ans += (n + 1) - s_val * pw10[SZ(n_str) - SZ(s)];
            }
        }
    }
    return ans;
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // code here
    int64_t n = input<int64_t>();

    string n_str;
    for (int64_t t = n; t; t /= 10)
        n_str += char('0' + t % 10);
    std::reverse(ALL(n_str));

    pw10[0] = 1;
    for (int i = 1; i < 17; ++i)
        pw10[i] = 10 * pw10[i - 1];
    
    __int128_t ans = 0;
    for (int len = 1; len <= SZ(n_str); ++len) {
        int64_t cur = 0;
        string curst;
        
        for (int firstdiff = 0; firstdiff < SZ(n_str) and firstdiff < len; ++firstdiff) {
            if (firstdiff) {
                cur = 10 * cur + (n_str[firstdiff - 1] - '0');
                curst += n_str[firstdiff - 1];
            }

            for (int lastdig = 0; lastdig <= 9; ++lastdig) {
                if (firstdiff == 0 and lastdig == 0)
                    continue;
                if (lastdig == n_str[firstdiff] - '0')
                    continue;
                if (len == SZ(n_str) and lastdig > n_str[firstdiff] - '0')
                    continue;
                
                auto curp = 10 * cur + lastdig;
                auto curstp = curst + char('0' + lastdig);
                
                // n = 23456
                // cur = 21??

                // who's less than us?
                // 1*
                // 20*
                // 21[smaller]

                int64_t base = 0;
                string tmp = "";
                for (int pos = 0; pos < SZ(curstp); ++pos) {
                    for (char dig = (pos == 0 ? '1' : '0'); dig < curstp[pos]; ++dig)
                        base += count_with_prefix(tmp + dig, n, n_str);
                    
                    tmp += curstp[pos];
                }
                base += len - 1; // all strict prefixes are also smaller
                
                // (sum ai xi + base) mod p
                vector<int> variables;
                for (int pos = SZ(curstp); pos < len; ++pos) {
                    variables.push_back(count_with_prefix(tmp + '0', n, n_str) % mod);
                    tmp += '0';
                }

                base += 1; // 1-based, not 0-based
                base -= curp * pw10[len - SZ(curstp)];
                for (int t = 0; t < SZ(variables); ++t)
                    variables[SZ(variables) - 1 - t] -= pw10[t] % mod;

                base %= mod;
                if (base < 0)
                    base += mod;
                
                for (int& val: variables) {
                    val %= mod;
                    if (val < 0)
                        val += mod;
                }

                solve(variables, base, ans);
                
                // cout << curstp << " " << len << "\n";
                // cout << base << "\n";
                // for (int x: variables)
                //     cout << x << " ";
                // cout << "\n";
                // cout << "delta is " << (int64_t)solve(variables, base) << "\n";
                // cout << "=====\n";
            }
        }
    }

    // special case, numbers that are a prefix of N:
    int64_t cur = 0;
    string curst;

    for (int len = 1; len <= SZ(n_str); ++len) {
        curst += n_str[len - 1];
        cur = 10 * cur + (n_str[len - 1] - '0');

        int64_t val = 1; // 1-based
        string tmp = "";
        for (int pos = 0; pos < SZ(curst); ++pos) {
            for (char dig = (pos == 0 ? '1' : '0'); dig < curst[pos]; ++dig)
                val += count_with_prefix(tmp + dig, n, n_str);
            
            tmp += curst[pos];
        }
        val += len - 1; // all strict prefixes are also smaller
        
        val -= cur;
        val %= mod;
        if (val < 0)
            val += mod;

        //cerr << "for " << curst << " ans is " << val << "\n";
        
        ans += val;
    }
    
    ans %= (1000 * 1000 * 1000 + 7);
    cout << toString(ans) << "\n";

    return 0;
}