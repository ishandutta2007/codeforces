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

    vector<int> maxlen(SZ(s) + 51);
    for (int n = 2; n <= SZ(s) + 50; ++n) {
        int A = n / 2;
        int B = n - n / 2;

        maxlen[n] = maxlen[A] + maxlen[B] + A + B - 1;
    }

    int minN = 1;
    while (maxlen[minN] < SZ(s))
        ++minN;
    
    vector<int> prefixSum0(SZ(s) + 1);
    for (int i = 0; i < SZ(s); ++i) {
        prefixSum0[i + 1] = prefixSum0[i] + (s[i] == '0');
    }

    vector<int> minloc0 = {0}, minloc1 = {0};
    for (int i = 1; i <= SZ(s); ++i)
        if (s[i - 1] == '0')
            minloc0.push_back(i);
        else
            minloc1.push_back(i);
        
    auto goFor = [&](int from, int A, int B) {
        A += prefixSum0[from];
        B += from - prefixSum0[from];
        
        return min(A >= SZ(minloc0) ? SZ(s) + 1 : minloc0[A],
                   B >= SZ(minloc1) ? SZ(s) + 1 : minloc1[B]);
    };
    
    const int KEK = int(0.10e3);
    vector<vector<int>> endOf(KEK + 1);

    endOf[1] = vector<int>(SZ(s), -1);
    for (int i = 0; i < SZ(s); ++i)
        endOf[1][i] = i;

    for (int len = 2; len <= KEK; ++len) {
        int A = len / 2;
        int B = len - A;

        endOf[len] = vector<int>(SZ(s), -1);
        if (A <= minN) {
            endOf[A - 1].clear();
            endOf[A - 1].shrink_to_fit();
        }
        
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

    int n = minN;
    bool found = false;
    while (n <= KEK and not found) {
        if (findEndOf(n, 0) == SZ(s)) {
            found = 1;
        } else {
            n += 1;
        }
    }

    if (not found) {
        if (n % 2 == 1 and findEndOf(n, 0) == SZ(s)) {
            // ok
        } else {
            n += (n % 2);
        
            while (true) {
                // n % 2 == 0
            
                int A = n / 2;
                int B = n - A;

                int e1 = findEndOf(A, 0);
                if (e1 >= SZ(s)) {
                    n += 2;
                    continue;
                }
            
                int e2 = findEndOf(B, e1);
                if (e2 >= SZ(s)) {
                    n += 1;
                    B += 1;
                    e2 = findEndOf(B, e1);
                
                    if (e2 < SZ(s) and goFor(e2, A, B) == SZ(s)) {
                        break;
                    } else {
                        n += 1;
                        continue;
                    }
                }
        
                if (goFor(e2, A, B) == SZ(s))
                    break;
                else {
                    n += 1;
                    B += 1;
                    e2 = findEndOf(B, e1);
                
                    if (e2 < SZ(s) and goFor(e2, A, B) == SZ(s)) {
                        break;
                    } else {
                        n += 1;
                        continue;
                    }
                }
            }
        }
    }
    
    if (1) {
        int ptr = 0;

        std::function<vector<int>(int, int)> go = [&](int start, int len) {
            if (len == 1)
                return vector<int> {start};

            auto left = go(start, len / 2);
            auto right = go(start + len / 2, len - (len / 2));
            int pleft = 0, pright = 0;
            vector<int> result;

            while (pleft != SZ(left) and pright != SZ(right) and ptr != SZ(s)) {
                if (s[ptr++] == '0')
                    result.push_back(left[pleft++]);
                else
                    result.push_back(right[pright++]);
            }
            
            while (pleft != SZ(left))
                result.push_back(left[pleft++]);
            while (pright != SZ(right))
                result.push_back(right[pright++]);

            return result;
        };

        auto rs = go(0, n);

        vector<int> inv(SZ(rs), -1);
        for (int i = 0; i < SZ(rs); ++i)
            inv[rs[i]] = i;

        cout << SZ(inv) << "\n";
        for (int a: inv)
            cout << a + 1 << " ";
        cout << "\n";
        exit(0);
    }

    return 0;
}