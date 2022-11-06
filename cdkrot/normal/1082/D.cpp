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

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // code here
    int n = input<int>();
    vector<int> a(n);
    input_seq(ALL(a));

    if (std::accumulate(ALL(a), 0) < 2 * n - 2) {
        cout << "NO\n";
        return 0;
    }

    while (std::count(ALL(a), 1) < 2) {
        *std::find_if(ALL(a), [&](int val){return val > 1;}) = 1;
    }
    
    cout << "YES " << n - std::count(ALL(a), 1) + 1 << "\n";

    cout << n - 1 << "\n";
    
    vector<int> seq(1 + n - std::count(ALL(a), 1) + 1, -1);
    int ptr = 1;
    
    vector<int> leaves;
    for (int i = 0; i < n; ++i)
        if (a[i] == 1) {
            if (seq[0] == -1)
                seq[0] = i;
            else if (seq.back() == -1)
                seq.back() = i;
            else
                leaves.push_back(i);
        } else {
            seq[ptr++] = i;
        }

    for (int i = 1; i < SZ(seq); ++i)
        cout << seq[i - 1] + 1 << " " << seq[i] + 1 << "\n";
    
    ptr = 0;
    int cur = 0;

    for (int lv: leaves) {
        while (cur == 0) {
            ptr += 1;
            cur = a[seq[ptr]] - 2;
        }

        cout << 1 + seq[ptr] << " " << 1 + lv << "\n";
        --cur;
    }
    
    return 0;
}