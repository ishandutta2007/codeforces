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

const int inf = 1e9;

struct m2 {
    int a[2][2];

    m2() {
        a[0][0] = a[0][1] = a[1][0] = a[1][1] = -inf;
    }
};

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // code here
    int pw, k;
    cin >> pw >> k;

    int N = 1 << pw;
    
    vector<char> has(N, false);
    for (int i = 0; i < k; ++i)
        has[input<int>() - 1] = true;

    vector<m2> dp(N / 2);
    for (int i = 0; i < N / 2; i += 1) {
        int A = 2 * i;

        int score = has[A] or has[A + 1];

        dp[i].a[has[A]][has[A + 1]] = score;
        dp[i].a[has[A + 1]][has[A]] = score;
    }

    while (dp.size() != 1) {
        int Size = dp.size() / 2;
        vector<m2> new_dp(Size);

        for (int i = 0; i < Size; ++i) {
            auto& Res = new_dp[i];
            
            for (int x = 0; x < 2; ++x)
                for (int y = 0; y < 2; ++y)
                    for (int z = 0; z < 2; ++z)
                        for (int w = 0; w < 2; ++w) {
                            int s1 = dp[2 * i + 0].a[x][y];
                            int s2 = dp[2 * i + 1].a[z][w];
                            
                            if (s1 < 0 or s2 < 0)
                                continue;
                            
                            for (int msk = 0; msk < 8; ++msk) {
                                int wasB = y or w;
                                int winB = ((msk & 1) ? y : w);

                                int wasA = x or z;
                                int winA = ((msk & 2) ? x : z);
                                int losA = x + z - winA;

                                int wasC = winB or losA;
                                int winC = ((msk & 4) ? winB : losA);

                                Res.a[winA][winC] = max(Res.a[winA][winC],
                                                        s1 + s2 + wasA + wasB + wasC);
                            }
                        }
        }
        
        dp = std::move(new_dp);
    }

    int ans = -inf;
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            ans = max(ans, dp[0].a[i][j] + int(i or j));

    cout << ans << "\n";
    
    return 0;
}