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
using namespace std;
int n,m,a[505][505];
int main() {
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    int c=a[1][1];
    for(int i=2;i<=n;i++) c^=a[i][1];
    if(c){
        puts("TAK");
        for(int i=1;i<=n;i++) printf("1 ");
    }
    else{
        int f=0,x,y;
        for(int i=1;i<=n&&!f;i++)
            for(int j=1;j<=m;j++)
                if(a[i][j]!=a[i][1]){
                    f=1;
                    x=i,y=j;
                    break;
                }
        if(f){
            puts("TAK");
            for(int i=1;i<x;i++) printf("1 ");
            printf("%d ",y);
            for(int i=x+1;i<=n;i++) printf("1 ");
        }
        else puts("NIE");
    }
    return 0;
}