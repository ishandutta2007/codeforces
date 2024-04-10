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

struct node {
    node() {
        std::fill(go + 0, go + 10, (node*)NULL);
    }
    
    node* go[10];
    int subtree_sum = 0;
};

vector<vector<int>> kukarek(node* root, int k, int depth=0) {
    vector<vector<int>> res(depth + 1, vector<int>(k + 1, 0));

    for (int i = 0; i != 10; ++i)
        if (root->go[i]) {
            auto rs = kukarek(root->go[i], k, depth + 1);
            for (int a = 0; a <= k; ++a)
                rs[depth][a] = max(rs[depth][a], rs[depth + 1][a]);

            rs.pop_back();
            
            vector<vector<int>> newres(depth + 1, vector<int>(k + 1, 0));

            for (int dp = 0; dp <= depth; ++dp)
                for (int a = 0; a <= k; ++a)
                    for (int b = 0; a + b <= k; ++b)
                        newres[dp][a + b] = max(newres[dp][a + b], rs[dp][a] + res[dp][b]);

            res = std::move(newres);
        }

    for (int nextdep = depth - 1; nextdep >= 0; --nextdep)
        for (int a = 0; a < k; ++a)
            res[nextdep][a + 1] = max(res[nextdep][a + 1],
                                      res[depth][a] + (depth - nextdep) * root->subtree_sum);

    return res;
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // code here
    int n = input<int>();
    int k = input<int>();

    node* root = new node();

    int total = 0;
    for (int i = 0; i != n; ++i) {
        string s = input<string>();
        int val = input<int>();
        total += SZ(s) * val;
        
        node* cur = root;
        cur->subtree_sum += val;
        
        for (char ch: s) {
            if (not cur->go[ch - '0'])
                cur->go[ch - '0'] = new node();

            cur = cur->go[ch - '0'];
            cur->subtree_sum += val;
        }
    }

    auto rs = kukarek(root, k);
    cout << total - *std::max_element(ALL(rs[0])) << "\n";
    
    return 0;
}