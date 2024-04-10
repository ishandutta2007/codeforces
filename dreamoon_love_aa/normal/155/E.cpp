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
#define SIZE 1000001
int cs,a[SIZE],ra[10][SIZE],x[SIZE],y[SIZE],deg[SIZE];
long long cc[SIZE][10];
bool compare(int x,int y){
    if(deg[x]!=deg[y])return deg[x]<deg[y];
    for(int i=0;i<10;i++){
        if(cc[x][i]!=cc[y][i])return cc[x][i]<cc[y][i];
    }
    return 0;
}
bool equal(int x,int y){
    if(deg[x]!=deg[y])return 0;
    for(int i=0;i<10;i++)
        if(cc[x][i]!=cc[y][i])return 0;
    return 1;
}
bool equal2(int x,int y){
    if(deg[x]!=deg[y])return 0;
    for(int i=0;i<10;i++)
        if(cc[x][i]-ra[i][y]!=cc[y][i]-ra[i][x])return 0;
    return 1;
}
int main(){
    int i,j,n,m;
    long long an=0;
    srand(1014);
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)a[i]=i;
    for(i=0;i<10;i++){
        for(j=1;j<=n;j++)ra[i][j]=rand();
    }
    for(i=1;i<=n;i++)a[i]=i;
    for(i=1;i<=m;i++){
        scanf("%d%d",&x[i],&y[i]);
        deg[x[i]]++;
        deg[y[i]]++;
        for(j=0;j<10;j++){
            cc[x[i]][j]+=ra[j][y[i]];
            cc[y[i]][j]+=ra[j][x[i]];
        }
    }
    sort(a+1,a+1+n,compare);
    for(i=1;i<=n;i=j){
        for(j=i+1;j<=n&&equal(a[i],a[j]);j++);
        an+=(long long)(j-i)*(j-i-1)/2;
    }
    for(i=1;i<=m;i++){
        if(equal2(x[i],y[i]))an++;
    }
    cout<<an<<endl;
    return 0;
}