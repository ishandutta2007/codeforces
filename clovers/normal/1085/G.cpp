#include<bits/stdc++.h>
using namespace std;
const int N=2005;
const int MOD=998244353;
int add(int x,int y){x+=y; return x>=MOD ? x-MOD : x;}
int sub(int x,int y){x-=y; return x<0 ? x+MOD : x;}
int mul(int x,int y){return 1ll*x*y%MOD;}
int dp[N][N];
int n,a[N][N],fac[N];

void init(int n,int k){
    fac[0]=1;
    for(int i=1;i<=n;i++) fac[i]=mul(fac[i-1],i);
    dp[1][0]=1; dp[1][1]=0;
    for(int i=2;i<=n;i++){
        dp[i][0]=fac[i];
        for(int j=1;j<=n;j++) dp[i][j]=sub(dp[i][j-1],dp[i-1][j-1]);
    }
}

struct BIT{
    int a[N];
    int lowbit(int x){return x&(-x);}
    void update(int pos,int add){
        for(int i=pos;i<=n;i+=lowbit(i)) a[i]+=add;
    }
    int query(int pos){
        int ret=0;
        for(int i=pos;i;i-=lowbit(i)) ret+=a[i];
        return ret;
    }
    void init(){
        for(int i=1;i<=n;i++) a[i]=0;
        for(int i=1;i<=n;i++) update(i,1);
    }
}tree1,tree2;

int ans=0,ti[N],vis[N];
int main(){
    scanf("%d",&n); init(n,n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) scanf("%d",&a[i][j]);
    }
    ti[0]=1;
    for(int i=1;i<=n;i++) ti[i]=mul(dp[n][n],ti[i-1]);
    tree1.init(); int tmp=0;
    for(int i=1;i<=n;i++){
        int pre=tree1.query(a[1][i]-1);
        tmp=add(tmp,mul(pre,fac[n-i]));
        tree1.update(a[1][i],-1);
    }
    ans=add(ans,mul(tmp,ti[n-1]));
    for(int i=2;i<=n;i++){
        tmp=0;
        tree1.init(); tree2.init();
        int k=n;
        for(int j=1;j<=n;j++) vis[j]=0;
        for(int j=1;j<=n;j++){
            int pre=tree1.query(a[i][j]-1);
            int pre2=tree2.query(a[i][j]-1);
            if(!vis[a[i-1][j]]&&a[i-1][j]<a[i][j]) pre--,pre2--;
            int pre1=pre-pre2;
            if(!vis[a[i-1][j]]) k--,vis[a[i-1][j]]=1,tree2.update(a[i-1][j],-1);
            if(pre2>0) tmp=add(tmp,mul(pre2,dp[n-j][k-1]));
            if(pre1>0) tmp=add(tmp,mul(pre1,dp[n-j][k]));
            if(!vis[a[i][j]]) k--,vis[a[i][j]]=1,tree2.update(a[i][j],-1);
            tree1.update(a[i][j],-1);
            //if(i==3) cout<<j<<":"<<pre1<<" "<<pre2<<" "<<k<<" "<<tmp<<endl;
        }
        //cout<<ans<<" "<<tmp<<endl;
        ans=add(ans,mul(tmp,ti[n-i]));
    }
    cout<<ans<<endl;
    return 0;
}