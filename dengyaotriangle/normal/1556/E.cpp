#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=100005;

int n,q;
int a[maxn];
struct info{
    long long a,b,c;
};

info mrg(const info&a,const info&b){
    return info{min(a.a,a.c+b.a),max(a.b,a.c+b.b),a.c+b.c};
}

struct node{
    info v;
    node* c[2];
}pool[maxn<<2];int ps;
node* nwnode(){
    node* nw=pool+ps++;
    return nw;
}
node* bt(int l,int r){
    node* nw=nwnode();
    if(l!=r){
        nw->c[0]=bt(l,(l+r)/2);
        nw->c[1]=bt((l+r)/2+1,r);
        nw->v=mrg(nw->c[0]->v,nw->c[1]->v); 
    }else{
        nw->v=info{a[l],a[l],a[l]};
    }
    return nw;
}
info qry(node*rt,int cl,int cr,int l,int r){
    int cm=(cl+cr)/2;
    if(cl==l&&cr==r){
        return rt->v;
    }else if(r<=cm)return qry(rt->c[0],cl,cm,l,r);
    else if(l>cm)return qry(rt->c[1],cm+1,cr,l,r);
    else return mrg(qry(rt->c[0],cl,cm,l,cm),qry(rt->c[1],cm+1,cr,cm+1,r));
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        int b;cin>>b;a[i]=b-a[i];
    }
    node *rt=bt(1,n);
    while(q--){
        int l,r;
        cin>>l>>r;
        info x=qry(rt,1,n,l,r);
        if(x.c||x.a<0)cout<<"-1\n";
        else cout<<x.b<<'\n';
    }
    return 0;
}