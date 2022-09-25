#include <bits/stdc++.h>
#include <bits/extc++.h>

//#define int long long
#define ull unsigned long long
#define ld long double
#define rep(a) rep1(i,a)
#define rep1(i,a) rep2(i,0,a)
#define rep2(i,b,a) for(int i=(b); i<((int)(a)); i++)
#define rep3(i,b,a) for(int i=(b); i>=((int)(a)); i--)
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
//#define inf 2000000000
#define inf 8000000000000000000
#define eps 1e-9
#define sz(a) ((int)a.size())
#define pow2(x) (1ll<<(x))
#define ceiling(a,b) (((a)+(b)-1)/(b))
#define print0(a) cout << (a) << ' '
#define print1(a) cout << (a) << '\n'
#define print2(a,b) cout << (a) << ' ',print1(b)
#define print3(a,b,c) cout << (a) << ' ',print2(b,c)
#define print4(a,b,c,d) cout << (a) << ' ',print3(b,c,d)
#define ykh mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>

using namespace std;
using namespace __gnu_pbds;

const int Mod=1000000007,Mod2=998244353;
const int MOD=Mod;
const int maxn=100005;
//i_am_noob
int n,a[maxn],q,last=0,pos[2*maxn],b[2*maxn],val[maxn],_time=1,t[maxn],x,p,cur,l,r,lpd[2*maxn];
vector<int> prime,vec[3],Pow[3];

template<typename T, int maxn, int type>
struct sparse{
    vector<T> val[22];
    sparse(){rep(__lg(maxn)+1) val[i].resize(max(0ll,maxn-pow2(i)+1));}
    inline T oper(T i, T j){return type?max(i,j):min(i,j);}
    void init(vector<T>& vec){
        rep(sz(vec)) val[0][i]=vec[i];
        rep2(i,1,__lg(maxn)+1) rep1(j,sz(val[i])) val[i][j]=oper(val[i-1][j],val[i-1][j+pow2(i-1)]);
    }
    T query(int l, int r){return oper(val[__lg(r-l+1)][l],val[__lg(r-l+1)][r-pow2(__lg(r-l+1))+1]);}
};
sparse<int,maxn,1> sp[3];

void find_prime(int n){
	rep(n) lpd[i]=-1;
    rep2(i,2,n){
        if(lpd[i]==-1){
            prime.pb(i);
            lpd[i]=i;
            if(1ll*i*i<n) for(int j=i*i; j<n; j+=i) if(lpd[j]==-1) lpd[j]=i;
        }
    }
}

template<int maxn,int maxq>
struct persistent_segment_tree{
    struct Node{int lc,rc,val;};
    Node node[maxn*4+maxq*40];
    int cnt_node=0,cur_time=0,rt[maxq];
    int build(int l, int r){
        int res=cnt_node++;
        if(l==r){
            node[res].val=1;
            return res;
        }
        node[res].lc=build(l,l+r>>1);
        node[res].rc=build((l+r>>1)+1,r);
        pull(res);
        return res;
    }
    persistent_segment_tree(){
        rt[0]=0;
        build(1,maxn);
    }
    void pull(int k){node[k].val=1ll*node[node[k].lc].val*node[node[k].rc].val%MOD;}
    int new_node(int old){
        int res=cnt_node++;
        node[res].lc=node[old].lc,node[res].rc=node[old].rc;
        return res;
    }
    int modify(int old, int l, int r, int p, int x){
        int res=new_node(old);
        if(l==r){
            node[res].val=x;
            return res;
        }
        if(p<=(l+r>>1)) node[res].lc=modify(node[old].lc,l,l+r>>1,p,x);
        else node[res].rc=modify(node[old].rc,(l+r>>1)+1,r,p,x);
        pull(res);
        return res;
    }
    void modify(int p, int x, int t){
        rt[t]=cnt_node;
        modify(rt[t-1],1,maxn,p,x);
    }
    int query(int k, int l, int r, int ql, int qr){
        if(l>qr||r<ql) return 1;
        if(ql<=l&&qr>=r){
            return node[k].val;
        }
        return 1ll*query(node[k].lc,l,l+r>>1,ql,qr)*query(node[k].rc,(l+r>>1)+1,r,ql,qr)%MOD;
    }
    int query(int ql, int qr, int t){return query(rt[t],1,maxn,ql,qr);}
};
persistent_segment_tree<maxn,7*maxn> segtree;

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    find_prime(2*maxn);
    rep(sz(prime)) pos[prime[i]]=i;
    rep(2*maxn) b[i]=-1;
    rep(maxn) val[i]=1;
    cin >> n;
    rep(n) cin >> a[i];
    rep(3){
        Pow[i].pb(1);
        while(1){
            if(Pow[i].back()*prime[i]>2*maxn) break;
            Pow[i].pb(Pow[i].back()*prime[i]);
        }
    }
    rep(n){
        x=a[i],p=-1;
        rep1(j,3) vec[j].pb(0);
        while(x>1){
            if(lpd[x]<=5){
                vec[pos[lpd[x]]].back()++;
                x/=lpd[x];
                continue;
            }
            if(lpd[x]!=p) cur=lpd[x];
            else cur*=p;
            p=lpd[x];
            if(b[cur]!=-1){
                segtree.modify(b[cur]+1,val[b[cur]]/p,_time);
                _time++;
                val[b[cur]]/=p;
            }
            val[i]*=p;
            b[cur]=i;
            x/=p;
        }
        segtree.modify(i+1,val[i],_time);
        t[i]=_time++;
    }
    rep(3) sp[i].init(vec[i]);
    cin >> q;
    while(q--){
        cin >> l >> r;
        l=(l+last)%n+1,r=(r+last)%n+1;
        if(l>r) swap(l,r);
        last=segtree.query(l,r,t[r-1]);
        rep(3) last=1ll*last*Pow[i][sp[i].query(l-1,r-1)]%MOD;
        print1(last);
    }
    return 0;
}