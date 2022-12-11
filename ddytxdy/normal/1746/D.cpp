#include<bits/stdc++.h>
#define LL long long
#define pb push_back
using namespace std;
const int N=3e5+50;
const double eps=1e-12;
vector<LL>v[N];
int n,T,k,mn[N],mx[N],s[N],tp;LL ans1[N],ans2[N],st[N];
void dfs(int x){
    if(!v[x].size()){
        ans1[x]=1ll*s[x]*mn[x];
        ans2[x]=1ll*s[x]*mx[x];
        return;
    }
    int d1=mn[x]/v[x].size(),d2=(mx[x]+v[x].size()-1)/v[x].size();
    int ttp=tp;
    // vector<int>d;
    LL ans=0;
    for(int i=0;i<v[x].size();i++){
        int y=v[x][i];
        mn[y]=d1,mx[y]=d2;
        dfs(y);
        st[++tp]=ans1[y]-ans2[y];
        ans+=ans1[y];
    }
    sort(st+ttp+1,st+tp+1);
    ans1[x]=ans;
    for(int i=0;i<mn[x]%v[x].size();i++)
        ans1[x]-=st[i+ttp+1];
    ans2[x]=ans;
    if(mx[x]%v[x].size()){
        for(int i=0;i<mx[x]%v[x].size();i++)
            ans2[x]-=st[i+ttp+1];
    }
    else{
        for(int i=0;i<v[x].size();i++)
            ans2[x]-=st[i+ttp+1];
    }
    ans1[x]+=1ll*mn[x]*s[x];
    ans2[x]+=1ll*mx[x]*s[x];
    tp=ttp;
}
void solve(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        v[i].clear();
    for(int i=2,x;i<=n;i++)
        scanf("%d",&x),v[x].pb(i);
    for(int i=1;i<=n;i++)
        scanf("%d",&s[i]);
    mn[1]=mx[1]=k;
    dfs(1);
    printf("%lld\n",ans2[1]);
}
int main(){
    // freopen("in.txt","r",stdin);
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}