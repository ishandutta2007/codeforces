#include<bits/stdc++.h>
using namespace std;

int n,w[100005];
priority_queue<int> pq;
long long ans;
bool vis[100005];

void mian(){
    cin>>n;
    ans=0;
    for(int i=1;i<=n;i++){
        cin>>w[i];
        ans+=w[i];
        vis[i]=0;
    }
    for(int i=1;i<n;i++){
        static int x,y;
        cin>>x>>y;
        if(vis[x])pq.emplace(w[x]);
        if(vis[y])pq.emplace(w[y]);
        vis[x]=vis[y]=true;
    }
    cout<<ans<<' ';
    for(int i=2;i<=n-1;i++){
        ans+=pq.top();
        pq.pop();
        cout<<ans<<' ';
    }
    cout<<'\n';
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}