#include<bits/stdc++.h>

using namespace std;

const int maxn=200005;
const int maxp=2750136;

int ntp[maxp];
int prm[maxp],prc;
int n;
int b[maxn<<1],c[maxn<<1];
int q[maxn<<1],m;
int nxt[maxn];
vector<int> adj[maxn];

void euler(int n){
    for(int i=2;i<=n;i++){
        if(!ntp[i]){
            prm[++prc]=i;
        }
        for(int j=1;i*prm[j]<=n;j++){
            ntp[i*prm[j]]=1;
            if(i%prm[j]==0) break;
        }
    }
}

int dfs(int u){
    int curs=0;
    for(int i=0;i<adj[u].size();i++){
        int v=adj[u][i];
        curs+=dfs(v);
    }
    for(int i=1;i<=c[u]-curs;i++){
        cout<<q[u]<<' ';
    }
    return c[u]-curs;
}
int main(){
    euler(maxp-1);
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n+n;i++){
        cin>>b[i];
    }    
    sort(b+1,b+1+n+n);
    m=1;
    q[1]=b[1];c[1]=1;
    for(int i=2;i<=n+n;i++){
        if(b[i]!=b[i-1]){
            q[++m]=b[i];
            c[m]=1;
        }else{
            c[m]++;
        }
    }
    for(int i=1;i<=m;i++){
        int des;
        if(ntp[q[i]]){
            for(int j=2;j*j<=q[i];j++){
                if(q[i]%j==0){
                    des=q[i]/j;
                    break;
                }
            }
        }else{
            des=prm[q[i]];
        }
        int cur=lower_bound(q+1,q+1+m,des)-q;
        if(q[cur]==des){
            nxt[i]=cur;
            adj[cur].push_back(i);
        }
    }
    for(int i=1;i<=m;i++){
        if(!nxt[i]){
            dfs(i);
        }
    }
    return 0;
}