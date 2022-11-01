#include<bits/stdc++.h>
using namespace std;

int n,m,sz[100005],fa[100005],cnt[100005],f[100005],ans=1e9;

int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}

void unite(int x,int y){
    x=find(x);
    y=find(y);
    fa[x]=y;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    memset(f,0x3f,sizeof(f));
    f[0]=0;
    cin>>n>>m;
    iota(fa+1,fa+1+n,1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        unite(u,v);
    }
    for(int i=1;i<=n;i++)sz[find(i)]++;
    for(int i=1;i<=n;i++)if(find(i)==i)cnt[sz[i]]++;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=cnt[i];j*=2){
            cnt[i]-=j;
            for(int k=n-j*i;k>=0;k--)f[k+j*i]=min(f[k+j*i],f[k]+(bool)k+j-1);
        }
        if(cnt[i])for(int k=n-cnt[i]*i;k>=0;k--)f[k+cnt[i]*i]=min(f[k+cnt[i]*i],f[k]+(bool)k+cnt[i]-1);
    }
    for(int i=4;i<=n;i++){
        int x=i;
        bool luck=true;
        while(x){
            luck&=x%10==4||x%10==7;
            x/=10;
        }
        if(luck)ans=min(ans,f[i]);
    }
    if(ans==1e9)cout<<-1;
    else cout<<ans;

    return 0;
}