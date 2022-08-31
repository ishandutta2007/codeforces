#include "bits/stdc++.h"
using namespace std;
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

const int N=1.3e7+5;

#define left axcvg
#define right axcvgwefhgk
int a[N],left[N],right[N];
int cur = 1;

int query(int v, int tl, int tr, int l, int r){
	if(l > tr || r < tl){
		return INF;
	}
	if(v == 0){
		return 0;
	}
	if(l <= tl && tr <= r){
		return a[v];
	}
	int tm = (tl + tr) / 2;
	return min(query(left[v],tl,tm,l,r),query(right[v],tm+1,tr,l,r));
}

int update(int v,int tl, int tr, int pos, int val){
	if(tl > pos || tr < pos){
		return v;
	}
	int ver = cur++;
	if(tl == tr){
		a[ver] = max(a[v],val);
		return ver;
	}
	int tm = (tl + tr) / 2;
	left[ver] = update(left[v],tl,tm,pos,val);
	right[ver] = update(right[v],tm+1,tr,pos,val);
	a[ver] = min(a[left[ver]],a[right[ver]]);
	return ver;
}

vector<array<int,3>> s;

int roots[N];

void solve(){
	int n,m,k;
	cin >> n >> m >> k;
	rep(i,0,k){
		int l,r,p;
		cin >> l >> r >> p;
		s.pb({r,l,p});
	}
	sort(all(s));
	
	rep(i,0,k){
		roots[i + 1] = update(roots[i],1,n,s[i][2],s[i][1]);
	}
	
	rep(zz,0,m){
		int a,b,x,y;
		cin >> a >> b >> x >> y;
		int root = roots[(upper_bound(all(s),array<int,3>{y,y+1,-1}) - s.begin())];
		int tmp = query(root,1,n,a,b);
		if(tmp >= x){
			cout << "yes" << endl;
		}
		else{
			cout << "no" << endl;
		}
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