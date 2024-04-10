#include<bits/stdc++.h>
using namespace std;

int n,m,ds;
vector<int> g[100005];
bool aff[100005];
int dt[3][100005];

void dfs(int p,int x,int id,int d){
    dt[id][x]=d;
    for(int i=0;i<g[x].size();i++){
        int y=g[x][i];
        if(y!=p)dfs(x,y,id,d+1);
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>ds;
    int x,y,z;
    for(int i=1;i<=m;i++){
        int t;
        cin>>t;
        aff[t]=true;
    }
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        if(aff[i]){
            dfs(-1,i,0,0);
            x=i;
            break;
        }
    }
    y=x;
    for(int i=1;i<=n;i++){
        if(aff[i]&&dt[0][i]>dt[0][y]){
            y=i;
        }
    }
    dfs(-1,y,1,0);
    z=y;
    for(int i=1;i<=n;i++){
        if(aff[i]&&dt[1][i]>dt[1][z]){
            z=i;
        }
    }
    dfs(-1,z,2,0);

    int cnt=0;
    for(int i=1;i<=n;i++){
        if(dt[1][i]<=ds&&dt[2][i]<=ds)cnt++;
    }
    cout<<cnt<<endl;

    return 0;
}