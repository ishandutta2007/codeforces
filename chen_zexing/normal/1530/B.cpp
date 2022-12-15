#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <assert.h>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <time.h>
#include <map>
#include <stack>
#include <unordered_set>
#include <bitset>
#define hash hassh
using namespace std;
int ans[25][25];
int emp(int x,int y) {
    return ans[x - 1][y] == 0 && ans[x - 1][y - 1] == 0 && ans[x - 1][y + 1] == 0 && ans[x][y + 1] == 0 &&
           ans[x][y - 1] == 0 && ans[x + 1][y - 1] == 0 && ans[x + 1][y] == 0 && ans[x + 1][y + 1] == 0;
}
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n,m;
        cin>>n>>m;
        for(int i=0;i<=n+1;i++)
            for(int j=0;j<=m+1;j++)
                ans[i][j]=0;
        for(int i=1;i<=m;i++) if(emp(1,i)) ans[1][i]=1;
        for(int i=2;i<=n;i++) if(emp(i,m)) ans[i][m]=1;
        for(int i=m;i>=1;i--) if(emp(n,i)) ans[n][i]=1;
        for(int i=n;i>=1;i--) if(emp(i,1)) ans[i][1]=1;
        for(int i=1;i<=n;i++,puts(""))
            for(int j=1;j<=m;j++)
                printf("%d",ans[i][j]);
        puts("");
    }
    return 0;
}
//
/// 
//01
// 
//
//dp
//