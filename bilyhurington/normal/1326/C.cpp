/*
 * @Author: BilyHurington
 * @Date: 2020-02-13 19:20:46
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-03-19 23:19:07
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
int n,k,p[200010],id[200010];
bool tag[200010];
const int mod=998244353;
int main(){
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&p[i]),id[p[i]]=i;
    long long ans=0,ans_num=1;
    for(int i=n;i>n-k;i--){
        tag[id[i]]=1;
        ans+=i;
    }
    for(int i=1,j=0;i<=n+1;i++){
        if(tag[i]){
            if(j) ans_num*=i-j;
            ans_num%=mod;
            j=i;
        }
    }
    printf("%lld %lld\n",ans,ans_num);
}