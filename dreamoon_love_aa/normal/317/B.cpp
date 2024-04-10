#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#define pb push_back
using namespace std;
#define MID 200
int a[400][400];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int main(){
    int i,j,k,n,now=0,t,flag=1;
    cin>>n;
    a[MID][MID]=n;
    while(flag){
        flag=0;
        for(i=0;i<400;i++)
            for(j=0;j<400;j++){
                if(a[i][j]>=4){
                    for(k=0;k<4;k++)a[i+dx[k]][j+dy[k]]+=a[i][j]>>2;
                    a[i][j]&=3;
                    flag=1;
                }
            }
    }
    scanf("%d",&n);
    while(n--){
        int x,y;
        scanf("%d%d",&x,&y);
        if(abs(x)>199||abs(y)>199)puts("0");
        else printf("%d\n",a[MID+x][MID+y]);
    }
    return 0;
}