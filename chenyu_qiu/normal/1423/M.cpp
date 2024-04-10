#include <bits/stdc++.h>
 
std::map<std::pair<int, int>, int> mem;
 
int Query(int p, int q) {
    if (mem.find(std::make_pair(p, q)) != mem.end()) return mem[std::make_pair(p, q)];
    std::cout << "? " << p << ' ' << q << std::endl;
    int val;
    std::cin >> val;
    return mem[std::make_pair(p, q)] = val;
}
int N, M, L[1000003];
 
std::vector<int> Reduce(std::vector<int> p1, std::vector<int> p2) {
    static int pre[1000003], suf[1000003];
    for (int i = 0; i < p2.size(); ++i) pre[i] = i - 1, suf[i] = i + 1;
    int Cnt = p2.size(), Pos = 0, rk = 0, hd = 0;
    auto Del = [&](int p) {
        (pre[p] != -1 ? suf[pre[p]] : hd = suf[p]) = suf[p];
        pre[suf[p]] = pre[p], --Cnt;
    };
    while (Cnt > p1.size()) {
        if (Query(p1[rk], p2[Pos]) <= Query(p1[rk], p2[suf[Pos]])) {
            if (rk == p1.size() - 1) {
                Del(suf[Pos]);
            } else {
                Pos = suf[Pos], ++rk;
            }
        } else {
            Pos = suf[Pos], Del(pre[Pos]);
            if (rk) Pos = pre[Pos], --rk;
        }
    }
    p1.clear();
    for (int i = hd; i != p2.size(); i = suf[i]) p1.push_back(p2[i]);
    return p1;
}
 
void Solve(std::vector<int> p1, std::vector<int> p2) {
    p2 = Reduce(p1, p2);
    std::vector<int> pp;
    if (p1.size() == 1) return void(L[p1[0]] = p2[0]);
    for (int i = 0; i < p1.size(); i += 2) pp.push_back(p1[i]);
    Solve(pp, p2);
    for (int i = 1; i < p1.size(); i += 2) {
        int pl = std::lower_bound(p2.begin(), p2.end(), L[p1[i - 1]]) - p2.begin(),
            pr = i + 1 < p1.size() ? std::lower_bound(p2.begin(), p2.end(), L[p1[i + 1]]) - p2.begin() : p2.size() - 1;
        L[p1[i]] = p2[pl];
        for (int j = pl + 1; j <= pr; ++j) {
            if (Query(p1[i], L[p1[i]]) > Query(p1[i], p2[j])) L[p1[i]] = p2[j];
        }
    }
}
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin >> N >> M;
    std::vector<int> pot1, pot2;
    for (int i = 1; i <= N; ++i) pot1.push_back(i);
    for (int i = 1; i <= M; ++i) pot2.push_back(i);
    Solve(pot1, pot2);
    int cAns = 1e9;
    for (int i = 1; i <= N; ++i) cAns = std::min(cAns, Query(i, L[i]));
    std::cout << "! " << cAns << std::endl;
    return 0;
}