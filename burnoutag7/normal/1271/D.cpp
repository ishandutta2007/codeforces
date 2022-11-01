#include<bits/stdc++.h>
using namespace std;

int n,m,k;
int a[5005],b[5005],c[5005],fr[5005];
vector<int> g[5005];
int def[5005],req[5005];
priority_queue<pair<int,int> > pq;
int ans;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>c[i];
        def[i]=i;
    }
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        def[v]=max(def[v],u);
    }
    for(int i=n;i>=1;i--){
        req[i]=max(a[i+1],req[i+1]-b[i+1]);cerr<<i<<' '<<req[i]<<endl;
    }
    int cur=k;
    for(int i=1;i<=n;i++){
        if(cur<a[i]){
            cout<<-1<<endl;
            return 0;
        }
        cur+=b[i];
    }
    cur=k;
    for(int i=1;i<=n;i++){
        cur+=b[i];
        fr[i]=cur-req[i];cur=req[i];
        pq.push(make_pair(c[i],i));
    }
    while(!pq.empty()){
        int val=pq.top().first,x=pq.top().second;
        pq.pop();
        int y=def[x];
        while(!fr[y]&&y>0)y--;
        if(y==0)continue;
        fr[y]--;
        ans+=val;
    }
    cout<<ans<<endl;

    return 0;
}