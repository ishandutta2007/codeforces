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
int a[505][505];
int main() {
    int T=1;
    //cin>>T;
    while(T--) {
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                scanf("%d",&a[i][j]);
        for(int i=1;i<=n;i++,puts(""))
            for(int j=1;j<=m;j++){
                if((i+j)%2) printf("720720 ");
                else{
                    int t=1;
                    for(int k=1;k<=4;k++) t*=a[i][j];
                    printf("%d ",720720+t);
                }
            }
    }
    return 0;
}