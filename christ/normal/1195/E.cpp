#include<bits/stdc++.h>
using namespace std;
const int M = 3005 * 3005;
int g[M];
int grid[3005][3005];
int mx[3005][3005];
deque<int> dq;
int main () {
    int n,m,a,b,x,y,z; long long ans = 0;
    scanf ("%d %d %d %d",&n,&m,&a,&b);
    scanf ("%d %d %d %d",&g[0],&x,&y,&z);
    for (int i = 1; i < M; i++) g[i] = (g[i-1] * 1LL * x + y) % z;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            grid[i][j] = g[(i-1)*m+j-1];
        }
    }
    for (int i = 1; i <= n; i++) {
        dq.clear();
        for (int j = 1; j <= b; j++) {
            while (!dq.empty() && dq.back() > grid[i][j])
                dq.pop_back();
            dq.push_back(grid[i][j]);
        }
        mx[i][b] = dq.front();
        for (int j = b+1; j <= m; j++) {
            while (!dq.empty() && dq.back() > grid[i][j])
                dq.pop_back();
            dq.push_back(grid[i][j]);
            if (!dq.empty() && dq.front() == grid[i][j-b])
                dq.pop_front();
            mx[i][j] = dq.front();
        }
    }
    for (int j = b; j <= m; j++) {
        dq.clear();
        for (int i = 1; i <= a; i++) {
            while (!dq.empty() && dq.back() > mx[i][j])
                dq.pop_back();
            dq.push_back(mx[i][j]);
        }
        ans += dq.front();
        for (int i = a+1; i <= n; i++) {
            while (!dq.empty() && dq.back() > mx[i][j])
                dq.pop_back();
            dq.push_back(mx[i][j]);
            if (!dq.empty() && dq.front() == mx[i-a][j])
                dq.pop_front();
            ans += dq.front();
        }
    }
    printf ("%lld\n",ans);
    return 0;
}