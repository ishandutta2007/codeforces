#include<bits/stdc++.h>
using namespace std;
const int MN = 1e3+5;
const int INF = 1e9;
char grid[MN][MN];
void solve () {
    int n,m; scanf ("%d %d",&n,&m);
    for (int i = 1; i <= n; i++) {
        scanf ("%s",grid[i]+1);
    }
    auto check = [&] (int k) {
        int ylb = INT_MIN, yub = INT_MAX, xlb = INT_MIN, xub = INT_MAX;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (grid[i][j] == 'B') {
                    array<int,2> a =  {i-k,j}, b = {i,j+k}, c = {i+k,j}, d = {i,j-k};
                    int mxX = INT_MIN, mnX = INT_MAX, mxY = INT_MIN, mnY = INT_MAX;
                    for (auto e : {a,b,c,d}) {
                        int x = e[0] - e[1];
                        int y = e[0] + e[1];
                        mxX = max(mxX,x); mnX = min(mnX,x);
                        mxY = max(mxY,y); mnY = min(mnY,y);
                    }
                    ylb = max(ylb, mnY);
                    yub = min(yub,mxY);
                    xlb = max(xlb,mnX);
                    xub = min(xub,mxX);
                }
            }
        }
        return array<int,4>{ylb,yub,xlb,xub};
    };
    int low = 0, high = n + m + 2, mid, ans = -1;
    while (low <= high) {
        mid = (low + high) / 2;
        auto a = check(mid);
        if (a[0] <= a[1] && a[2] <= a[3]) high = (ans = mid) - 1;
        else low = mid + 1;
    }
    array<int,4> a = check(ans);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int x = i - j, y = i + j;
            if (a[0] <= y && y <= a[1] && a[2] <= x && x <= a[3]) {
                printf ("%d %d\n",i,j);
                return;
            }
        }
    }
     a = check(ans + 1);
     for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int x = i - j, y = i + j;
            if (a[0] <= y && y <= a[1] && a[2] <= x && x <= a[3]) {
                printf ("%d %d\n",i,j);
                return;
            }
        }
    }
    assert(false);
}
int main () {
    int _t; scanf ("%d",&_t);
    while (_t--) solve();
    return 0;
}