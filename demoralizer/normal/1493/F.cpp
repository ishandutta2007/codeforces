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

const int N=0;

int n,m;

int query(int h,int w,int i1,int j1,int i2,int j2){
	int ans;
	cout << "? " << h << " " << w << " " << i1 << " " << j1 << " " << i2 << " " << j2 << endl;
	cin >> ans;
	return ans;
}

void answer(int x){
	cout << "! " << x << endl;
	return;
}

bool checkx(int g,int val){
	// w = m, j1 = 1, j2 = 1
	if(val == 1){
		return 1;
	}
	int siz = g / val;
	int p2 = val;
	while(ppc(p2) != 1){
		p2--;
	}
	
	if(val > p2 && !query((val - p2)*siz,m,1,1,p2*siz+1,1)){
		return 0;
	}
	
	p2 /= 2;
	while(p2){
		if(!query(p2*siz,m,1,1,p2*siz+1,1)){
			return 0;
		}
		p2 /= 2;
	}
	
	return 1;
}

int solvex(){
	int g = n;
	int t = n;
	for(int i = 2; i <= n; i++){
		bool flag = 1;
		int val = 1;
		while(t % i == 0){
			t /= i;
			val *= i;
			if(flag == 1 && checkx(g,i)){
				g /= i;
			}
			else{
				flag = 0;
			}
		}
	}
	return g;
}


bool checky(int g,int val){
	// h = n, i1 = 1, i2 = 1
	if(val == 1){
		return 1;
	}
	int siz = g / val;
	int p2 = val;
	while(ppc(p2) != 1){
		p2--;
	}
	
	if(val > p2 && !query(n,(val - p2)*siz,1,1,1,p2*siz+1)){
		return 0;
	}
	
	p2 /= 2;
	while(p2){
		if(!query(n,p2*siz,1,1,1,p2*siz+1)){
			return 0;
		}
		p2 /= 2;
	}
	
	return 1;
}

int solvey(){
	int g = m;
	int t = m;
	for(int i = 2; i <= m; i++){
		bool flag = 1;
		int val = 1;
		while(t % i == 0){
			t /= i;
			val *= i;
			if(flag == 1 && checky(g,i)){
				g /= i;
			}
			else{
				flag = 0;
			}
		}
	}
	return g;
}


void solve(){
	cin >> n >> m;
	int ansx = 0;
	int ansy = 0;
	int x = solvex();
	int y = solvey();
	
	rep(i,1,n+1){
		if(n % i == 0 && i % x == 0){
			ansx++;
		}
	}
	
	rep(i,1,m+1){
		if(m % i == 0 && i % y == 0){
			ansy++;
		}
	}
	
	answer(ansx * ansy);
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