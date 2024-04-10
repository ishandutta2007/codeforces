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
int n,m,a[MAXN],f[MAXN];
vector<int>occ[MAXN];
int ans[MAXN];
struct Qry{
    int l,r,idx;
    int operator<(const Qry& q2)const{
        return r<q2.r;
    }
}qry[MAXN];
struct BIT{
    int t[MAXN];
    void upd(int x,int val){
        for(;x<=n;x+=lowbit(x))t[x]+=val;
    }
    void upd(int l,int r,int val){
        upd(l,val);
        if(r+1<=n)upd(r+1,-val);
    }
    int qry(int x){
        int ret=0;
        for(;x;x-=lowbit(x))ret+=t[x];
        return ret;
    }
}t1,t2;
int main(){
    scanf("%d",&n);
    rep(i,1,n)scanf("%d",&a[i]);
    scanf("%d",&m);
    rep(i,1,m){
        scanf("%d%d",&qry[i].l,&qry[i].r);
        qry[i].idx=i;
    }
    sort(qry+1,qry+1+m);
    rep(i,1,1e5)occ[i].pb(0);
    int p=0;
    rep(i,1,n){
        int pre=occ[a[i]].back();
        occ[a[i]].pb(i);
        int idx=occ[a[i]].size()-1;
        //t1
        t1.upd(pre+1,i,1);
        //t2
        if(pre==0){
            f[i]=1;
            t2.upd(1,i,1);
        }else if(f[pre]==1){
            f[i]=2;
            t2.upd(pre+1,i,1);
        }else{
            assert(idx-f[pre]-1>=0);
            assert(idx>=2);
            t2.upd(occ[a[i]][idx-f[pre]-1]+1,pre,-1);
            int d=occ[a[i]][idx-1]-occ[a[i]][idx-2];
            if(i-pre==d){
                f[i]=f[pre]+1;
            }else{
                f[i]=2;
            }
            assert(idx-f[i]>=0);
            t2.upd(occ[a[i]][idx-f[i]]+1,i,1);
        }
        while(p+1<=m && qry[p+1].r==i){
            ans[qry[p+1].idx]=t1.qry(qry[p+1].l)+1;
            if(t2.qry(qry[p+1].l))ans[qry[p+1].idx]--;
            p++;
        }
    }
    rep(i,1,m){
        printf("%d\n",ans[i]);
    }
    return 0;
}