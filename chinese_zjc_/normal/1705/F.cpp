// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, tot, ans[2005], Xn[2005], Cn[2005], Xm[2005], Cm[2005];
void fill(std::vector<std::vector<int>> &X, const std::vector<std::vector<int>> &V, int x, int y)
{
    for (std::size_t i = 0; i != V.size(); ++i)
        for (std::size_t j = 0; j != V[i].size(); ++j)
            X[x + i][y + j] = V[i][j];
}
std::string sss;
int query(std::string s)
{
    int x = 0, y = 0;
    while (int(s.size()) > n)
    {
        y += s.back() == 'F';
        s.pop_back();
    }
    std::cout << s << std::endl;
    // for (std::size_t i = 0; i != s.size(); ++i)
    //     x += s[i] == sss[i];
    // std::cout << x << std::endl;
    std::cin >> x;
    if (x == n)
        exit(0);
    return x + y;
}
template <class T>
int query(T l, T r)
{
    std::string s(r - l, 'F');
    std::transform(l, r, s.begin(), [&](const int &X)
                   { return "FT"[X]; });
    return query(s);
}
template <class T>
int Query(T l, T r)
{
    int v = std::accumulate(l, r, 0);
    if (v == 0)
        return 0;
    return (v + query(l, r) - (r - l) + tot) >> 1;
}
void solve1(const std::vector<std::vector<int>> &A, const std::vector<int> &B, int *ans, int dep)
{
    if (dep == 0)
        return void(*ans = B.front() / A.front().front());
    std::vector<int> B_(Xn[dep - 1]);
    for (int i = 2 * Xm[dep - 1]; i != Xm[dep]; ++i)
        ans[i] = (B[i - 2 * Xm[dep - 1]] + B[i + Xn[dep - 1] - 2 * Xm[dep - 1]]) & 1;
    std::vector<std::vector<int>> A_;
    A_.resize(Xn[dep - 1], std::vector<int>(Xm[dep - 1]));
    for (int i = 0; i != Xn[dep - 1]; ++i)
        for (int j = 0; j != Xm[dep - 1]; ++j)
            A_[i][j] = A[i][j];
    for (int i = 0; i != Xn[dep - 1]; ++i)
        B_[i] = (B[i] + B[i + Xn[dep - 1]] - ans[Xm[dep - 1] * 2 + i]) >> 1;
    solve1(A_, B_, ans, dep - 1);
    for (int i = 0; i != Xn[dep - 1]; ++i)
        B_[i] = (B[i + Xn[dep - 1]] - B[i] + ans[Xm[dep - 1] * 2 + i]) >> 1;
    solve1(A_, B_, ans + Xm[dep - 1], dep - 1);
}
void solve(const std::vector<std::vector<int>> &A, const std::vector<int> &B, int *ans, int dep)
{
    // std::cout << dep << ' ' << ans - ::ans << std::endl;
    // for (int i = 0; i != Cn[dep]; ++i)
    // {
    //     for (int j = 0; j != Cm[dep]; ++j)
    //         std::cout << std::setw(4) << A[i][j];
    //     std::cout << std::setw(4) << B[i] << std::endl;
    // }
    if (dep == 0)
        return;
    std::vector<int> B_(Xn[dep - 1]);
    for (std::size_t i = 0; i != B_.size(); ++i)
        B_[i] = B[i] - B[i + B_.size()];
    std::vector<std::vector<int>> A_;
    A_.resize(Xn[dep - 1], std::vector<int>(Xm[dep - 1]));
    for (int i = 0; i != Xn[dep - 1]; ++i)
        for (int j = 0; j != Xm[dep - 1]; ++j)
            A_[i][j] = A[i][Cm[dep - 1] + j] - A[Cn[dep - 1] + i][Cm[dep - 1] + j];
    solve1(A_, B_, ans + Cm[dep - 1], dep - 1);
    A_.resize(Cn[dep - 1], std::vector<int>(Cm[dep - 1]));
    for (int i = 0; i != Cn[dep - 1]; ++i)
        for (int j = 0; j != Cm[dep - 1]; ++j)
            A_[i][j] = A[i][j];
    std::copy(B.begin(), B.begin() + Cn[dep - 1], B_.begin());
    for (int i = 0; i != Cn[dep - 1]; ++i)
        for (int j = Cm[dep - 1]; j != Cm[dep]; ++j)
            B_[i] -= ans[j] * A[i][j];
    solve(A_, B_, ans, dep - 1);
}
void work(const std::vector<std::vector<int>> &A,
          const std::vector<std::vector<int>> &B,
          const std::vector<std::vector<int>> &C,
          int dep)
{
    Xn[dep] = A.size();
    Cn[dep] = C.size();
    Xm[dep] = A.front().size();
    Cm[dep] = C.front().size();
    if (Cm[dep] >= n)
    {
        tot = query(std::string(Cm[dep], 'T'));
        // for (int i = 0; i != Cn[dep]; ++i)
        //     for (int j = 0; j != Cm[dep]; ++j)
        //         std::cout << C[i][j] << " \n"[j + 1 == Cm[dep]];
        // std::cout << "!" << std::endl;
        std::vector<int> res;
        for (std::size_t i = 0; i != C.size(); ++i)
            res.push_back(Query(C[i].begin(), C[i].end()));
        return solve(C, res, ans, dep);
    }
    std::vector<std::vector<int>>
        A_(Xn[dep] * 2, std::vector<int>(Xm[dep] * 2 + Xn[dep])),
        B_(Xn[dep] * 2, std::vector<int>(Xm[dep] * 2 + Xn[dep])),
        C_(Cn[dep] * 2, std::vector<int>(Cm[dep] + Xm[dep]));
    // std::cout << Cn[dep] << ' ' << Cm[dep] << std::endl;
    fill(A_, A, 0, 0);
    fill(A_, A, Xn[dep], 0);
    fill(A_, B, 0, Xm[dep]);
    fill(A_, A, Xn[dep], Xm[dep]);
    for (int i = 0; i != Xn[dep]; ++i)
        A_[i][Xm[dep] * 2 + i] = 1;

    fill(B_, B, 0, 0);
    fill(B_, B, Xn[dep], 0);
    fill(B_, A, 0, Xm[dep]);
    fill(B_, B, Xn[dep], Xm[dep]);

    fill(C_, C, 0, 0);
    fill(C_, C, Cn[dep], 0);
    fill(C_, A, 0, Cm[dep]);
    fill(C_, B, Cn[dep], Cm[dep]);

    work(A_, B_, C_, dep + 1);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    srand(time(nullptr));
    for (int i = 0; i != n; ++i)
        sss.push_back(rand() & 1 ? 'F' : 'T');
    // std::cout << sss << std::endl;
    work({{1}}, {{0}}, {{}}, 0);
    query(ans, ans + n);
    // for (int i = 0; i != n; ++i)
    //     std::cout << ans[i] << " \n"[i + 1 == n];
    return 0;
}