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
    for (int t = input<int>(); t !=0; --t){
        int n = input<int>();
        vector<int> a(n);
        input_seq(ALL(a));
        
        map<int, vector<int>> where;
        for (int i = 0; i < n; ++i)
            where[a[i]].push_back(i);


        set<pair<int, int>> on;
        int fuck = 0;
        
        int ans = SZ(where);
        auto L = where.rbegin();
        auto R = where.rbegin();
        int cur = 0;
        
        while (L != where.rend()) {
            for (auto elem: L->second) {
                auto it = on.emplace(make_pair(elem, a[elem])).first;

                if (it != on.begin() and std::prev(it)->second > a[elem])
                    ++fuck;
                if (std::next(it) != on.end() and a[elem] > std::next(it)->second)
                    ++fuck;
                
                if (it != on.begin() and std::next(it) != on.end() and std::prev(it)->second > std::next(it)->second)
                    --fuck;
            }
            
            ++L;
            ++cur;

            while (fuck and R != where.rend()) {
                for (auto elem: R->second) {
                    auto it = on.emplace(make_pair(elem, a[elem])).first;

                    if (it != on.begin() and std::prev(it)->second > a[elem])
                        --fuck;
                    if (std::next(it) != on.end() and a[elem] > std::next(it)->second)
                        --fuck;

                    if (it != on.begin() and std::next(it) != on.end() and std::prev(it)->second > std::next(it)->second)
                        ++fuck;

                    on.erase(it);
                }

                ++R;
                --cur;
            }

            if (not fuck)
                ans = min(ans, SZ(where) - cur);
        }

        cout << ans << "\n";
    }
    
    return 0;
}