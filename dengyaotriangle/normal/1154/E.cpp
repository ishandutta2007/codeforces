#include<bits/stdc++.h>

using namespace std;

const int maxn=200005;

int nxt[maxn],prv[maxn],val[maxn],idx[maxn];
int vis[maxn];
int n,k;

void del(int g,int q){
    vis[val[g]]=q;
    if(prv[g])nxt[prv[g]]=nxt[g];
    if(nxt[g])prv[nxt[g]]=prv[g];
}
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>val[i];
        idx[val[i]]=i;
        prv[i]=i-1;
        nxt[i]=i+1;
        if(nxt[i]>n) nxt[i]=0;
    }
    int cur=n;
    for(int i=0;;i=!i){
        for(;;cur--){
            if(!vis[cur]){
                break;
            }
        }
        if(cur==0) break;
        int f=idx[cur];
        for(int j=1;j<=k;j++){
            if(!f) break;
            f=prv[f];
            if(!f) break;
            del(f,i+1);
        }
        f=idx[cur];
        for(int j=1;j<=k;j++){
            if(!f) break;
            f=nxt[f];
            if(!f) break;
            del(f,i+1);
        }
        del(idx[cur],i+1);
    }
    for(int i=1;i<=n;i++){
        cout<<vis[val[i]];
    }
    return 0;
}