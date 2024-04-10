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

struct comp_t {
    vector<int> cycle;
    int size;
};

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // code here
    int n = input<int>();
    
    vector<int> go(n);

    vector<vector<int>> graph(n);
    vector<vector<int>> graph2(n);
    
    for (int i = 0; i != n; ++i) {
        go[i] = input<int>() - 1;
        graph[go[i]].push_back(i);

        graph2[go[i]].push_back(i);
        graph2[i].push_back(go[i]);
    }

    vector<int> compid(n, -1);
    vector<comp_t> comps;
    int szcomp = 0;
    
    std::function<void(int, int)> dfs = [&](int v, int c) {
        ++szcomp;
        compid[v] = c;
        for (int u: graph2[v])
            if (compid[u] == -1)
                dfs(u, c);
    };

    vector<char> is_cycle(n, false);
    vector<int> pos(n, -1);
    for (int i = 0; i != n; ++i)
        if (compid[i] == -1) {
            szcomp = 0;
            dfs(i, SZ(comps));

            comps.resize(SZ(comps) + 1);
            comps.back().size = szcomp;

            vector<int> arr;
            int p = i;
            for (; pos[p] == -1; p = go[p]) {
                pos[p] = SZ(arr);
                arr.push_back(p);
            }

            arr.erase(arr.begin(), arr.begin() + pos[p]);
            comps.back().cycle = arr;
            for (int elem: arr)
                is_cycle[elem] = 1;

            for (int i = 0; i != SZ(arr); ++i)
                pos[arr[i]] = i;
        }

    vector<vector<tuple<int, int, int>>> buckets(SZ(comps));
    vector<vector<pair<int, int>>> notcycle(n);

    int q = input<int>();
    vector<int> answers(q, -1);
    for (int i = 0; i != q; ++i) {
        int64_t m;
        int y;
        cin >> m >> y;
        --y;

        if (is_cycle[y]) {
            int clen = SZ(comps[compid[y]].cycle);
            int total = comps[compid[y]].size;
            
            if (m >= clen + total)
                m = total + (m - total) % clen;
            
            buckets[compid[y]].emplace_back(m, pos[y], i);
        } else
            notcycle[y].emplace_back(m, i);
    }

    auto merge = [&](vector<int>& a, vector<int>& b) {
        if (not (SZ(a) >= SZ(b)))
            swap(a, b);

        for (int p = 0; p != SZ(b); ++p)
            a[SZ(a) - SZ(b) + p] += b[p];
    };
    
    std::function<vector<int>(int, vector<pair<int,int>>&,int,int)> solve =
        [&](int v, vector<pair<int, int>>& go, int to, int len) {

        go.emplace_back(len, to);
        
        vector<int> res = {1};
        
        for (int u: graph[v]) {
            auto rs = solve(u, go, to, len + 1);

            rs.push_back(0);

            merge(res, rs);
        }

        for (auto elem: notcycle[v])
            if (elem.first < SZ(res))
                answers[elem.second] = res[SZ(res) - 1 - elem.first];
            else
                answers[elem.second] = 0;

        return res;
    };
    
    for (int c = 0; c != SZ(comps); ++c) {
        sort(ALL(buckets[c]));

        vector<pair<int, int>> go;

        for (int i = 0; i != SZ(comps[c].cycle); ++i)
            for (int u: graph[comps[c].cycle[i]])
                if (not is_cycle[u])
                    solve(u, go, i, 1);

        sort(ALL(go));
        int ptr = 0;
        
        vector<int> state(SZ(comps[c].cycle), 1);
        int curt = 0;
        int off = 0;
        
        for (auto quer: buckets[c]) {
            while (curt != get<0>(quer)) {
                ++curt;
                off -= 1;
                if (off < 0)
                    off += SZ(state);

                while (ptr < SZ(go) and go[ptr].first == curt) {
                    state[(go[ptr].second + off) % SZ(state)] += 1;
                    ++ptr;
                }
            }

            answers[get<2>(quer)] = state[(get<1>(quer) + off) % SZ(state)];
        }
    }

    for (int i = 0; i != q; ++i)
        cout << answers[i] << "\n";
    return 0;
}