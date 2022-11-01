#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
vector<int> g[200005],sl[200005],sr[200005],r;
ll ans;
int w[200005];

ll dfs(int x){
    ll res=w[x];
    for(int &y:g[x]){
        ll sv=dfs(y);
        if(sv>=0){
            res+=sv;
            sl[x].emplace_back(y);
        }else{
            sr[x].emplace_back(y);
        }
    }
    ans+=res;
    return res;
}

void print(int x){
    for(int &y:sl[x])print(y);
    cout<<x<<' ';
    for(int &y:sr[x])print(y);
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        int u;
        cin>>u;
        if(u!=-1)g[u].push_back(i);
        else r.emplace_back(i);
    }
    for(int &x:r)dfs(x);
    cout<<ans<<endl;
    for(int &x:r)print(x);

    return 0;
}