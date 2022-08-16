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

const int N=1e5+5;

int t[N * 40];
int lef[N * 40];
int rig[N * 40];
int query(int v,int tl,int tr,int l,int r){
	if(!v || tl > r || tr < l){
		return 0;
	}
	if(tl >= l && tr <= r){
		return t[v];
	}
	int tm = (tl + tr) / 2;
	return query(lef[v],tl,tm,l,r) + query(rig[v],tm+1,tr,l,r);
}

int cnt = 1;
int make(){
	return cnt++;
}
int update(int v,int tl,int tr,int id,int val){
	int n = make();
	t[n] = t[v];lef[n] = lef[v];rig[n] = rig[v];
	t[n] += val;
	if(tl == tr){
		return n;
	}
	int tm = (tl + tr) / 2;
	if(id > tm){
		rig[n] = update(rig[v],tm+1,tr,id,val);
	}
	else{
		lef[n] = update(lef[v],tl,tm,id,val);
	}
	return n;
}

queue<int> v[N];
int a[N];

int version[N];

void solve(){
	int n,k;
	cin >> n >> k;
	rep(i,1,n+1){
		cin >> a[i];
		v[a[i]].push(i);
		version[i] = update(version[i-1],0,N-1,i,1);
		if(sz(v[a[i]]) > k){
			int tmp = v[a[i]].front();
			v[a[i]].pop();
			version[i] = update(version[i],0,N-1,tmp,-1);
		}
	}
	
	int last = 0;
	int q;
	cin >> q;
	rep(i,0,q){
		int x,y;
		cin >> x >> y;
		x = (x + last) % n + 1;
		y = (y + last) % n + 1;
		if(x > y) swap(x,y);
		cout << (last = query(version[y],0,N-1,x,y)) << "\n";
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