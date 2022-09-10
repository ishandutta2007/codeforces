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
#define SIZE 5500
int a[SIZE];
struct data{
    int mi,num;
    data(int _mi=0,int _num=0){mi=_mi;num=_num;}
};
vector<data>dp[SIZE];
int low[SIZE];
int main(){
    int i,j,k,n;
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    for(i=1;i<=n;i++){
        int now=0;
        for(j=i;j>1;j--){
            now+=a[j];
            while(low[j-1]!=dp[j-1].size()&&now>=dp[j-1][low[j-1]].mi)low[j-1]++;
            if(low[j-1]){
                if(dp[i].size()==0||dp[j-1][low[j-1]-1].num+1>dp[i].back().num){
                    dp[i].pb(data(now,dp[j-1][low[j-1]-1].num+1));
                }
            }
        }
        if(dp[i].size()==0)dp[i].pb(data(now+a[1],1));
    }
    printf("%d\n",n-dp[n].back().num);
    return 0;
}