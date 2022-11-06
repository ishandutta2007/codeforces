// Dmitry [cdkrot.me] Sayutin (2021)

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
    string s = input<string>();

    vector<int> minlen(SZ(s) + 51);
    vector<int> maxlen(SZ(s) + 51);
    for (int n = 2; n <= SZ(s) + 50; ++n) {
        int A = n / 2;
        int B = n - n / 2;

        minlen[n] = minlen[A] + minlen[B] + min(A, B);
        maxlen[n] = maxlen[A] + maxlen[B] + A + B - 1;
    }

    vector<int> prefixSum0(SZ(s) + 1), prefixSum1(SZ(s) + 1);
    for (int i = 0; i < SZ(s); ++i) {
        prefixSum0[i + 1] = prefixSum0[i] + (s[i] == '0');
        prefixSum1[i + 1] = prefixSum1[i] + (s[i] == '1');
    }
    prefixSum0.push_back(TYPEMAX(int));
    prefixSum1.push_back(TYPEMAX(int));
    
    auto goFor = [&](int from, int A, int B) {
        int end = min(std::lower_bound(ALL(prefixSum0), prefixSum0[from] + A) - prefixSum0.begin(),
                      std::lower_bound(ALL(prefixSum1), prefixSum1[from] + B) - prefixSum1.begin());
        return end;
    };
    
    const int KEK = int(1e3);
    vector<vector<int>> endOf(KEK + 1, vector<int>(SZ(s), -1));

    for (int i = 0; i < SZ(s); ++i)
        endOf[1][i] = i;

    for (int len = 2; len <= KEK; ++len) {
        int A = len / 2;
        int B = len - A;

        for (int start = 0; start < SZ(s); ++start) {
            int e1 = endOf[A][start];
            int e2 = (e1 >= SZ(s) ? SZ(s) + 1 : endOf[B][e1]);
            
            if (e2 >= SZ(s))
                endOf[len][start] = SZ(s) + 1;
            else
                endOf[len][start] = goFor(e2, A, B);
        }
    }

    std::function<int(int, int)> findEndOf = [&](int len, int start) {
        if (len <= KEK)
            return endOf[len][start];

        int A = len / 2;
        int B = len - A;

        int e1 = findEndOf(A, start);
        int e2 = (e1 >= SZ(s) ? SZ(s) + 1 : findEndOf(B, e1));
        
        if (e2 >= SZ(s))
            return SZ(s) + 1;
        else
            return goFor(e2, A, B);
    };
    
    int n = 1;
    while (true) {
        if (maxlen[n] < SZ(s))
            ++n;
        
        int res = findEndOf(n, 0);
        if (res == SZ(s))
            break;
        else
            ++n;
    }
    
    if (1) {
        int ptr = 0;

        std::function<vector<int>(int, int)> go = [&](int start, int len) {
            if (len == 1)
                return vector<int> {start};

            auto left = go(start, len / 2);
            if (ptr > SZ(s))
                return vector<int> {};

            auto right = go(start + len / 2, len - (len / 2));
            if (ptr > SZ(s))
                return vector<int> {};

            int pleft = 0, pright = 0;
            vector<int> result;

            while (pleft != SZ(left) and pright != SZ(right) and ptr != SZ(s)) {
                if (s[ptr++] == '0')
                    result.push_back(left[pleft++]);
                else
                    result.push_back(right[pright++]);
            }

            if (pleft != SZ(left) and pright != SZ(right)) {
                ptr = int(1e9);
                return vector<int> {};
            }

            while (pleft != SZ(left))
                result.push_back(left[pleft++]);
            while (pright != SZ(right))
                result.push_back(right[pright++]);

            return result;
        };

        auto rs = go(0, n);
        if (ptr == SZ(s)) {
            vector<int> inv(SZ(rs), -1);
            for (int i = 0; i < SZ(rs); ++i)
                inv[rs[i]] = i;

            cout << SZ(inv) << "\n";
            for (int a: inv)
                cout << a + 1 << " ";
            cout << "\n";
            exit(0);
        }
    }

    assert(false);

    return 0;
}