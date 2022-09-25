#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

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
const int MOD=Mod2;
const int maxn=200005;
//i_am_noob
int n,m,q,a[maxn],p[maxn],rp[maxn],last[maxn],fa[maxn][18],pos[maxn],l,r;

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

segment_tree segtree(maxn,2);

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n >> m >> q;
    rep(n) {cin >> p[i];p[i]--;}
    rep(m) {cin >> a[i];a[i]--;}
    rep(n) rp[p[i]]=i;
    rep(n) last[i]=-1;
    rep(m){
        fa[i][0]=last[p[(rp[a[i]]-1+n)%n]];
        last[a[i]]=i;
        rep2(j,1,18) fa[i][j]=(fa[i][j-1]==-1?-1:fa[fa[i][j-1]][j-1]);
    }
    rep(m){
        pos[i]=i;
        rep1(j,18) if((n-1)&pow2(j)) if(pos[i]!=-1) pos[i]=fa[pos[i]][j];
        segtree.modify(1,1,m,i+1,i+1,pos[i]);
    }
    while(q--){
        cin >> l >> r;
        cout << (segtree.query(1,1,m,l,r)>=l-1);
    }
    cout << "\n";
    return 0;
}