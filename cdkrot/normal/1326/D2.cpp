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

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // code here
    for (int tc = input<int>(); tc != 0; --tc) {
        string s;
        cin >> s;

        string ans, ans_l, ans_r;

        int dumb = 0;
        while (2 * dumb < SZ(s) and s[dumb] == s[SZ(s) - 1 - dumb])
            ++dumb;

        if (2 * dumb >= SZ(s))
            ans = s;
        else {
            for (int i = 0; i < dumb; ++i)
                ans_l.push_back(s[i]);
            for (int i = SZ(s) - dumb; i < SZ(s); ++i)
                ans_r.push_back(s[i]);

            s.erase(s.begin() + (SZ(s) - dumb), s.end());
            s.erase(s.begin(), s.begin() + dumb);
                
            for (int it = 0; it < 2; ++it) {
                if (it)
                    std::reverse(ALL(s));

                if (1) {
                    vector<int> mana(SZ(s));
                    int L = -1, R = -1;

                    int rem = -1;
                    for (int i = 0; i < SZ(s); ++i) {
                        if (i <= R)
                            mana[i] = min(R - i + 1, mana[R + L - i]);

                        while (i - mana[i] >= 0 and i + mana[i] < SZ(s) and s[i - mana[i]] == s[i + mana[i]])
                            ++mana[i];

                        if (i + mana[i] - 1 > R)
                            R = i + mana[i] - 1, L = i - mana[i] + 1;

                        if (mana[i] == i + 1) { // kek lol
                            rem = i;
                        }
                    }

                    string z;
                    for (int j = 0; j <= 2 * rem; ++j)
                        z += s[j];

                    if (SZ(z) > SZ(ans))
                        ans = z;
                }

                if (1) {
                    vector<int> mana(SZ(s));
                    int L = -1, R = -1;

                    int rem = -1;
                    for (int i = 1; i < SZ(s); ++i) {
                        if (s[i] != s[i - 1])
                            continue;

                        mana[i] = 1;
                        
                        if (i <= R)
                            mana[i] = min(R - i + 1, mana[R + L - i + 1]);

                        while (i - mana[i] - 1 >= 0 and i + mana[i] < SZ(s)
                               and s[i - mana[i] - 1] == s[i + mana[i]])
                            ++mana[i];

                        if (i + mana[i] - 1 > R)
                            R = i + mana[i] - 1, L = i - mana[i];

                        if (mana[i] == i) { // kek lol
                            rem = i;
                        }
                    }

                    if (rem != -1) {
                        string z;
                        for (int j = 0; j < 2 * rem; ++j)
                            z += s[j];
                        
                        if (SZ(z) > SZ(ans))
                            ans = z;
                    }
                }
            }
        }
        
        cout << ans_l + ans + ans_r << "\n";
    }
    
    return 0;
}