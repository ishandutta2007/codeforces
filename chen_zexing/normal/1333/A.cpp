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
char ans[105][105];
int main() {
    int T=1;
    cin>>T;
    while(T--) {
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                ans[i][j]=(i+j)%2?'W':'B';
        if(n%2==0||m%2==0){
            if(ans[1][m]=='W') ans[1][m]='B';
            else ans[n][1]='B';
        }
        for(int i=1;i<=n;i++,puts(""))
            for(int j=1;j<=m;j++)
                printf("%c",ans[i][j]);
    }
    return 0;
}
//
/// 
//01
// 
//