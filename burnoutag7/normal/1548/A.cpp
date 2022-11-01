#include<bits/stdc++.h>
using namespace std;

int n,m,q,g[200005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    int ans=n;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        if(u>v)swap(u,v);
        g[u]++;
        if(g[u]==1)ans--;
    }
    cin>>q;
    while(q--){
        int typ,u,v;
        cin>>typ;
        if(typ==3){
            cout<<ans<<'\n';
        }else{
            cin>>u>>v;
            if(u>v)swap(u,v);
            if(typ==1){
                g[u]++;
                if(g[u]==1)ans--;
            }else{
                g[u]--;
                if(g[u]==0)ans++;
            }
        }
    }

    return 0;
}