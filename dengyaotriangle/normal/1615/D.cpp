#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=400005;

int n,m;
tuple<int,int,int> edg[maxn];
int p[maxn];

int grt(int u){
    return p[u]==u?u:p[u]=grt(p[u]);
}
void mrg(int u,int v){
    u=grt(u),v=grt(v);
    if(u!=v)p[u]=v;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--){
        cin>>n>>m;
        
        for(int i=1;i<=n*2;i++)p[i]=i;
        for(int i=1;i<n;i++){
            int u,v,w;
            cin>>u>>v>>w;
            if(w>=0){
                int cw=__builtin_parity(w);
                for(int t=0;t<2;t++){
                    int u1=u+t*n,v1=v+(t^cw)*n;
                    mrg(u1,v1);
                }
            }
            edg[i]={u,v,w};
        }
        for(int i=1;i<=m;i++){
            int u,v,cw;
            cin>>u>>v>>cw;
            for(int t=0;t<2;t++){
                int u1=u+t*n,v1=v+(t^cw)*n;
                mrg(u1,v1);
            }
        }
        bool ok=1;
        for(int i=1;i<=n;i++){
            if(grt(i)==grt(i+n))ok=0;
            if(grt(i)!=grt(1)&&grt(i+n)!=grt(1)){
                mrg(i,1);
                mrg(i+n,1+n);
            }
        }
        if(!ok)cout<<"NO\n";
        else{
            cout<<"YES\n";
            for(int i=1;i<n;i++){
                int u,v,w;tie(u,v,w)=edg[i];
                cout<<u<<' '<<v<<' ';
                if(w>=0)cout<<w<<'\n';
                else{
                    bool z1=grt(u)==grt(1);
                    bool z2=grt(v)==grt(1);
                    cout<<(z1^z2)<<'\n';
                }
            }
        }
    }
    return 0;
}