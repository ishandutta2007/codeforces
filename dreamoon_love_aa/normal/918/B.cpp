#include<bits/stdc++.h>
void solve() {
    int n, m;
    scanf("%d%d", &n, &m);
    std::map<std::string,std::string> AA;
    for(int i = 0; i < n; ++i) {
        std::string s1, s2;
        std::cin >> s1 >> s2;
        AA[s2] = s1;
    }
    for(int i = 0; i < m; ++i) {
        std::string s1, s2;
        std::cin >> s1 >> s2;
        std::cout<< s1 << " " << s2 << " #" << AA[s2.substr(0, (int)s2.size() - 1)] << std::endl;
    }
}
int main() {
    solve();
    return 0;
}