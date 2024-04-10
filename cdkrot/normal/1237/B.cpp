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

    vector<int> in1(n), in2(n);
    input_seq(RALL(in1));
    input_seq(RALL(in2));
    
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        a[i] = in1[i] - 1;

    vector<int> where(n, -1);
    for (int i = 0; i < n; ++i)
        where[a[i]] = i;

    vector<int> jmp(n, -1);
    for (int i = 0; i < n; ++i) {
        jmp[where[in2[i] - 1]] = i;
    }

    int ans = 0;
    for (int i = n - 2; i >= 0; --i) {
        if (jmp[i] > jmp[i + 1])
            ++ans;
        
        jmp[i] = min(jmp[i], jmp[i + 1]);
    }

    cout << ans << "\n";

    return 0;
}