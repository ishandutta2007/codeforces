#include <bits/stdc++.h>
#include <bits/extc++.h>

#define int long long
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
const int maxn=200005;
//i_am_noob
int n,m,q,e[300005][2],a[maxn],pos[maxn],arr[maxn],k=maxn+1,l[2*maxn],r[2*maxn],child[maxn][2],_time=0;
vector<int> adj[maxn];
bool vis[300005]={false},vis2[2*maxn]={false};

struct segment_tree{
    vector<int> val,tag;
	int type;
	inline int mid(int l, int r){return l+r>>1;}
	segment_tree(int _siz, int _type){val.resize(4*_siz),tag.resize(4*_siz),type=_type;}
	inline int oper(int i, int j){
	    if(type==0) return i+j;
	    else if(type==1) return min(i,j);
	    else return max(i,j);
	}
	inline int def(){
	    if(type==0) return 0;
	    else if(type==1) return 4e18;
	    else return -4e18;
	}
	void pull(int k){val[k]=oper(val[k<<1],val[(k<<1)+1]);}
	void push(int k, int l, int r){
		if(l!=r){
            if(type){
                tag[k<<1]+=tag[k];
                tag[(k<<1)+1]+=tag[k];
                val[k<<1]+=tag[k];
                val[(k<<1)+1]+=tag[k];
            }
			else{
                tag[k<<1]+=tag[k];
                tag[(k<<1)+1]+=tag[k];
                val[k<<1]+=(mid(l,r)-l+1)*tag[k];
                val[(k<<1)+1]+=(r-mid(l,r))*tag[k];
			}
		}
		tag[k]=0;
	}
	void modify(int k, int l, int r, int ql, int qr, int x){
		if(l>qr||r<ql) return;
		if(ql<=l&&qr>=r){
			if(type) val[k]+=x;
			else val[k]+=(r-l+1)*x;
			tag[k]+=x;
			return;
		}
		push(k,l,r);
		modify(k<<1,l,mid(l,r),ql,qr,x);
		modify((k<<1)+1,mid(l,r)+1,r,ql,qr,x);
		pull(k);
	}
	int query(int k, int l, int r, int ql, int qr){
		if(l>qr||r<ql) return def();
		if(ql<=l&&qr>=r) return val[k];
		push(k,l,r);
		return oper(query(k<<1,l,mid(l,r),ql,qr),query((k<<1)+1,mid(l,r)+1,r,ql,qr));
	}
};
segment_tree segtree(2*maxn,2);

struct dsu{
    vector<int> fa,siz;
    dsu(int _siz){
        fa.resize(_siz),siz.resize(_siz);
        rep(_siz) fa[i]=i,siz[i]=1;
    }
    int Find(int _x){return fa[_x]==_x?_x:fa[_x]=Find(fa[_x]);}
    void Union(int _x, int _y){
        int _a=Find(_x),_b=Find(_y);
        if(_a==_b) return;
        if(siz[_a]<siz[_b]) swap(_a,_b);
        fa[_b]=_a;
        siz[_a]+=siz[_b];
        child[k-maxn][0]=arr[_a],child[k-maxn][1]=arr[_b];
        arr[_a]=k++;
    }
};
dsu d(maxn);

void dfs(int u){
    l[u]=++_time;
    vis2[u]=true;
    if(u>maxn) dfs(child[u-maxn][0]),dfs(child[u-maxn][1]);
    r[u]=_time;
}

struct query{int o,x,pos,ans;}qu[500005];

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n >> m >> q;
    rep(n){
        cin >> a[i];
        pos[a[i]]=i;
    }
    rep(m){
        cin >> e[i][0] >> e[i][1];
        e[i][0]--,e[i][1]--;
    }
    rep(q){
        cin >> qu[i].o >> qu[i].x;
        qu[i].x--;
        if(qu[i].o==2) vis[qu[i].x]=true;
    }
    rep(n) arr[i]=i;
    rep(m) if(!vis[i]) d.Union(e[i][0],e[i][1]);
    rep3(i,q-1,0){
        if(qu[i].o==1) qu[i].pos=arr[d.Find(qu[i].x)];
        else d.Union(e[qu[i].x][0],e[qu[i].x][1]);
    }
    rep3(i,k-1,maxn+1) if(!vis2[i]) dfs(i);
    rep(n) if(!vis2[i]) dfs(i);
    rep(n) segtree.modify(1,1,2*maxn-1,l[i],r[i],a[i]);
    rep(q){
        if(qu[i].o==1){
            qu[i].ans=segtree.query(1,1,2*maxn-1,l[qu[i].pos],r[qu[i].pos]);
            segtree.modify(1,1,2*maxn-1,l[pos[qu[i].ans]],r[pos[qu[i].ans]],-qu[i].ans);
            print1(qu[i].ans);
        }
    }
    return 0;
}