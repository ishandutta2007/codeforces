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
const int MOD=Mod2;
const int maxn=200005;
//i_am_noob
int n,a[maxn],pos[maxn],ans[maxn],k,x,y;
ordered_set st;

struct BIT{
	int val[maxn];
	void modify(int x, int y){for(int i=x; i<maxn; i+=i&-i) val[i]+=y;}
	int query(int x, int y){
		int ret=0;
		for(int i=y; i>0; i-=i&-i) ret+=val[i];
		for(int i=x-1; i>0; i-=i&-i) ret-=val[i];
		return ret;
	}
}bit;

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n;
    rep(n) cin >> a[i];
    rep(n) a[i]--;
    rep(n) pos[a[i]]=i;
    rep3(i,n-1,0){
        ans[a[i]]+=st.order_of_key(a[i]);
        st.insert(a[i]);
    }
    rep2(i,1,n) ans[i]+=ans[i-1];
    st.clear();
    rep(n){
        st.insert(pos[i]);
        k=*st.find_by_order(i>>1);
        bit.modify(pos[i]+1,pos[i]);
        x=bit.query(1,k+1);
        y=bit.query(k+2,n);
        ans[i]+=(k+1)*(i/2+1)-(i/2+1)*(i/2+2)/2-x+(n-1-k)*(i-i/2)-(i-i/2)*(i-i/2+1)/2-((n-1)*(i-i/2)-y);
    }
    rep(n) print0(ans[i]);
    cout << "\n";
    return 0;
}