#include<bits/stdc++.h>
using namespace std;

int n,k,m,g[25][25],d[10005],e[105],a[25],f[1<<20];
bool b[10005];

void bfs(int s){
    memset(d,0x3f,sizeof(d));
    d[s]=0;
    queue<int> q;
    q.emplace(s);
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int i=0;i<m;i++){
            if(x>=e[i]&&d[x-e[i]]>d[x]+1){
                d[x-e[i]]=d[x]+1;
                q.emplace(x-e[i]);
            }
            if(x+e[i]<=n&&d[x+e[i]]>d[x]+1){
                d[x+e[i]]=d[x]+1;
                q.emplace(x+e[i]);
            }
        }
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k>>m;
    for(int i=0;i<k;i++){
        int x;
        cin>>x;
        b[x-1]^=1;
        b[x]^=1;
    }
    for(int i=0;i<m;i++)cin>>e[i];
    k=0;
    for(int i=0;i<=n;i++)if(b[i]){
        a[k++]=i;
    }
    for(int i=0;i<k;i++){
        bfs(a[i]);
        for(int j=0;j<k;j++)g[i][j]=d[a[j]];
    }
    memset(f,0x3f,sizeof(f));
    f[0]=0;
    for(int s=0;s<1<<k;s++)if(!__builtin_parity(s)){
        int i=0;while(s>>i&1)i++;
        for(int j=i+1;j<k;j++)if(s>>j&1^1){
            f[s|1<<i|1<<j]=min(f[s|1<<i|1<<j],f[s]+g[i][j]);
        }
    }
    if(f[(1<<k)-1]==0x3f3f3f3f)f[(1<<k)-1]=-1;
    cout<<f[(1<<k)-1];

    return 0;
}