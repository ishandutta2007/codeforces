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
const int MAXN=2e4+10,MAXM=1e6,INF=1e9;
int n,k,a[MAXN];
int f[MAXN],g[MAXN];
namespace Seg{
    struct Node{int lc,rc,idx;}tree[MAXM];
    struct Line{int k,b;}line[MAXN];
    int tot,linetot,cur,rt[MAXN];
    void clear(){tot=linetot=cur=0;}
    int newnode(){tot++;tree[tot].lc=tree[tot].rc=tree[tot].idx=0;return tot;}
    void addline(int k,int b){line[++linetot]={k,b};}
    int calc(int x,int idx){if(!idx)return INF;return 1ll*line[idx].k*x+line[idx].b;}
    int seg_upd(int p,int l,int r,int idx){
        int x=newnode();tree[x]=tree[p];
        if(!idx)return x;
        int mid=(l+r)>>1;
        if(calc(mid,idx)<calc(mid,tree[x].idx))swap(idx,tree[x].idx);
        if(l==r)return x;
        if(calc(l,idx)<calc(l,tree[x].idx))tree[x].lc=seg_upd(tree[x].lc,l,mid,idx);
        if(calc(r,idx)<calc(r,tree[x].idx))tree[x].rc=seg_upd(tree[x].rc,mid+1,r,idx);
        return x;
    }
    void seg_qry(int p,int l,int r,int pos,int& ans){
        if(!p)return;
        ans=min(ans,calc(pos,tree[p].idx));
        if(l==r)return;
        int mid=(l+r)>>1;
        if(pos<=mid)seg_qry(tree[p].lc,l,mid,pos,ans);
        else seg_qry(tree[p].rc,mid+1,r,pos,ans);
    }
    void add(int k,int b){
        addline(k,b);
        cur++;
        rt[cur]=seg_upd(rt[cur-1],1,n,linetot);
    }
    int qry(int x){
        int ans=INF;
        seg_qry(rt[cur],1,n,x,ans);
        return ans;
    }
    void back(){cur--;}
};
struct Convex{
    deque<array<int,2> >c;
    int check(array<int,2>a,array<int,2>b,array<int,2>c){return 1.00*(b[1]-a[1])*(c[0]-b[0])>1.00*(c[1]-b[1])*(b[0]-a[0]);}
    int check(array<int,2>a,array<int,2>b,int k){return 1.00*(b[1]-a[1])>1.0*(b[0]-a[0])*k;}
    void clear(){c.clear();}
    void push_back(array<int,2>p){
        while(c.size()>=2 && check(c[c.size()-2],c[c.size()-1],p))c.pop_back();
        c.push_back(p);
    }
    void push_front(array<int,2>p){
        while(c.size()>=2 && check(p,c[0],c[1]))c.pop_front();
        c.push_front(p);
    }
    int qry(int k){
        if(c.empty())return INF;
        int sz=c.size();
        int L=0,R=sz-2,ret=sz-1;
        while(L<=R){
            int mid=(L+R)>>1;
            if(check(c[mid],c[mid+1],k)){ret=mid;R=mid-1;}
            else{L=mid+1;}
        }
        return c[ret][1]-c[ret][0]*k;
    }
};
vector<Convex>convex;
void process_merge(){
    Seg::back();
    int sz=convex.size();
    if(sz<2)return;
    if(convex[sz-2].c.size()>convex[sz-1].c.size()){
        for(auto p:convex[sz-1].c)convex[sz-2].push_back(p);
    }else{
        reverse(convex[sz-2].c.begin(),convex[sz-2].c.end());
        for(auto p:convex[sz-2].c)convex[sz-1].push_front(p);
        swap(convex[sz-1],convex[sz-2]);
    }
    convex.pop_back();
}
void new_convex(array<int,2> p){
    Convex node;node.clear();node.push_back(p);
    convex.push_back(node);
}
int st[MAXN],top;
void calc(){
    Seg::clear();
    convex.clear();
    rep(i,0,n)f[i]=INF;
    top=0;
    rep(i,1,n){
        if(i>1){
            st[++top]=a[i];
            new_convex({i-1,g[i-1]});
            while(top>1 && st[top-1]<st[top]){
                process_merge();
                top--;st[top]=a[i];
            }
            Seg::add(a[i],convex.back().qry(a[i]));
        }
        f[i]=Seg::qry(i);
    }
    rep(i,0,n)g[i]=f[i];

}
int main(){
    cin>>n>>k;
    rep(i,1,n)cin>>a[i];
    int maxn=0;g[0]=INF;rep(i,1,n)maxn=max(maxn,a[i]),g[i]=maxn*i;
    rep(i,1,k-1)calc();
    cout<<g[n]<<endl;
    return 0;
}