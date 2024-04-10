#include<stdio.h>
#include<iostream>
using namespace std;
#define SIZE 100010
long long dp[SIZE],start[SIZE],end[SIZE],de[SIZE];
main(){
    int n,m,k,x,y,z,i,j,now;
    long long an=0;
    scanf("%d%d%d",&n,&m,&k);
    while(m--){
        scanf("%d%d%d",&x,&y,&z);
        dp[x]+=z;
        start[x]++;
        end[y]++;
        de[y+1]+=z+y-x;
    }
    now=0;
    for(i=1;i<=n;i++){
        dp[i]+=dp[i-1]+now-de[i];
        now+=start[i];
        now-=end[i];
    }
    while(k--){
        scanf("%d",&x);
        an+=dp[x];
    }
    cout<<an<<endl;
}