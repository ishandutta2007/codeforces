#include <stdio.h>
#include<iostream>
#include<string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <map>
using namespace std;
int ans[505][505],row[505][505],col[505][505],bl[250005];
int main() {
    int T;
    cin>>T;
    while(T--){
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                scanf("%d",&row[i][j]),bl[row[i][j]]=i;
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++)
                scanf("%d",&col[i][j]);
        int x,y;
        for(int i=1;i<=n;i++)
        {
            int t=bl[col[1][i]];
            for(int j=1;j<=m;j++) printf("%d ",row[t][j]);
            printf("\n");
        }
    }
    return 0;
}