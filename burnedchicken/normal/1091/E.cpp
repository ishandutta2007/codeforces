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
const int maxn=500005;
//i_am_noob
int n,a[maxn],sum[maxn],cur,cnt[maxn]={0},k=0,total=0;
vector<int> vec;
vector<pii> vec1;

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
segment_tree segtree(maxn,1);

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n;
    rep(n) cin >> a[i];
    sort(a,a+n,[&](int i, int j){return i>j;});
    rep(n) cnt[a[i]]++;
    rep(n) total+=a[i];
    sum[0]=0;
    rep(n) sum[i+1]=sum[i]+a[i];
    cur=n;
    rep(n){
        k-=min(i,a[i]);
        cur-=cnt[i];
        cnt[a[i]]--;
        if(a[i]>i) cur--;
        k+=cur;
        segtree.modify(1,1,n,i+1,i+1,(i+1)*i+k-sum[i+1]);
    }
    if(total%2==0&&segtree.query(1,1,n,1,n)>=0) vec.pb(0);
    rep(n) vec1.pb({a[i],i});
    sort(all(vec1),[&](pii i, pii j){return i>j;});
    rep2(i,1,n+1){
        k=vec1[i-1].second;
        segtree.modify(1,1,n,k+1,n,1);
        segtree.modify(1,1,n,a[k],k,-1);
        a[k]--;
        total--;
        if(total%2==0&&segtree.query(1,1,n,1,n)>=0) vec.pb(i);
    }
    if(vec.empty()) print0(-1);
    else for(auto i: vec) print0(i);
    cout << "\n";
    return 0;
}