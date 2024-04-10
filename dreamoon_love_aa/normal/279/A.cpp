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
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int dir,used[222][222];
int main(){
    int i,j,k,n,x,y;
    cin>>x>>y;
    if(x==0&&y==0)puts("0");
    else if(x==1&&y==0)puts("0");
    else{
        int xx=1,an=0;
        int yy=0;
        dir=0;
        used[112][111]=used[111][111]=1;
        while(xx!=x||yy!=y){
            if(!used[xx+dx[(dir+1)&3]+111][yy+dy[(dir+1)&3]+111]){
                dir=(dir+1)&3;
                an++;
            }
            xx+=dx[dir];
            yy+=dy[dir];
            used[xx+111][yy+111]=1;
        }
        printf("%d\n",an);
    }
    return 0;
}