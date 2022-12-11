#include<bits/stdc++.h>
using namespace std;
unordered_map<int,int>M;
unordered_map<int,unordered_map<int,int> >bp;
set<int>s;
vector<int>v[333333];
int t,n,m;
int main(){
    cin>>t;
    while(t--){
        cin>>n>>m;
        long long ans=0;
        for(int i=1,x;i<=n;++i)cin>>x,M[x]++;
        for(auto x:M)s.insert(x.second),v[x.second].push_back(x.first);
        for(auto x:s) sort(v[x].begin(),v[x].end()),reverse(v[x].begin(),v[x].end());
        for(int i=1,a,b;i<=m;++i)scanf("%d%d",&a,&b),bp[a][b]=bp[b][a]=1;
        for(auto z:M){int x=z.first; for(auto c:s) for(int y:v[c])
            if(x!=y&&!bp[x][y]){ans=max(ans,(x+y)*1ll*(M[x]+M[y]));break;}}
        cout<<ans<<endl;
        for(auto x:s)v[x].clear();
        s.clear(); M.clear(); bp.clear();
    }
}