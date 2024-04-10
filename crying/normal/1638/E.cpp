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
const int MAXN=1e6+10;
int n,q;
ll lazy[MAXN];
string op;
struct Seg{
    int c[MAXN<<2],ctag[MAXN<<2];
    ll tag[MAXN<<2],s[MAXN<<2];
    void pushup(int x){c[x]=(c[lc(x)]==c[rc(x)])?c[lc(x)]:0;}
    void add(int x,ll val){s[x]+=val;tag[x]+=val;}
    void pushdown(int x){if(ctag[x])c[lc(x)]=c[rc(x)]=ctag[lc(x)]=ctag[rc(x)]=ctag[x],ctag[x]=0;}
    void build(int x,int l,int r){
        c[x]=1;if(l==r)return;
        int mid=(l+r)>>1;build(lc(x),l,mid);build(rc(x),mid+1,r);
    }
    void upd(int x,int l,int r,int ql,int qr,int col){
        if(ql<=l&&qr>=r){
            if(c[x]){
                add(x,lazy[c[x]]);add(x,-lazy[col]);
                c[x]=ctag[x]=col;
                return;
            }
            int mid=(l+r)>>1;pushdown(x);
            upd(lc(x),l,mid,ql,qr,col);
            upd(rc(x),mid+1,r,ql,qr,col);
            pushup(x);
            return;
        }
        int mid=(l+r)>>1;pushdown(x);
        if(ql<=mid)upd(lc(x),l,mid,ql,qr,col);
        if(qr>mid)upd(rc(x),mid+1,r,ql,qr,col);
        pushup(x);
    }
    ll qry(int x,int l,int r,int pos){
        if(l==r)return s[x]+lazy[c[x]];
        int mid=(l+r)>>1;pushdown(x);
        ll ret=tag[x];if(pos<=mid)ret+=qry(lc(x),l,mid,pos);else ret+=qry(rc(x),mid+1,r,pos);
        pushup(x);return ret;
    }
}t;
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>q;
    t.build(1,1,n);
    rep(i,1,q){
        cin>>op;
        if(op=="Color"){
            int l,r,c;cin>>l>>r>>c;
            t.upd(1,1,n,l,r,c);
        }else if(op=="Add"){
            int c,x;cin>>c>>x;
            lazy[c]+=x;
        }else{
            int x;cin>>x;
            cout<<t.qry(1,1,n,x)<<endl;
        }
    }
    return 0;
}