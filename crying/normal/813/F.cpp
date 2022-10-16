#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#define next Cry_For_theMoon
#define il inline
#define pb(x) push_back(x)
#define is(x) insert(x)
#define sit set<int>::iterator
#define mapit map<int,int>::iterator
#define pi pair<int,int>
#define ppi pair<int,pi>
#define pp pair<pi,pi>
#define fr first
#define se second
#define vit vector<int>::iterator
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
const int MAXN=1e5+10;
int n,m,q,x[MAXN],y[MAXN];
int u[MAXN],v[MAXN],l[MAXN],r[MAXN];
int fa[MAXN],sz[MAXN],w[MAXN];
vector<pi>info[MAXN<<2];
map<pi,int>f;
struct Op{
    int from,to,presz;
};
vector<Op>hist;
pi Find(int x){
    int u=x,ret=0;
    while(fa[u]!=u){
        ret^=w[u];
        u=fa[u];
    }
    return mp(u,ret);
}
void Merge(int x,int y,int z){
    pi A=Find(x),B=Find(y);
    if(sz[A.fr]>sz[B.fr])swap(A,B);
    hist.pb(((Op){A.fr,B.fr,sz[A.fr]}));
    w[A.fr]=A.se^B.se^z;
    sz[B.fr]+=sz[A.fr];
    fa[A.fr]=B.fr;
}
void Back(){
    Op o=hist.back();hist.pop_back();
    int from=o.from,to=o.to,presz=o.presz;
    fa[from]=from;w[from]=0;
    sz[to]-=presz;
    sz[from]=presz;
}
void upd(int x,int l,int r,int ql,int qr,int u,int v){
    if(ql<=l && qr>=r){info[x].pb(mp(u,v));return;}
    int mid=(l+r)>>1;
    if(ql<=mid)upd(lc(x),l,mid,ql,qr,u,v);
    if(qr>mid)upd(rc(x),mid+1,r,ql,qr,u,v);
}
void qry(int x,int l,int r,int& flag){
    int cur=hist.size();
    for(auto e:info[x]){
        int u=e.fr,v=e.se;
        pi A=Find(u),B=Find(v);
        if(A.fr==B.fr){
            if(A.se^B.se!=1){
                flag=0;
            }
        }else{
            Merge(u,v,1);
            cur++;
        }
    }
    if(l==r){
        if(flag)printf("YES\n");
        else printf("NO\n");
        return;
    }
    int nowflag=flag,mid=(l+r)>>1;
    qry(lc(x),l,mid,flag);
    flag=nowflag;
    while(hist.size()!=cur)Back();
    qry(rc(x),mid+1,r,flag);

}
int main(){
    scanf("%d%d",&n,&q);
    rep(i,1,n)fa[i]=i,sz[i]=1;
    rep(i,1,q){
        scanf("%d%d",&x[i],&y[i]);
        if(f[mp(x[i],y[i])]!=0){
            r[f[mp(x[i],y[i])]]=i-1;
            f[mp(x[i],y[i])]=0;
        }
        else{
            m++;
            l[m]=i;r[m]=q;u[m]=x[i];v[m]=y[i];
            f[mp(x[i],y[i])]=m;
        }
    }
    rep(i,1,m)upd(1,1,q,l[i],r[i],u[i],v[i]);
    int flag=1;
    qry(1,1,q,flag);

    return 0;
}