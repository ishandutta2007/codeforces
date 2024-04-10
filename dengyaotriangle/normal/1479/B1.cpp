#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=100005;


struct node{
    node* c[2];
    int tg,mx;
}pool[maxn<<1];int ps;

void pu(node* rt){
    rt->mx=max(rt->c[0]->mx,rt->c[1]->mx);
}

void pd(node*rt){
    if(rt&&rt->tg){
        rt->mx+=rt->tg;
        if(rt->c[0])rt->c[0]->tg+=rt->tg;
        if(rt->c[1])rt->c[1]->tg+=rt->tg;
        rt->tg=0;
    }
}

node* bt(int l,int r){
    node* nw=pool+ps++;
    nw->mx=-1e9;
    if(l!=r){
        nw->c[0]=bt(l,(l+r)>>1);
        nw->c[1]=bt(((l+r)>>1)+1,r);
    }
    return nw;
}

void chg(node* rt,int cl,int cr,int l,int r,int v){
    int cm=(cl+cr)>>1;
    pd(rt);
    if(l==cl&&r==cr)rt->tg+=v,pd(rt);
    else if(r<=cm)pd(rt->c[1]),chg(rt->c[0],cl,cm,l,r,v),pu(rt);
    else if(l>cm)pd(rt->c[0]),chg(rt->c[1],cm+1,cr,l,r,v),pu(rt);
    else chg(rt->c[0],cl,cm,l,cm,v),chg(rt->c[1],cm+1,cr,cm+1,r,v),pu(rt);
}
void chg(node* rt,int cl,int cr,int i,int v){
    int cm=(cl+cr)>>1;
    pd(rt);
    if(cl==cr)rt->mx=max(rt->mx,v);
    else if(i<=cm)pd(rt->c[1]),chg(rt->c[0],cl,cm,i,v),pu(rt);
    else pd(rt->c[0]),chg(rt->c[1],cm+1,cr,i,v),pu(rt);
}

int qry(node* rt,int cl,int cr,int l,int r){
    int cm=(cl+cr)>>1;
    pd(rt);
    if(l==cl&&r==cr)return rt->mx;
    else if(r<=cm)return qry(rt->c[0],cl,cm,l,r);
    else if(l>cm)return qry(rt->c[1],cm+1,cr,l,r);
    else return max(qry(rt->c[0],cl,cm,l,cm),qry(rt->c[1],cm+1,cr,cm+1,r));
}
int main(){
    int n;
    cin>>n;
    node* rt=bt(0,n);
    vector<int> a(n+1);
    for(int i=1;i<=n;i++)cin>>a[i];
    chg(rt,0,n,0,1);
    for(int i=2;i<=n;i++){
        int w=max(qry(rt,0,n,0,a[i]-1),(a[i]==n?0:qry(rt,0,n,a[i]+1,n)))+1;
        w=max(w,qry(rt,0,n,a[i],a[i]));
        chg(rt,0,n,0,n,a[i-1]!=a[i]);
        chg(rt,0,n,a[i-1],w);
    }
    cout<<qry(rt,0,n,0,n);
    return 0;
}