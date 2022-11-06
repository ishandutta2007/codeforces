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
    int k = input<int>();
    vector<vector<int>> lists(k);

    int64_t total = 0;

    vector<int64_t> delta(k, 0);

    vector<pair<int64_t, int>> where;
    
    for (int i = 0; i < k; ++i) {
        lists[i].resize(input<int>());
        input_seq(ALL(lists[i]));
        sort(ALL(lists[i]));

        for (int elem: lists[i]) {
            delta[i] += elem;
            where.emplace_back(elem, i);
        }

        total += delta[i];
    }
    
    if (total % k) {
        cout << "No\n";
        return 0;
    }

    sort(ALL(where));
    
    for (int i = 0; i < k; ++i)
        delta[i] = (total / k) - delta[i];

    vector<vector<int>> produced_mask;
    for (int bit = 0; bit < k; ++bit) {
        produced_mask.push_back(vector<int>(SZ(lists[bit]), -1));
        
        for (int i = 0; i < SZ(lists[bit]); ++i) {
            int num = lists[bit][i];
            
            int64_t the_num = num;
            int curbit = bit;
            int used = 0;

            bool fail = false;
            
            while ((used & (1 << curbit)) == 0) {
                used |= (1 << curbit);
                                
                int64_t target = the_num + delta[curbit];
                auto it = std::lower_bound(ALL(where), make_pair(target, -1));
                if (it == where.end() or it->first != target) {
                    fail = 1;
                    break;
                }

                int to = it->second;
                
                the_num = target;
                curbit = to;
            }

            if (fail or curbit != bit or the_num != num)
                continue;

            produced_mask[bit][i] = used;
        }
    }

    
    vector<char> used((1 << k), false);

    vector<int> ans_num(k, TYPEMIN(int));
    vector<int> ans_goto(k, -1);
    
    std::function<bool(int)> search = [&](int mask) {
        if (mask == 0)
            return true;

        if (used[mask])
            return false;

        used[mask] = 1;
        
        int bit = 0;
        for (; (mask & (1 << bit)) == 0; ++bit){}

        for (int i = 0; i < SZ(lists[bit]); ++i) {
            int used = produced_mask[bit][i];

            if (used != -1 and (mask | used) == mask and search(mask ^ used)) {
                int num = lists[bit][i];
                
                int64_t the_num = num;
                int curbit = bit;
                int used = 0;

                bool fail = false;
            
                while ((used & (1 << curbit)) == 0) {
                    used |= (1 << curbit);
                                
                    int64_t target = the_num + delta[curbit];
                    auto it = std::lower_bound(ALL(where), make_pair(target, -1));
                    if (it == where.end() or it->first != target) {
                        fail = 1;
                        break;
                    }

                    int to = it->second;

                    if (not (mask & (1 << to))) {
                        fail = 1;
                        break;
                    }

                    ans_num[to] = target;
                    ans_goto[to] = curbit;
                
                    the_num = target;
                    curbit = to;
                }

                if (fail or curbit != bit or the_num != num)
                    assert(false);
            
                return true;
            }
        }

        return false;
    };
    
    int rem = (1 << k) - 1;

    if (search(rem)) {
        cout << "Yes\n";
        for (int i = 0; i < k; ++i)
            cout << ans_num[i] << " " << ans_goto[i] + 1 << "\n";
    } else {
        cout << "No\n";
    }

    return 0;
}