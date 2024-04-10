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
#define SIZE 100010
int n,maxb,t,dn,b[SIZE],d[SIZE],dp[SIZE][2];
int get(int x){return lower_bound(d,d+dn,x)-d;}
vector<int>ker[SIZE],emp;
int main(){
    int i,j,k;
    scanf("%d%d%d%d",&k,&n,&maxb,&t);
    while(k--){
        for(i=0;i<n;i++){scanf("%d",&b[i]);d[i]=b[i];}
        sort(d,d+n);
        dn=unique(d,d+n)-d;
        if(t>=dn){
            printf("%d\n",dn);
            continue;
        }
        for(i=0;i<n;i++)b[i]=get(b[i]);
        for(i=0;i<dn;i++)ker[i]=emp;
        for(i=0;i<n;i++)ker[b[i]].pb(i);
        int ma=0;
        dp[0][0]=0;
        dp[0][1]=ker[0][0];
        for(i=1;i<dn;i++){
            j=ma-1;
            int idx=upper_bound(ker[i].begin(),ker[i].end(),dp[ma][1])-ker[i].begin();
            if(idx!=(int)ker[i].size()){
                ma++;
                dp[ma][0]=dp[ma-1][0];
                dp[ma][1]=ker[i][idx];
            }
            else{
                if(dp[ma][0]+1<t){
                    ma++;
                    dp[ma][0]=dp[ma-1][0]+1;
                    dp[ma][1]=ker[i][0];
                }
            }
            for(;j>=0;j--){
                idx=upper_bound(ker[i].begin(),ker[i].end(),dp[j][1])-ker[i].begin();
                if(idx!=(int)ker[i].size()){
                    if(make_pair(dp[j][0],ker[i][idx])<make_pair(dp[j+1][0],dp[j+1][1])){
                        dp[j+1][0]=dp[j][0];
                        dp[j+1][1]=ker[i][idx];
                    }
                }
                else{
                    if(dp[j][0]+1<t){
                        if(make_pair(dp[j][0]+1,ker[i][0])<make_pair(dp[j+1][0],dp[j+1][1])){
                            dp[j+1][0]=dp[j][0]+1;
                            dp[j+1][1]=ker[i][0];
                        }
                    }
                }
            }
            if(ker[i][0]<dp[0][1]){
                dp[0][1]=ker[i][0];
            }
        }
        printf("%d\n",ma+1);
    }
    return 0;
}