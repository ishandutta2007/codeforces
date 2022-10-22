/*
 * @Author: BilyHurington
 * @Date: 2020-02-13 19:20:46
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-04-26 23:08:26
 */
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<queue>
using namespace std;
int T,a,b,q,sum[50010];
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d %d %d",&a,&b,&q);
        int m=a*b;
        for(int i=1;i<m;i++){
            sum[i]=sum[i-1];
            if((i%a)%b!=(i%b)%a) sum[i]++;
        }
        long long l,r;
        while(q--){
            scanf("%lld %lld",&l,&r);
            if(l/m==r/m){printf("%d ",sum[r%m]-((l%m==0)?0:sum[l%m-1]));continue;}
            long long lx=l/m+1,rx=r/m-1,ans=0;
            ans+=(rx-lx+1)*sum[m-1];
            ans+=sum[m-1]-((l%m==0)?0:sum[l%m-1])+sum[r%m];
            printf("%lld ",ans);
        }
        printf("\n");
    }
    return 0;
}