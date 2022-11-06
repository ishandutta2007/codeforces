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

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // code here
    for (int t = input<int>(); t; --t) {
        int n, a, b, da, db;
        cin >> n >> a >> b >> da >> db;
        --a, --b;

        vector<vector<int>> graph(n);
        for (int i = 1; i < n; ++i) {
            int x, y;
            cin >> x >> y;
            --x, --y;

            graph[x].push_back(y);
            graph[y].push_back(x);
        }

        if (not (db >= 2 * da + 1)) {
            cout << "Alice\n";
            continue;
        }


        auto calc_dist = [&](int from) {
            queue<int> q;
            q.push(from);

            vector<int> dist(n, -1);
            dist[from] = 0;

            while (not q.empty()) {
                int v = q.front();
                q.pop();

                for (int u: graph[v])
                    if (dist[u] == -1) {
                        dist[u] = dist[v] + 1;
                        q.push(u);
                    }
            }

            return dist;
        };

        auto dist = calc_dist(a);
        
        if (dist[b] <= da) {
            cout << "Alice\n";
            continue;
        }

        int v1 = std::max_element(ALL(dist)) - dist.begin();
        auto d2 = calc_dist(v1);

        if (*std::max_element(ALL(d2)) <= 2 * da) {
            cout << "Alice\n";
            continue;
        }
        
        cout << "Bob\n";
    }

    return 0;
}