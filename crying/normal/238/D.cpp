#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
using namespace std;
const int MAXN=1e5+10,INF=1e9;
int n,q;
struct Seg{
    int tag[MAXN<<2];
    void build(int x,int l,int r){
        tag[x]=INF;if(l==r)return;
        int mid=(l+r)>>1;build(lc(x),l,mid);build(rc(x),mid+1,r);
    }
    void upd(int x,int l,int r,int ql,int qr,int val){
        if(ql<=l&&qr>=r){tag[x]=min(tag[x],val);return;}
        int mid=(l+r)>>1;
        if(ql<=mid)upd(lc(x),l,mid,ql,qr,val);
        if(qr>mid)upd(rc(x),mid+1,r,ql,qr,val);
    }
    int qry(int x,int l,int r,int pos){
        int ret=tag[x];if(l==r)return ret;
        int mid=(l+r)>>1;
        if(pos<=mid)ret=min(ret,qry(lc(x),l,mid,pos));
        else ret=min(ret,qry(rc(x),mid+1,r,pos));
        return ret;
    }
    int operator[](const int idx){return qry(1,1,n+1,idx);}
    void operator()(const int l,const int r,const int val){if(l<=r)upd(1,1,n+1,l,r,val);}
}f,g;
char s[MAXN];
vector<array<int,10> >sum;
int pre[MAXN],nxt[MAXN],cur;
void Push(int val){
    auto tmp=sum.back();
    if(val!=-1)tmp[val]++;
    sum.push_back(tmp);
}
void Del(int x){
    int prev=pre[x],nxtv=nxt[x];
    if(prev)nxt[prev]=nxtv;
    if(nxtv)pre[nxtv]=prev;
    pre[x]=nxt[x]=0;
}
void Pre(){
    rep(i,1,n-1)nxt[i]=i+1;rep(i,2,n)pre[i]=i-1;
    int cur=0,u=1,d=1;
    while(1){
        cur++;
        f(u,u,cur);
        if(isdigit(s[u]))Push(s[u]-'0');
        else{
            if(s[u]=='>')d=1;
            else d=0;
            Push(-1);
        }
        int nxtp=0;
        if(d==1){
            if(!nxt[u]){
                f(n+1,n+1,cur+1);return;
            }
            else nxtp=nxt[u];
        }else{

            if(!pre[u]){
                if(!nxt[u]){
                    f(n+1,n+1,cur+1);return;
                }
                else d=1,nxtp=nxt[u],g(1,u,cur);
            }else{
                nxtp=pre[u];
                g(nxtp+1,u,cur);
            }
        }
        if(isdigit(s[u])){
            s[u]--;
            if(s[u]<'0')Del(u);
        }else{
            if(!isdigit(s[nxtp]))Del(u);
        }
        u=nxtp;
    }
}
int main(){
    cin>>n>>q>>(s+1);
    sum.push_back({0,0,0,0,0,0,0,0,0,0});
    f.build(1,1,n+1),g.build(1,1,n+1);
    Pre();
    rep(i,1,q){
        int l,r;cin>>l>>r;
        int s=f[l],t=min(f[r+1]-1,g[l]);
        auto tmp=sum[t];
        rep(j,0,9)tmp[j]-=sum[s-1][j];
        rep(j,0,9)cout<<tmp[j]<<' ';cout<<endl;
    }
    return 0;
}