/*
 * @Author: BilyHurington
 * @Date: 2020-10-05 21:26:48
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-10-05 22:38:23
 */
#include<bits/stdc++.h>
using namespace std;
int T,n,sum[1000010];
int main(){
    for(int i=2;i<=1000000;i++){
        if(!sum[i]){
            for(int j=2*i;j<=1000000;j+=i) sum[j]=1;
        }
    }
    for(int i=1;i<=1000000;i++) sum[i]=1-sum[i],sum[i]+=sum[i-1];
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        printf("%d\n",sum[n]-sum[(int)sqrt(n)]+1);
    }
    return 0;
}