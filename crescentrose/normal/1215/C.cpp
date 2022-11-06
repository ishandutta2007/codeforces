#include <ctime>
#include <cstdio>
#include <random>
#include <algorithm>
#include <ctime>
#include <iostream>
#include <queue>
#include <bitset>
#include <string>
#include <cstring>
#include <cmath>
#include <unordered_map>
using namespace std;
const int N = 1e6;
bool a[N] ,b[N];
int n;
vector<int> g[2];
vector<pair<int, int> > ans;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n ; i ++){
        char c;
        scanf(" %c", &c);
        a[i] = c - 'a';
    }
    for (int i = 1; i <= n ; i ++){
        char c;
        scanf(" %c", &c);
        b[i] = c - 'a';
    }
    for (int i = 1; i <= n ; i ++)
        if (a[i] != b[i])
            g[a[i]].push_back(i);
    if ((g[0].size() + g[1].size()) % 2) {
        printf("-1");
        return 0;
    }
    for (int j = 0; j < 2; j ++)
        for (int i = 0; i + 1 < g[j].size(); i += 2)
            ans.push_back(make_pair(g[j][i], g[j][i + 1]));
    if (g[0].size() & 1){
        int x = g[0][g[0].size() - 1], y = g[1][g[1].size() - 1];
        ans.push_back(make_pair(x, x));
        ans.push_back(make_pair(x, y));
    }
    printf("%d\n", ans.size());
    for (auto u:ans)
        printf("%d %d\n", u.first, u.second);
    return 0;
}