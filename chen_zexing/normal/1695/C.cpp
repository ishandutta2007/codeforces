#pragma GCC optimize(3)
#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <climits>
#include <algorithm>
#include <complex>
#include <string.h>
#include <iomanip>
#include <assert.h>
#include <random>
#include <bitset>
using namespace std;
int a[1005][1005],mn[1005][1005],mx[1005][1005];
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                scanf("%d",&a[i][j]);
        if((n+m-1)%2){
            puts("NO");
            continue;
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++){
                if(i==1&&j==1) mn[i][j]=mx[i][j]=a[i][j];
                else if(i==1) mn[i][j]=mn[i][j-1]+a[i][j],mx[i][j]=mx[i][j-1]+a[i][j];
                else if(j==1) mn[i][j]=mn[i-1][j]+a[i][j],mx[i][j]=mx[i-1][j]+a[i][j];
                else {
                    mn[i][j] = min(mn[i - 1][j] + a[i][j], mn[i][j - 1] + a[i][j]);
                    mx[i][j] = max(mx[i - 1][j] + a[i][j], mx[i][j - 1] + a[i][j]);
                }
            }
        puts(mx[n][m]>=0&&mn[n][m]<=0?"YES":"NO");
    }
    return 0;
}
//cf