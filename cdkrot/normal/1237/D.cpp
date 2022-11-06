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
    vector<int> a(n);
    input_seq(ALL(a));

    vector<int> aa = a;
    for (int elem: a)
        aa.push_back(elem);

    for (int elem: a)
        aa.push_back(elem);
    
    aa.push_back(int(-1e9));
    
    const int k = 25;
    vector<vector<int>> next(k, vector<int>(3 * n + 1, 3 * n));

    vector<int> stack = {3 * n};
    for (int i = 3 * n - 1; i >= 0; --i) {
        while (aa[i] <= aa[stack.back()])
            stack.pop_back();

        next[0][i] = stack.back();
        for (int j = 1; j < k; ++j)
            next[j][i] = next[j - 1][next[j - 1][i]];
        
        stack.push_back(i);
    }

    int r = 3 * n;
    vector<int> ans(n, -228);
    
    for (int l = 3 * n - 1; l >= 0; --l) {
        int nxt = l;

        int val = (aa[l] % 2 ? aa[l] / 2 : aa[l] / 2 - 1);
        
        for (int j = k - 1; j >= 0; --j)
            if (aa[next[j][nxt]] > val)
                nxt = next[j][nxt];
        
        nxt = next[0][nxt];
//        cerr << l << " " << nxt << " " << min(nxt, r) << "\n";
        r = min(r, nxt);

        if (l < n) {
            if (r == 3 * n)
                ans[l] = -1;
            else
                ans[l] = r - l;
            
        }
    }

    for (int i = 0; i < n; ++i)
        cout << ans[i] << " \n"[i + 1 ==n ];
    
    
    return 0;
}