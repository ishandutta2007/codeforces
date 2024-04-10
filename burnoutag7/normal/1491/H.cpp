#include<bits/stdc++.h>
using namespace std;

const int bs=350;

int n,q;
long long a[100005],f[100005],op[505],acc[505],sv[505];

inline int bid(int x){
    return (x+bs-1)/bs;
}

void update(){
    int l,r,x;
    cin>>l>>r>>x;
    if(bid(l)==bid(r)){
        for(int i=l;i<=min(bid(l)*bs,n);i++){
            a[i]=max(1ll,a[i]-x*(i<=r));
            if(bid(a[i])!=bid(i))f[i]=i;
            else f[i]=f[a[i]];
        }
    }else{
        for(int i=l;i<=min(bid(l)*bs,n);i++){
            a[i]=max(1ll,a[i]-x);
            if(bid(a[i])!=bid(i))f[i]=i;
            else f[i]=f[a[i]];
        }
        for(int i=bid(l)+1;i<bid(r);i++){
            op[i]+=x;
        }
        for(int i=bid(r)*bs-bs+1;i<=min(bid(r)*bs,n);i++){
            a[i]=max(1ll,a[i]-x*(i<=r));
            if(bid(a[i])!=bid(i))f[i]=i;
            else f[i]=f[a[i]];
        }
    }
}

void recalc(int id){
    if(sv[id])return;
    sv[id]=(acc[id]+=op[id])>=bs;
    for(int i=id*bs-bs+1;i<=min(id*bs,n);i++){
        a[i]=max(1ll,a[i]-op[id]);
        if(bid(a[i])!=bid(i))f[i]=i;
        else f[i]=f[a[i]];
    }
    op[id]=0;
}

void jump(){
    int u,v;
    cin>>u>>v;
    while(u!=v){
        if(u>v){
            if(op[bid(u)])recalc(bid(u));
            if(sv[bid(u)]){
                u=max(a[u]-op[bid(u)],1ll);
            }else{
                if(a[f[u]]>v)u=a[f[u]];
                else u=a[u];
            }
        }else{
            if(op[bid(v)])recalc(bid(v));
            if(sv[bid(v)]){
                v=max(a[v]-op[bid(v)],1ll);
            }else{
                if(a[f[v]]>u)v=a[f[v]];
                else v=a[v];
            }
        }
    }
    cout<<u<<'\n';
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>q;
    for(int i=2;i<=n;i++){
        cin>>a[i];
        if(bid(a[i])!=bid(i))f[i]=i;
        else f[i]=f[a[i]];
    }
    while(q--){
        int typ;
        cin>>typ;
        if(typ==1)update();
        else jump();
    }

    return 0;
}