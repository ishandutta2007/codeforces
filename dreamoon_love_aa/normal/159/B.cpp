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
#define SIZE 1111
int a[SIZE][SIZE],b[SIZE][SIZE],aa[SIZE],bb[SIZE];
int main(){
    int i,j,k,n,m,an1=0,an2=0;
    cin>>n>>m;
    for(i=0;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        a[x][y]++;
        aa[y]++;
    }
    for(i=0;i<m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        b[x][y]++;
        bb[y]++;
    }
    for(i=1;i<=1000;i++)an1+=min(aa[i],bb[i]);
    for(i=1;i<=1000;i++)
        for(j=1;j<=1000;j++)an2+=min(a[i][j],b[i][j]);
    printf("%d %d\n",an1,an2);
    return 0;
}