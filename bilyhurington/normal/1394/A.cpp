/*
 * @Author: BilyHurington
 * @Date: 2020-08-12 22:51:21
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-08-12 23:10:44
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
#define int long long
using namespace std;
int n,d,m;long long a[100010];
signed main(){
    scanf("%lld %lld %lld",&n,&d,&m);
    int cnt=0;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        if(a[i]<=m) cnt++;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) a[i]+=a[i-1];
    long long ans=0;
    for(int i=0;i<=n-cnt;i++){
        if(1ll*i*(d+1)<n-cnt||1ll*(i-1)*(d+1)+1>n) continue;
        // printf("%lld\n",i);
        // printf("%lld\n",a[n]-a[n-i]+a[cnt]-a[cnt-(n-min(n,i*(d+1)))]);
        ans=max(ans,a[n]-a[n-i]+a[cnt]-a[cnt-(n-max(1ll*(i-1)*(d+1)+1,n-cnt))]);
    }
    printf("%lld",ans);
    return 0;
}