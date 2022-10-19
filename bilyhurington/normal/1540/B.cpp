/*
 * @Author: BilyHurington
 * @Date: 2021-06-25 23:35:11
 * @LastEditors: BilyHurington
 * @LastEditTime: 2021-06-26 00:36:46
 */
#include<bits/stdc++.h>
using namespace std;
int n,INV;
vector<int> T[210];
const int mod=1e9+7;
long long fast_pow(long long x,long long k){
    long long ans=1;
    while(k){
        if(k&1) ans=ans*x%mod;
        x=x*x%mod;k>>=1;
    }
    return ans;
}
long long Fac[210],Fac_inv[210];
void Pre_Fac(){
    Fac[0]=1;for(int i=1;i<=200;i++) Fac[i]=Fac[i-1]*i%mod;
    Fac_inv[200]=fast_pow(Fac[200],mod-2);
    for(int i=200;i>=1;i--) Fac_inv[i-1]=Fac_inv[i]*i%mod;
}
long long Binom(int x,int y){
    if(y<0||x<y) return 0;
    return Fac[x]*Fac_inv[y]%mod*Fac_inv[x-y]%mod;
}
long long Binom_INV(int x,int y){
    if(y<0||x<y) return 0;
    return Fac_inv[x]*Fac[y]%mod*Fac[x-y]%mod;
}
int siz[210],fa[210];
void dfs_siz(int x,int F){
    siz[x]=1;fa[x]=F;
    for(auto to:T[x]){
        if(to==F) continue;
        dfs_siz(to,x);
        siz[x]+=siz[to];
    }
}
int f[210][210];
long long ans;
vector<pair<int,int> > path;
void solve(int x,int y){
    // printf("solve: %d %d\n",x,y);
    dfs_siz(x,0);path.clear();
    for(int i=fa[y],j=y;i!=x;j=i,i=fa[i]){
        path.push_back(make_pair(i,siz[i]-siz[j]));
        // printf("%d %d\n",i,siz[i]-siz[j]);
    }
    ans=(ans+siz[y])%mod;
    // printf("+siz %d\n",siz[y]);
    for(int i=0;i<path.size();i++){
        int ly=i+1,lx=path.size()-i;
        // printf("%d +val %lld\n",path[i].first,1ll*path[i].second*Binom(path.size(),ly)%mod*Binom_INV(lx+ly,ly)%mod);
        ans+=1ll*path[i].second*f[lx][ly]%mod;
        ans%=mod;
    }
}
int main(){
    #ifdef LOCAL_TEST
    clock_t start=clock();
    #endif
    scanf("%d",&n);Pre_Fac();
    for(int i=1,x,y;i<n;i++){
        scanf("%d %d",&x,&y);
        T[x].push_back(y);
        T[y].push_back(x);
    }
    int INV2=fast_pow(2,mod-2);
    for(int i=1;i<=n;i++) f[i][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) f[i][j]=1ll*INV2*(f[i-1][j]+f[i][j-1])%mod;
    }
    // printf("%d %d\n",f[1][2],f[2][1]);
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            solve(i,j);
        }
    }
    printf("%lld",ans*fast_pow(n,mod-2)%mod);
    #ifdef LOCAL_TEST
    clock_t end=clock();cout<<endl;
    cout<<"The program costs "<<(double)(end-start)/CLOCKS_PER_SEC<<" seconds"<< endl;
    puts("");system("pause");
    #endif
    return 0;
}