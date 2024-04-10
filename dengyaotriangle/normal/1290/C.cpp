#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=300005;

int n,m;
int p[maxn<<1],sz[maxn<<1];
pair<int,int> rs[maxn];
char x[maxn];

int grt(int u){return p[u]==u?u:p[u]=grt(p[u]);}
void mrg(int u,int v){u=grt(u);v=grt(v);sz[u]+=sz[v];p[v]=u;}

int gans(int x){
    return min(sz[grt(x)],sz[grt(x+m+1)]);
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>(x+1);
    for(int i=1;i<=m;i++){
        int t;cin>>t;
        while(t--){
            int x;cin>>x;
            if(rs[x].first)rs[x].second=i;
            else rs[x].first=i;
        }
    }
    for(int i=0;i<=m+m+1;i++)p[i]=i;
    for(int i=1;i<=m;i++)sz[i]=1;
    sz[0]=0x3fff3fff;
    int ans=0;
    for(int i=1;i<=n;i++){
        int u=rs[i].first,v=rs[i].second;
        if(grt(u)!=grt(v)&&grt(u)!=grt(v+m+1)){
            ans-=gans(u)+gans(v);
            if(x[i]=='0'){
                mrg(u,v+m+1);mrg(v,u+m+1);
            }else{
                mrg(u,v);mrg(u+m+1,v+m+1);
            }
            ans+=gans(u);
        }
        cout<<ans<<'\n';
    }
    return 0;
}