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
    for (int t = input<int>(); t != 0; --t) {
        int h, g;
        cin >> h >> g;

        vector<int> a(1 << (h + 1));
        for (int i = 1; i <= (1 << h) - 1; ++i)
            cin >> a[i];

        vector<int> ans;
        vector<pair<int, int>> log;
        std::function<void(int, int)> fix = [&](int v, int dep) {
            if (dep == g + 1)
                return;

            while (true) {
                int cur = v;
                int curdep = dep;
                while (a[2 * cur] != 0 or a[2 * cur + 1] != 0) {
                    log.emplace_back(cur, a[cur]);
                
                    if (a[2 * cur] > a[2 * cur + 1]) {
                        a[cur] = a[2 * cur];                    
                        cur = 2 * cur;
                        ++curdep;
                    } else {
                        a[cur] = a[2 * cur + 1];                    
                        cur = 2 * cur + 1;
                        ++curdep;
                    }
                }

                log.emplace_back(cur, a[cur]);
                a[cur] = 0;
                
                if (curdep >= g + 1) {
                    ans.push_back(v);
                    log.clear();
                    continue;
                } else {
                    while (not log.empty()) {
                        a[log.back().first] = log.back().second;
                        log.pop_back();
                    }
                    
                    break;
                }
            }

            fix(2 * v, dep + 1);
            fix(2 * v + 1, dep + 1);
        };

        fix(1, 1);
        int64_t sum = 0;
        for (int i = 1; i < SZ(a); ++i)
             sum += a[i];

        cout << sum << "\n";
        
        for (int x: ans)
            cout << x << " ";

        cout << "\n";
    }

    return 0;
}