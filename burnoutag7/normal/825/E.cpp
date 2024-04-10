#include<bits/stdc++.h>
using namespace std;

int n,m;
int deg[100005];
int ans[100005];
vector<int> rg[100005];
priority_queue<int> pq;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        deg[a]++;
        rg[b].push_back(a);
    }
    for(int i=1;i<=n;i++)if(!deg[i]){
        pq.push(i);
    }
    for(int i=n;i>=1;i--){
        int x=pq.top();pq.pop();
        for(int &y:rg[x]){
            deg[y]--;
            if(!deg[y])pq.push(y);
        }
        ans[x]=i;
    }
    for(int i=1;i<=n;i++)cout<<ans[i]<<' ';

    return 0;
}