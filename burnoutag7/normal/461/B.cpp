#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod=1000000007;

vector<int> g[100005];
ll d[100005][2];
int c[100005];
int n;

void dfs(int x){
    if(g[x].size()==0){
        d[x][c[x]]=1;
        return;
    }
    ll t[2]={0ll,0ll};
    t[c[x]]=1;
    for(int i=0;i<g[x].size();i++){
        int y=g[x][i];
        dfs(y);
        t[1]=(t[1]*d[y][1]+t[1]*d[y][0]+t[0]*d[y][1])%mod;
        t[0]=(t[0]*d[y][1]+t[0]*d[y][0])%mod;
    }
    d[x][0]=(d[x][0]+t[0])%mod;
    d[x][1]=(d[x][1]+t[1])%mod;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<n;i++){
        int t;
        cin>>t;
        g[t].push_back(i);
    }
    for(int i=0;i<n;i++)cin>>c[i];
    dfs(0);
    cout<<d[0][1]<<endl;

    return 0;
}