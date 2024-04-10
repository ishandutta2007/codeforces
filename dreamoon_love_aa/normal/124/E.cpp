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
#define SIZE 256
#define MAX 1000000000000000020ll
int order[SIZE];
char an[SIZE];
vector<pair<int,int> >pri;
long long count(int n){
    int i,j;
    static long long dp[SIZE][SIZE];
    if(an[0]==')')return 0;
    dp[0][1]=1;
    for(i=1;i<n;i++){
        for(j=0;j<=i+1;j++){
            dp[i][j]=0;
            if(an[i]!=')'&&j)dp[i][j]+=dp[i-1][j-1];
            if(an[i]!='(')dp[i][j]+=dp[i-1][j+1];
            if(dp[i][j]>MAX)dp[i][j]=MAX;
        }
    }
    return dp[n-1][0];
}
int main(){
    int i,j,n,m,x;
    long long k;
    cin>>n>>m>>k;
    for(i=0;i<n+m;i++)order[i]=100000000;
    for(i=0;i<n;i++)
        for(j=0;j<m;j++){scanf("%d",&x);order[i+j]=min(order[i+j],x);}
    for(i=0;i<n+m-1;i++)pri.pb(make_pair(order[i],i));
    sort(pri.begin(),pri.end());
    for(i=0;i<pri.size();i++){
        x=pri[i].second;
        an[x]='(';
        long long tmp=count(n+m-1);
        if(tmp>=k)continue;
        else{
            k-=tmp;
            an[x]=')';
        }
    }
    for(i=0;i<n;i++,puts(""))
        for(j=0;j<m;j++)putchar(an[i+j]);
    return 0;
}