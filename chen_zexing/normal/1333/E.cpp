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
int ans[505][505];
int main() {
    int T=1;
    //cin>>T;
    while(T--) {
        int n;
        cin >> n;
        if (n == 1 || n == 2) {
            puts("-1");
            continue;
        }
        int now = 1;
        for (int i = n; i >= 4; i--) {
            if (i % 2) for (int j = 1; j <= n; j++) ans[i][j] = now++;
            else for (int j = n; j >= 1; j--) ans[i][j] = now++;
        }
        for(int i=1;i<=n-3;i++)
        {
            if((n-i)%2) for(int j=3;j>=1;j--) ans[j][i]=now++;
            else for(int j=1;j<=3;j++) ans[j][i]=now++;
        }
        ans[1][n-2]=now++,ans[2][n-1]=now++,ans[2][n-2]=now++;
        ans[3][n-2]=now++,ans[2][n]=now++,ans[3][n]=now++;
        ans[1][n-1]=now++,ans[3][n-1]=now++,ans[1][n]=now++;
        for(int i=1;i<=n;i++,puts(""))
            for(int j=1;j<=n;j++)
                printf("%d ",ans[i][j]);
    }
    return 0;
}
//
/// 
//01
// 
//