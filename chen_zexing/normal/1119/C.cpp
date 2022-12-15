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
int a[505][505],b[505][505];
int main() {
    int T=1;
    //cin>>T;
    while(T--){
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                scanf("%d",&a[i][j]);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                scanf("%d",&b[i][j]);
        int f=1;
        for(int i=1;i<n;i++) {
            for (int j = 1; j < m; j++) {
                if(a[i][j]!=b[i][j]){
                    a[i][j]^=1,a[i+1][j+1]^=1;
                    a[i+1][j]^=1,a[i][j+1]^=1;
                }
            }
            if(a[i][m]!=b[i][m]) f=0;
        }
        for(int i=1;i<=m;i++) if(a[n][i]!=b[n][i]) f=0;
        if(f) puts("Yes");
        else puts("No");
    }
    return 0;
}