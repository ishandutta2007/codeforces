/*
 * @Author: BilyHurington
 * @Date: 2020-10-17 21:05:20
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-10-17 22:44:06
 */
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[100010],cnt[100010];
priority_queue<pair<long long,int> > Q;
long long calc(int len,int k){
    if(k>len) return calc(len,len);
    int A=len/k,n2=len%k,n1=k-n2;
    // printf("%lld %lld %lld\n",n1,n2,A);
    return 1ll*n1*A*A+1ll*n2*(A+1)*(A+1);
}
signed main(){
    // printf("%lld",calc(10,3));
    long long ans=0;
    scanf("%lld %lld",&n,&k);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]),cnt[i]=1,ans+=1ll*a[i]*a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        Q.push(make_pair(calc(a[i],1)-calc(a[i],2),i));
    }
    int C=k-n;
    while(Q.size()&&C--){
        int x=Q.top().second;
        ans-=Q.top().first;Q.pop();
        cnt[x]++;Q.push(make_pair(calc(a[x],cnt[x])-calc(a[x],cnt[x]+1),x));
    }
    printf("%lld",ans);
    return 0;
}