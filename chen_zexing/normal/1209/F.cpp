#include <stdio.h>
#include<iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <map>
#include <stack>
#include <unordered_set>
#define hash hassh
using namespace std;
vector <int> v[1000005][10];
vector <int> q[1000005];
int cnt,vis[1000005];
long long ans[1000005],mod=1000000007;
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        cnt = n;
        for (int i = 1, x, y; i <= m; i++) {
            scanf("%d%d", &x, &y);
            int temp = i;
            vector<int> t;
            while (temp) t.push_back(temp % 10), temp /= 10;
            reverse(t.begin(), t.end());
            int now = x;
            for (int j = 0; j < t.size(); j++) {
                if (j == t.size() - 1) v[now][t[j]].push_back(y);
                else v[now][t[j]].push_back(++cnt), now = cnt;
            }
            now = y;
            for (int j = 0; j < t.size(); j++) {
                if (j == t.size() - 1) v[now][t[j]].push_back(x);
                else v[now][t[j]].push_back(++cnt), now = cnt;
            }
        }
        q[0].push_back(1);
        vis[1] = 1;
        int x = 0;
        for (int i = 0; i <= x; i++) {
            for (int j = 0; j < 10; j++) {
                int fl = 0;
                for (int k = 0; k < q[i].size(); k++)
                    for (int l = 0; l < v[q[i][k]][j].size(); l++) {
                        int temp = v[q[i][k]][j][l];
                        if (vis[temp]) continue;
                        vis[temp] = 1, fl = 1;
                        ans[temp] = (ans[q[i][k]] * 10 + j) % mod;
                        q[x + 1].push_back(temp);
                    }
                if(fl) x++;
            }
        }
        for (int i = 2; i <= n; i++) printf("%lld\n", ans[i]);
    }
    return 0;
}
//
/// 
//01
// 
//
//dp