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
    int n = input<int>();

    map<int, vector<tuple<int, int, int>>> mp;
    for (int i = 0; i < n; ++i) {
        int x, y, z;
        cin >> x >> y >> z;

        mp[x].emplace_back(y, z, i);
    }

    vector<pair<int, int>> ans;

    // (y,z,i)
    tuple<int, int, int> brak = make_tuple(-1,-1,-1);

    for (auto elem: mp) {
        // y -> (z,i)
        map<int, vector<pair<int, int>>> m2;

        for (auto el: elem.second)
            m2[get<0>(el)].emplace_back(get<1>(el), get<2>(el));

        for (auto& el: m2) {
            sort(ALL(el.second));
        }
        
        if (get<2>(brak) != -1) {
            auto it = m2.lower_bound(get<0>(brak));
            if (it == m2.end())
                --it;

            auto itit = std::lower_bound(ALL(it->second), make_pair(get<1>(brak), -1));
            if (itit == it->second.end())
                --itit;

            ans.emplace_back(get<2>(brak), itit->second);
            it->second.erase(itit);

            if (it->second.size() == 0)
                m2.erase(it);

            brak = make_tuple(-1,-1,-1);
        }

        // kurwa
        for (auto& el: m2) {
            if (brak != make_tuple(-1, -1, -1)) {
                auto it = std::lower_bound(ALL(el.second), make_pair(get<1>(brak), -1));
                if (it == el.second.end())
                    --it;

                ans.emplace_back(get<2>(brak), it->second);
                el.second.erase(it);
                brak = make_tuple(-1,-1,-1);
            }

            if (el.second.size() % 2) {
                brak = make_tuple(el.first, el.second.back().first, el.second.back().second);
                el.second.pop_back();
            }

            for (int i = 0; i < SZ(el.second); i += 2)
                ans.emplace_back(el.second[i].second, el.second[i + 1].second);
        }
    }
    

    for (auto elem: ans)
        cout << elem.first + 1 << " " << elem.second + 1 << "\n";
        
    return 0;
}