#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#define pb push_back
using namespace std;
#define SIZE 512
char s[SIZE][SIZE];
int d[SIZE][SIZE];
long long an;
int dx[5]={1,0,-1,0,0};
int dy[5]={0,1,0,-1,0};
void Go(int x,int y,int m,int k){
    int right=1,i,now=0;
    for(i=1;i<=m;i++){
        while(right<=m+2&&now<k){
            now+=d[y][right]-d[x][right];
            right++;
        }
        if(now>=k)an+=m+2-right;
        now-=d[y][i]-d[x][i];
    }
}
int main(){
    int i,j,kk,k,n,m;
    scanf("%d%d%d",&n,&m,&k);
    for(i=0;i<n;i++)scanf("%s",s[i]);
    for(i=1;i<n-1;i++)
        for(j=1;j<m-1;j++){
            for(kk=0;kk<5;kk++)
                if(s[i+dx[kk]][j+dy[kk]]=='0')break;
            if(kk==5)d[i][j]=1;
        }
    n--,n--,m--,m--;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)d[i][j]+=d[i-1][j];
    for(i=1;i<=n;i++)
        for(j=i;j<=n;j++)
            Go(i-1,j,m,k);
    cout<<an<<endl;
    return 0;
}