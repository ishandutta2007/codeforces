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
const int MAXN=2e5+19,MAXQ=1e6+10;
int n,q,p[MAXN],pos[MAXN];
vector<int>d[MAXN];
int calc(int l,int r,int R,int maxn){
    int ret=0;
    for(auto u:d[maxn]){
        int v=maxn/u;if(u>=v)break;
        if(pos[u]>=l && pos[v]>=l && pos[u]<=R && pos[v]<=R)ret=max(ret,min(pos[u],pos[v]));
    }
    return min(ret,r);
}   
struct BIT{
    ll t[MAXN];
    void upd(int x,ll val){for(;x<=n;x+=lowbit(x))t[x]+=val;}
    ll qry(int x,ll s=0){for(;x;x-=lowbit(x))s+=t[x];return s;}
};
struct Seg{
    BIT t1,t2;
    void upd(int l,int r,ll val){
        t1.upd(l,val);t2.upd(l,l*val);
        t1.upd(r+1,-val);t2.upd(r+1,-(r+1)*val);
    }
    ll qry(int l){
        if(!l)return 0;
        return (l+1)*t1.qry(l)-t2.qry(l);
    }   
    ll qry(int l,int r){return qry(r)-qry(l-1);}
}F,S,T;
//F:
//S:
//T:
vector<array<int,2> >qry[MAXN];
ll ans[MAXQ];
void insert_interval(int l,int r,int t){
    //t[l,r]
    //printf("insert [%d,%d]\n",l,r);
    T.upd(l,r,1);S.upd(l,r,t);
}
void remove_interval(int l,int r,int s,int t){
    //ts[l,r]
    //printf("delete [%d,%d] with start at %d\n",l,r,s);
    F.upd(l,r,t-s);T.upd(l,r,-1);S.upd(l,r,-s);
}
ll ask_sum(int l,int r,int t){
    //ts[l]~s[r]
    ll ret=F.qry(l,r),cnt=T.qry(l,r),sum=S.qry(l,r);
    ret+=cnt*(t+1)-sum;
    return ret;
}
array<int,5>st[MAXN];
int idx[MAXN],top;
void solve(){
    rep(i,1,n){
        //printf("at times %d\n",i);
        int l=i,r=i;
        while(top && st[top][0]<p[i]){
            l=st[top][1];
            idx[st[top][0]]=0;
            if(st[top][3])remove_interval(st[top][1],st[top][3],st[top][4],i);
            top--;
        }
        int ret=calc(l,r,r,p[i]);
        st[++top]={p[i],l,r,ret,i};
        idx[p[i]]=top;
        if(ret)insert_interval(l,ret,i);
        rep(j,2,n)if(p[i]*j<=n){
            if(!idx[p[i]*j])continue;
            int u=idx[p[i]*j];
            //u
            if(st[u][3])remove_interval(st[u][1],st[u][3],st[u][4],i);
            int l=st[u][1],r=st[u][2],ret=calc(l,r,i,st[u][0]);
            st[u][3]=ret;st[u][4]=i;
            if(st[u][3])insert_interval(st[u][1],st[u][3],i);
        }else break;
        for(auto q:qry[i])ans[q[1]]=ask_sum(q[0],i,i);
    }
}
void Read(int& num){
    char ch;
    while((ch=getchar()) && !isdigit(ch));
    num=ch-'0';
    while((ch=getchar()) && isdigit(ch))num=num*10+ch-'0';
}
void Write(ll num){
    if(!num)return;
    Write(num/10);putchar('0'+num%10);
}
int main(){
    Read(n);Read(q);
    rep(i,1,n)rep(j,1,n)if(i*j<=n)d[i*j].push_back(i);else break;
    rep(i,1,n)Read(p[i]),pos[p[i]]=i;
    rep(i,1,q){
        int l,r;Read(l);Read(r);
        qry[r].push_back({l,i});
    }
    solve();
    rep(i,1,q){
        if(ans[i])Write(ans[i]);else putchar('0');putchar('\n');
    }
    return 0;
}