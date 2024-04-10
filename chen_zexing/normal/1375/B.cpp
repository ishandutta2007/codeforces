#include <stdio.h>
#include<iostream>
#include<string>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
#include <map>
using namespace std;
int a[305][305];
int main() {
    int T;
    cin>>T;
    while(T--)
    {
        int n,m,f=1;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++) {
                scanf("%d", &a[i][j]);
                if(a[i][j]>4) f=0;
            }
        if(a[1][1]>2||a[1][m]>2||a[n][1]>2||a[n][m]>2) f=0;
        for(int i=1;i<=n;i++) if(a[i][1]>3||a[i][m]>3) f=0;
        for(int i=1;i<=m;i++) if(a[1][i]>3||a[n][i]>3) f=0;
        if(f){
            printf("YES\n");
            for(int i=1;i<=n;i++,printf("\n"))
                for(int j=1;j<=m;j++)
                {
                    if(i==1&&j==1||i==1&&j==m||i==n&&j==1||i==n&&j==m) printf("2 ");
                    else if(i==1||j==1||i==n||j==m) printf("3 ");
                    else printf("4 ");
                }
        }
        else printf("NO\n");
    }
    return 0;
}