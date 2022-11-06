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

// (r, c)
int query(int x1, int y1, int x2, int y2) {
    ++x1, ++x2, ++y1, ++y2;
    cout << "? " << x1 << " " << y1 << " " << x2 << " " << y2 << std::endl;

    return input<int>();
}

bool has(int a, int b,
         int c, int d,
         int e, int f) {

    return (a == f) and ((b == d) or (d == c) or (c == e));
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // code here
    int n = input<int>();

    vector<vector<int>> field(n, vector<int>(n, -1));
    field[0][0] = 1;
    field[n - 1][n - 1] = 0;
    
    for (int i = 2; i < n; i += 2)
        field[0][i] = field[0][i - 2] xor (query(0, i - 2, 0, i) == 0);

    for (int i = 1; i < n; i += 2)
        field[1][i] = field[0][i - 1] xor (query(0, i - 1, 1, i) == 0);

    for (int i = 2; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            if (i == n - 1 and j == n - 1)
                continue;
            if ((i + j) % 2)
                continue;

            field[i][j] = field[i - 2][j] xor (query(i - 2, j, i, j) == 0);
        }

    field[0][1] = 0; // pseudo color
    field[2][1] = field[0][1] xor (query(0, 1, 2, 1) == 0);
    field[1][0] = field[2][1] xor (query(1, 0, 2, 1) == 0);

    for (int i = 0; i != n; ++i)
        for (int j = 0; j != n; ++j)
            if ((i + j) % 2) {
                if (field[i][j] != -1)
                    continue;

                if (i >= 2)
                    field[i][j] = field[i - 2][j] xor (query(i - 2, j, i, j) == 0);
                else {
                    assert(j >= 2);
                    field[i][j] = field[i][j - 2] xor (query(i, j - 2, i, j) == 0);
                }
            }

    int val = -1;
    auto help = [&]() {
        for (int i = 0; i + 2 != n; ++i)
            for (int j = 0; j + 1 != n; ++j) {
                int out[2];

                for (int x = 0; x != 2; ++x) {
                    int mat[3][2] = {{field[i+0][j], field[i+0][j + 1]},
                                     {field[i+1][j], field[i+1][j + 1]},
                                     {field[i+2][j], field[i+2][j + 1]}};

                    if (x)
                        for (int ii = i; ii <= i + 2; ++ii)
                            for (int jj = j; jj <= j + 1; ++jj)
                                if ((ii + jj) % 2)
                                    mat[ii - i][jj - j] ^= 1;
                    
                    out[x] = has(mat[0][0], mat[0][1],
                                 mat[1][0], mat[1][1],
                                 mat[2][0], mat[2][1]);
                }

                if (out[0] != out[1]) {
                    int r = query(i, j, i + 2, j + 1);
                    if (r == out[0])
                        val = 0;
                    else
                        val = 1;

                    return;
                }
            }
    };

    help();
    assert (val != -1);

    cout << "!" << std::endl;
    for (int i = 0; i != n; ++i, cout << "\n")
        for (int j = 0; j != n; ++j) {
            int r = field[i][j];
            
            if (val and (i + j) % 2)
                r ^= 1;

            cout << r;
        }

    cout.flush();
    
    return 0;
}