//
//
//
//
//
//
//
#include<bits/stdc++.h>
using namespace std;

int n,m,sm,tot;
set<int> g[200005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;i++)g[i].insert(1<<25);
    while(m--){
        char typ,c;
        int u,v,k;
        cin>>typ;
        if(typ=='+'){
            cin>>u>>v>>c;
            g[u].insert((v<<5)+c-'a');
            sm+=g[v].find((u<<5)+c-'a')!=g[v].end();
            tot+=(*g[v].lower_bound(u<<5)>>5)==u;
        }else if(typ=='-'){
            int u,v;
            cin>>u>>v;
            c=*g[u].lower_bound(v<<5)&31;
            g[u].erase((v<<5)+c);
            sm-=g[v].find((u<<5)+c)!=g[v].end();
            tot-=(*g[v].lower_bound(u<<5)>>5)==u;
        }else{
            cin>>k;
            cout<<(sm||k&1&&tot?"YES\n":"NO\n");
        }
    }

    return 0;
}