#include<bits/stdc++.h>
using namespace std;
int n,m,a[123456],x[233333],y[233333],w[233333],loc[123456];
vector<int>v[123456];
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;++i) cin>>x[i]>>y[i]>>w[i];
    for(int b=0;b<30;++b){
        for(int i=1;i<=n;++i) loc[i]=0, v[i].clear();
        #define B(x) bit(x,b)
        for(int i=1;i<=m;++i) if(!(w[i]>>b&1)) loc[x[i]]=loc[y[i]]=1; else v[x[i]].push_back(y[i]),v[y[i]].push_back(x[i]);
        for(int i=1;i<=m;++i) if(x[i]==y[i]) a[x[i]]|=(w[i]>>b&1)<<b;
        for(int i=1;i<=n;++i) if(loc[i]) for(auto u:v[i]) a[u]|=1<<b;
        for(int i=1;i<=n;++i) if(!loc[i]&&!(a[i]>>b&1)) for(auto u:v[i]) a[u]|=1<<b;
    }
    for(int i=1;i<=n;++i) cout<<a[i]<<' ';
}