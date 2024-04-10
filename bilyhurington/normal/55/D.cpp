/*
 * @Author: BilyHurington
 * @Date: 2021-07-01 14:21:32
 * @LastEditors: BilyHurington
 * @LastEditTime: 2021-07-01 14:41:29
 */
#include<bits/stdc++.h>
#ifdef LOCAL_TEST
#include<ctime>
#endif
using namespace std;
int T,tot,L[50],a[20],nxt[50][10];long long l,r;
unordered_map<long long,int> mp;
long long f[20][50][2520][2];
long long gcd(long long x,long long y){return y?gcd(y,x%y):x;}
long long dp(int x,int lcm,int md,int eq){
    if(!x){
        if(md%L[lcm]==0) return 1;
        return 0;
    }
    if(f[x][lcm][md][eq]!=-1) return f[x][lcm][md][eq]; 
    f[x][lcm][md][eq]=0;
    if(eq){
        for(int i=0;i<a[x];i++) f[x][lcm][md][eq]+=dp(x-1,nxt[lcm][i],(md*10+i)%2520,0);
        f[x][lcm][md][eq]+=dp(x-1,nxt[lcm][a[x]],(md*10+a[x])%2520,1);
    }else{
        for(int i=0;i<10;i++) f[x][lcm][md][eq]+=dp(x-1,nxt[lcm][i],(md*10+i)%2520,0);
    }
    return f[x][lcm][md][eq];
}
int main(){
    #ifdef LOCAL_TEST
    clock_t start=clock();
    #endif
    scanf("%d",&T);
    for(int i=0;i<(1<<8);i++){
        long long now=1;
        for(int j=2;j<10;j++){
            if((i>>(j-2))&1) now=now/gcd(now,j)*j; 
        }
        if(mp.find(now)==mp.end()) mp[now]=++tot,L[tot]=now;
    }
    for(int i=1;i<=tot;i++){
        nxt[i][0]=i;
        for(int j=1;j<10;j++){
            nxt[i][j]=mp[L[i]/gcd(L[i],j)*j];
        }
    }
    while(T--){
        scanf("%lld %lld",&l,&r);l--;
        long long ans=0;
        memset(a,0,sizeof(a));
        for(int i=1;l;a[i]=l%10,i++,l/=10);
        memset(f,-1,sizeof(f));
        ans-=dp(19,1,0,1);
        memset(a,0,sizeof(a));
        for(int i=1;r;a[i]=r%10,i++,r/=10);
        memset(f,-1,sizeof(f));
        ans+=dp(19,1,0,1);
        printf("%lld\n",ans);
    }
    #ifdef LOCAL_TEST
    clock_t end=clock();cout<<endl;
    cout<<"The program costs "<<(double)(end-start)/CLOCKS_PER_SEC<<" seconds"<< endl;
    puts("");system("pause");
    #endif
    return 0;
}