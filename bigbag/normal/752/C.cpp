#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 222222, inf = 1011111111;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int n, num[333];
char s[max_n];
vector<pair<int, int> > ans;

int dist(pair<int, int> p1, pair<int, int> p2) {
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    num['U'] = 0;
    num['D'] = 1;
    num['L'] = 2;
    num['R'] = 3;
    scanf("%d%s", &n, s);
    ans.push_back(make_pair(0, 0));
    int x = 0, y = 0;
    for (int i = 0; i < n; ++i) {
        x += dx[num[s[i]]];
        y += dy[num[s[i]]];
        pair<int, int> p = make_pair(x, y);
        while (ans.size() >= 2 && dist(ans[ans.size() - 2], ans.back()) + dist(ans.back(), p) == dist(ans[ans.size() - 2], p)) {
            ans.pop_back();
        }
        ans.push_back(p);
    }
    printf("%d\n", ans.size() - 1);
    return 0;
}