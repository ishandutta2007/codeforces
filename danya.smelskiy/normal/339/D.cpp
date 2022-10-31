#include <bits/stdc++.h>
using namespace std;

int n,m,sz;
long long  tree[500005];
int depth[500005];
long long x,y;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    n=(1<<n);
    sz=n;
    for (int i=1;i<=n;++i)
        cin>>tree[sz+i-1];
    for (int i=1;i<=n;++i)
        depth[sz+i-1]=1;
    for (int i=sz-1;i>0;--i)
        depth[i]=depth[i+i]+1;
    for (int i=sz-1;i>0;--i)
        if ((depth[i]&1)==0) tree[i]=(tree[i+i]|tree[i+i+1]);
        else tree[i]=(tree[i+i]^tree[i+i+1]);
    for (int i=1;i<=m;++i){
        cin>>x>>y;
        x+=sz-1;
        tree[x]=y;
        x>>=1;
        while (x) {
            if ((depth[x]&1)==0) tree[x]=(tree[x+x]|tree[x+x+1]);
            else tree[x]=(tree[x+x]^tree[x+x+1]);
            x>>=1;
        }
        cout<<tree[1]<<'\n';
    }
}