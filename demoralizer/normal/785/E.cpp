#include "bits/stdc++.h"
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define fbo               find_by_order
#define ook               order_of_key
template<typename T>
using oset = __gnu_pbds::tree<T,__gnu_pbds::null_type,less<T>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>;
#define int               long long
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define sz(x)             (int)((x).size())
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount
#define ppcll             __builtin_popcountll

template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.fr>>a.sc;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.fr<<" "<<a.sc;return out;}
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}

const long long INF=1e18;
const int32_t M=1e9+7;
const int32_t MM=998244353;

const int N=2e5+5;

oset<int> t[4*N];
int query(int v,int tl,int tr,int l,int r,int x,int y){
	if(tl > r || tr < l){
		return 0;
	}
	if(tl >= l && tr <= r){
		int ans = 0;
		ans += t[v].ook(x);
		ans -= t[v].ook(y);
		return ans;
	}
	int tm = (tl + tr) / 2;
	return query(2*v,tl,tm,l,r,x,y) + query(2*v+1,tm+1,tr,l,r,x,y);
}
int query(int l,int r,int x,int y){
	if(x < y){
		swap(x,y);
	}
	return query(1,0,N-1,l,r,x,y);
}
void update_ins(int v,int tl,int tr,int id,int val){
	if(tl > id || tr < id){
		return;
	}
	t[v].insert(val);
	if(tl == tr){
		return;
	}
	int tm = (tl + tr) / 2;
	if(id > tm){
		update_ins(2*v+1,tm+1,tr,id,val);
	}
	else{
		update_ins(2*v,tl,tm,id,val);
	}
}
void update_ers(int v,int tl,int tr,int id,int val){
	if(tl > id || tr < id){
		return;
	}
	t[v].erase(val);
	if(tl == tr){
		return;
	}
	int tm = (tl + tr) / 2;
	if(id > tm){
		update_ers(2*v+1,tm+1,tr,id,val);
	}
	else{
		update_ers(2*v,tl,tm,id,val);
	}
}

void update(int id,int val,int act){
	if(act == 1){
		update_ins(1,0,N-1,id,val);
	}
	else{
		update_ers(1,0,N-1,id,val);
	}
}

int p[N];

void solve(){
	int n,q;
	cin >> n >> q;
	rep(i,1,n+1){
		update(i,i,1);
		p[i] = i;
	}
	int ans = 0;
	rep(i,0,q){
		int l,r;
		cin >> l >> r;
		if(l == r){
			cout << ans << "\n";
			continue;
		}
		if(l > r){
			swap(l,r);
		}
		int x = p[l], y = p[r];
		int tmp = query(l+1,r-1,x,y);
		// cout << "||| " << l << " " << r << " " << p[l] << " " << p[r] << " " << tmp << "\n";
		if(p[l] < p[r]){
			ans += 2*tmp + 1;
		}
		else{
			ans -= 2*tmp + 1;
		}
		cout << ans << "\n";
		update(l,p[l],0);
		update(r,p[r],0);
		swap(p[l],p[r]);
		update(l,p[l],1);
		update(r,p[r],1);
	}
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#ifdef SIEVE
		sieve();
	#endif
	#ifdef NCR
		init();
	#endif
	int t=1;
	//cin>>t;
	while(t--) solve();
	return 0;
}