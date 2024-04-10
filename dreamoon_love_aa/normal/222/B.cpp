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
#define SIZE 1024
int a[SIZE][SIZE],row[SIZE],col[SIZE];
int main(){
    int i,j,k,n,m;
    cin>>n>>m>>k;
    for(i=1;i<SIZE;i++)row[i]=col[i]=i;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)cin>>a[i][j];
    while(k--){
        char c[4];
        int x,y;
        scanf("%s%d%d",c,&x,&y);
        if(c[0]=='g')printf("%d\n",a[row[x]][col[y]]);
        else if(c[0]=='r')swap(row[x],row[y]);
        else swap(col[x],col[y]);
    }
    return 0;
}