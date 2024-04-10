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

void solve(int r, int c) {
    if (r == 1 and c == 1) {
        cout << "0\n";
        return;
    }

    bool was_swap = false;
    if (r > c)
        was_swap = 1, swap(r, c);
    
    vector<vector<int>> mat(r, vector<int>(c));
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j) {
            int A = i + 1;
            int B = r + 1 + j;

            mat[i][j] = A * B / std::__gcd(A, B);
        }

    for (int i = 0; i < r; ++i) {
        int G = 0;
        for (int j = 0; j < c; ++j)
            G = std::__gcd(G, mat[i][j]);

        assert(G == i + 1);
    }

    for (int j = 0; j < c; ++j) {
        int G = 0;
        for (int i = 0; i < r; ++i)
            G = std::__gcd(G, mat[i][j]);

        assert(G == r + 1 + j);
    }

    if (not was_swap)
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                cout << mat[i][j] << " \n"[j + 1 == c];
    else
        for (int i = 0; i < c; ++i)
            for (int j = 0; j < r; ++j)
                cout << mat[j][i] << " \n"[j + 1 == r];
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // code here
    if(0)
    for (int r = 1; r <= 50; ++r)
        for (int c = 1; c <= 50; ++c)
            solve(r, c);
    
    int r, c;
    cin >> r >> c;
    solve(r, c);

    return 0;
}