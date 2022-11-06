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

template <typename T>
T sorted(T a) {
    sort(ALL(a));
    return a;
}

template <typename A, typename B, typename C>
void set_difference_to(const A& a, const B& b, C& c) {
    std::set_difference(ALL(a), ALL(b), std::inserter(c, c.end()));
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // code here
    int n = input<int>();

    auto make = [&](const string& s, int l, int r) {
        vector<string> rs;

        for (int p1 = l; p1 <= r; ++p1)
            for (int p2 = p1; p2 <= r; ++p2) {
                rs.push_back(sorted(s.substr(p1, p2 - p1 + 1)));
            }

        sort(ALL(rs));
        return rs;
    };
    
    #ifndef TEST
    
    auto read = [&](int l, int r) {
        cout << "? " << l + 1 << " " << r + 1 << std::endl;

        vector<string> rs;
        int len = (r - l + 1);
        int cnt = (len) * (len + 1) / 2;

        for (int i = 0; i < cnt; ++i) {
            string s = input<string>();
            sort(ALL(s));
            rs.push_back(s);
        }

        sort(ALL(rs));
        return rs;
    };
#else
    int total_cnt = 0;
    int allowed = int(ceil(0.777 * (n + 1) * (n + 1)));
    string the_str = "baaba";
    the_str.clear();
    srand(time(nullptr));
    for (int i = 0; i < n; ++i)
        the_str += "abc"[rand() % 3];
    
    auto read = [&](int l, int r) {  
        auto rs = make(the_str, l, r);
        total_cnt += SZ(rs);
        
        return rs;
    };
#endif
    
    if (n == 1) { // thanks
        auto rs = read(0, 0)[0];
        cout << "! " << rs << std::endl;
    } else if (n <= 7) {
        int LEN = n;
        
        vector<string> set1 = read(0, LEN - 1);
        vector<string> set2 = read(1, LEN - 1);

        vector<string> res;
        set_difference_to(set1, set2, res);

        sort(ALL(res), [&](string a, string b) {
            return SZ(a) < SZ(b);
        });

        string ans;
        for (string s: res) {
            string x = ans;

            std::sort(ALL(x));
            std::sort(ALL(s));

            set_difference_to(s, x, ans);
        }
        
        cout << "! " << ans << std::endl;
    } else {
        int L1 = (n - 1) / 2;
        int L2 = n - 1 - L1;
        if (2 * L1 + 1 == n)
            --L1, ++L2;

        vector<string> full = read(0, n - 1);
        vector<string> left = read(0, L1 - 1);
        vector<string> right = read(n - L2, n - 1);

        vector<string> part_;
        set_difference_to(full, left, part_);

        vector<string> res;
        set_difference_to(part_, right, res);

        vector<vector<string>> lists(n + 1);
        for (auto elem: res)
            lists[SZ(elem)].push_back(elem);
        
        // monadic

        assert(SZ(lists[1]) == 1);
        vector<string> candidates = {lists[1][0]};

        int len = 1;
        for (; (len - 1) / 2 + 1 <= L1; len += 2) {
            vector<string> new_candidates;
            int k = (len - 1) / 2;
            
            for (string c: candidates) {
                auto lst = lists[k + 2];

                bool fl = false;
                for (int st = 0; st + (k + 2) <= len and not fl; ++st) {
                    int en = st + (k + 1);

                    auto it = std::find(ALL(lst), sorted(c.substr(st, en - st + 1)));
                    if (it == lst.end())
                        fl = true;
                    else
                        lst.erase(it);
                }

                if (fl)
                    continue;

                assert(SZ(lst) == 2);

                for (int i = 0; i < 2; ++i) {
                    string a, b;
                    set_difference_to(lst[i], sorted(c.substr(0, k + 1)), a);
                    set_difference_to(lst[i ^ 1], sorted(c.substr(k, k + 1)), b);

                    if (SZ(a) != 1 or SZ(b) != 1)
                        continue;

                    new_candidates.push_back(a + c + b);
                }
            }

            std::sort(ALL(new_candidates));
            new_candidates.resize(std::unique(ALL(new_candidates)) - new_candidates.begin());
            candidates = std::move(new_candidates);
        }

        string ans;
        for (auto elem: candidates) {
            auto r1 = make(elem, 0, L1 - 1);

            if (r1 != left)
                continue;

            auto r2 = make(elem, L1 + 1, SZ(elem) - 1);
            vector<string> tmp;
            set_difference_to(right, r2, tmp);

            if (SZ(tmp) + SZ(r2) != SZ(right))
                continue;

            auto r3 = make(elem, 0, SZ(elem) - 1);
            vector<string> tmp2;
            set_difference_to(full, r3, tmp2);

            if (SZ(tmp2) + SZ(r3) != SZ(full))
                continue;

            std::multiset<string> rem_full(tmp2.begin(), tmp2.end());

            string cur = elem;
            std::function<bool()> brute = [&]() {
                if (SZ(cur) == n) {
                    if (make(cur, 0, L1 - 1) != left)
                        return 0;
                    if (make(cur, n - L2, n - 1) != right)
                        return 0;

                    if (make(cur, 0, n - 1) != full)
                        return 0;

                    
                    ans = cur;
                    return 1;
                }

                for (char c = 'a'; c <= 'z'; ++c) {
                    cur += c;

                    auto it = rem_full.find(sorted(cur));
                    if (it != rem_full.end()) {
                        rem_full.erase(it);
                        
                        if (brute())
                            return 1;

                        rem_full.insert(sorted(cur));
                    }

                    cur.pop_back();
                }

                return 0;
            };

            if (brute())
                break;
        }            
        
        cout << "! " << ans << std::endl;

#ifdef TEST
        if (ans != the_str)
            cerr << ans << " " << the_str;
        assert(ans == the_str);
#endif
    }

#ifdef TEST
    if (total_cnt > allowed)
        cerr << "FAIL " << total_cnt << " " <<allowed << "\n";
    else
        cerr << "OK " << total_cnt << " " << allowed << "\n";
#endif
    return 0;
}