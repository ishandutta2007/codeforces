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
#define hash hassh
using namespace std;
int a[105][105];
int main() {
    int T;
    cin>>T;
    while(T--){
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                scanf("%d",&a[i][j]);
        for(int i=1;i<=n;i++,printf("\n"))
            for(int j=1;j<=m;j++){
                if((i+j)%2){
                    if(a[i][j]%2) printf("%d ",a[i][j]);
                    else printf("%d ",a[i][j]+1);
                }
                else{
                    if(a[i][j]%2) printf("%d ",a[i][j]+1);
                    else printf("%d ",a[i][j]);
                }
            }
    }
    return 0;
}