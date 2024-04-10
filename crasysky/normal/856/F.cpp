#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define ll long long
using namespace std;
const int N=1e6+6;
struct node{ ll x,y,my,y_x,myx,dy; int ls,rs,v; }t[N];
int cnt;
int newnode(ll x,ll y){
    t[++cnt]={x,y,y,y-x,y-x,0,0,0,rand()}; return cnt;
}
void up(int u){
    t[u].my=t[u].y,t[u].myx=t[u].y_x;
    if (t[u].ls)
        t[u].my=max(t[u].my,t[t[u].ls].my),t[u].myx=max(t[u].myx,t[t[u].ls].myx);
    if (t[u].rs)
        t[u].my=max(t[u].my,t[t[u].rs].my),t[u].myx=max(t[u].myx,t[t[u].rs].myx);
}
void upd(int u,ll dy){
    t[u].y+=dy,t[u].my+=dy,t[u].y_x+=dy,t[u].myx+=dy,t[u].dy+=dy;
}
void down(int u){
    if (t[u].dy)
        upd(t[u].ls,t[u].dy),upd(t[u].rs,t[u].dy),t[u].dy=0;
}
int merge(int x,int y){
    if (!x||!y) return x|y;
    if (t[x].v>t[y].v){
        down(x),t[x].rs=merge(t[x].rs,y),up(x);
        return x;
    }
    else{
        down(y),t[y].ls=merge(x,t[y].ls),up(y);
        return y;
    }
}
void split(int u,int &x,int &y,ll k){
    if (!u){ x=y=0; return; }
    down(u);
    if (t[u].x<=k)
        x=u,split(t[u].rs,t[x].rs,y,k),up(x);
    else
        y=u,split(t[u].ls,x,t[y].ls,k),up(y);
}
ll l1[N],r1[N],l2[N],r2[N],b[N]; int s[N];
#define id(x) lower_bound(b+1,b+1+k,x)-b
int main(){
    int n,m,k=0; ll c; scanf("%d%d%lld",&n,&m,&c);
    rep(i,1,n){
        scanf("%lld%lld",&l1[i],&r1[i]);
        b[++k]=l1[i],b[++k]=r1[i];
    }
    rep(i,1,m){
        scanf("%lld%lld",&l2[i],&r2[i]);
        b[++k]=l2[i],b[++k]=r2[i];
    }
    sort(b+1,b+1+k); k=unique(b+1,b+1+k)-b-1;
    rep(i,1,n) ++s[id(l1[i])],--s[id(r1[i])];
    rep(i,1,m) s[id(l2[i])]+=2,s[id(r2[i])]-=2;
    rep(i,1,k) s[i]+=s[i-1];
    ll dx=0; int rt=newnode(0,0);
    rep(i,1,k-1){
        ll l=b[i+1]-b[i];
        if (s[i]==1) dx+=l,upd(rt,l);
        if (s[i]==2) dx-=l;
        if (s[i]==3){
            upd(rt,l);
            int ls,rs;
            split(rt,ls,rt,-c-1-dx),split(rt,rt,rs,c-dx);
            if (ls) rt=merge(newnode(-c-dx,t[ls].my),rt);
            if (rs) rt=merge(rt,newnode(c-dx,t[rs].myx-dx+c));
            upd(rt,l);
            rt=merge(merge(ls,rt),rs);
        }
    }
    cout<<t[rt].my<<endl;
    return 0;
}