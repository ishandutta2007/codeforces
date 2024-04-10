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
#define int ll
const ll MAXN=2e5+10,MAXM=MAXN*30,INF=1.5e12;
int n,q,c[MAXN],r[MAXN],pre;
int d[MAXN];
ll sum;
stack<array<ll,4> >st;
ll ans;
struct Node{int lc,rc;ll tag;};
struct Seg{
    int rt[MAXN],tot;
    Node tree[MAXM];
    ll a[MAXN];
    void copy(int from,int to){tree[to]=tree[from];}
    void build(ll* a){rep(i,1,n)(*this).a[i]=a[i];}
    int update(int x,int l,int r,int ql,int qr,ll val){
        int p=++tot;copy(x,p);
        if(ql<=l&&qr>=r){
            tree[p].tag+=val;
            return p;
        }
        int mid=(l+r)>>1;
        if(ql<=mid)tree[p].lc=update(tree[p].lc,l,mid,ql,qr,val);
        if(qr>mid)tree[p].rc=update(tree[p].rc,mid+1,r,ql,qr,val);
        return p;
    }
    ll qry(int x,int l,int r,int pos,ll sum){
        sum+=tree[x].tag;
        if(l==r)return sum+a[l];
        int mid=(l+r)>>1;
        if(pos<=mid)return qry(tree[x].lc,l,mid,pos,sum);
        else return qry(tree[x].rc,mid+1,r,pos,sum);
    }
}s1,s2;
bool cmp(int x,int y){return d[x]<d[y];}
void Pre(){
    static ll sum[MAXN],idx[MAXN];
    memset(sum,0,sizeof sum);
    s2.build(sum);
    rep(i,1,n)sum[i]=sum[i-1]+r[i];
    s1.build(sum);
    rep(i,1,n)d[i]=c[i]/r[i]+1,idx[i]=i;
    sort(idx+1,idx+1+n,cmp);sort(d+1,d+1+n);
    rep(i,1,n){
        s1.rt[i]=s1.update(s1.rt[i-1],1,n,idx[i],n,-r[idx[i]]);
        s2.rt[i]=s2.update(s2.rt[i-1],1,n,idx[i],n,c[idx[i]]);
    }
}
ll qry(ll t,int l){
    if(l==0)return 0;
    int idx=upper_bound(d+1,d+1+n,t)-d-1;
    return s2.qry(s2.rt[idx],1,n,l,0)+t*s1.qry(s1.rt[idx],1,n,l,0);
}
ll qry(ll t,int l,int r){return qry(t,r)-qry(t,l-1);}
void solve(int t,int h){
    sum+=t;
    while(st.size()){
        array<ll,4>tmp=st.top();st.pop();
        if(tmp[0]==tmp[1]){
            tmp[2]=min(tmp[2]+(sum-tmp[3])*r[tmp[0]],(ll)c[tmp[0]]);
            tmp[3]=sum;
            if(tmp[2]<h){
                h-=tmp[2];
                continue;
            }else{
                tmp[2]-=h;st.push(tmp);
                if(tmp[0]>1){
                    if(tmp[0]>2)st.push({1,tmp[0]-1,sum,0});
                    else st.push({1,1,0,sum}); 
                }
                return;
            }
        }else{
            ll val=qry(sum-tmp[2],tmp[0],tmp[1]);
            if(val<h){h-=val;continue;}
            int L=tmp[0],R=tmp[1],ret=L-1;
            while(L<=R){
                int mid=(L+R)>>1;
                if(qry(sum-tmp[2],tmp[0],mid)<h){
                    ret=mid;L=mid+1;
                }else R=mid-1;
            }
            ll pre=0;if(ret>=tmp[0])pre=qry(sum-tmp[2],tmp[0],ret);
            h-=pre;val=qry(sum-tmp[2],ret+1,ret+1);
            if(ret+1!=tmp[1]){
                if(ret+2!=tmp[1])st.push({ret+2,tmp[1],tmp[2],0});
                else st.push({ret+2,ret+2,qry(sum-tmp[2],ret+2,ret+2),sum});
            }
            st.push({ret+1,ret+1,val-h,sum});
            if(ret){
                if(ret>1)st.push({1,ret,sum,0});
                else st.push({1,1,0,sum});
            }
            return;
        }
    }
    if(n==1)st.push({1,1,0,sum});
    else st.push({1,n,sum,0});
    ans+=h;
}
signed main(){
    ios::sync_with_stdio(false);
    cin>>n;
    rep(i,1,n)cin>>c[i]>>r[i];
    Pre();
    sum=INF;
    if(n>1)st.push({1,n,0,0});
    else st.push({1,n,c[1],sum});
    cin>>q;
    rep(i,1,q){
        int t,h;cin>>t>>h;
        int delta=t-pre;
        solve(delta,h);
        pre=t;
    }
    cout<<ans<<endl;

    return 0;
}