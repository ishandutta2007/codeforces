#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <ctime>
 
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
#include <set>

using namespace std;
 
typedef long long ll;

const int max_n = 1e3 + 100;


char a[max_n][max_n];
int n, m;
int g_pos[max_n], s_pos[max_n];

int main() {
   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);

    while (scanf("%d%d", &n, &m) != EOF) {
        for (int i = 0; i < n; ++i) {
            scanf("%s", a[i]);
        }
        
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (a[i][j] == 'G') {
                    g_pos[i] = j;
                } else if (a[i][j] == 'S') {
                    s_pos[i] = j;
                }
        bool my_win = true;
        for (int i = 0; i < n; ++i)
            if (s_pos[i] < g_pos[i]) {
                my_win = false;
                break;
            }
        if (!my_win) {
            printf("-1\n");
            continue;
        }
        
        vector<int> d;
        for (int i = 0; i < n; ++i)
            d.push_back(s_pos[i] - g_pos[i]);

        vector<int> us;
        us.assign(n, 0);
        int ans = 0;
        while (true) {
            int mn = -1;
            for (int j = 0; j < (int) d.size(); ++j)
                if (!us[j] && (mn == -1 || d[j] < d[mn])) {
                    mn = j;
                }
            if (mn == -1) break;
            us[mn] = 1;
            int k = d[mn];
            if (k == 0) continue;
            for (int j = 0; j < (int) d.size(); ++j)
                d[j] -= k;
            ++ans;
        }
        printf("%d\n", ans);
    }
    
    return 0;
}