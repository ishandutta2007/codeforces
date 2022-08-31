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

int query(int x1,int y1,int x2,int y2){
	cout << "? " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
	int ans;
	cin >> ans;
	return ans;
}

void answer(pii x1,pii y1,pii x2,pii y2){
	cout << "! " << x1.fr << " " << y1.fr << " " << x1.sc << " " << y1.sc << " "
		<< x2.fr << " " << y2.fr << " " << x2.sc << " " << y2.sc << endl;
	exit(0);
}

bool check(pii x1,pii y1,pii x2,pii y2){
	int a = query(x1.fr,y1.fr,x1.sc,y1.sc);
	int b = query(x2.fr,y2.fr,x2.sc,y2.sc);
	return (a == b && a == 1);
}

void solve(){
	int n;
	cin >> n;
	int L = 1, U = n;
	int ans,val;
	while(L <= U){
		int m = (L + U) / 2;
		int tmp = query(1,1,m,n);
		if(tmp){
			ans = m;
			val = tmp;
			U = m - 1;
		}
		else{
			L = m + 1;
		}
	}
	
	int ux1 = ans, ux1v = val, ux2;
	if(val == 2){
		ux2 = ux1;
	}
	else{
		L = 1, U = n;
		while(L <= U){
			int m = (L + U) / 2;
			int tmp = query(1,1,m,n);
			if(tmp > 1){
				ans = m;
				val = tmp;
				U = m - 1;
			}
			else{
				L = m + 1;
			}
		}
		ux2 = ans;
	}
	
	// cout << ux1 << " " << ux2 << "\n";
	
	L = 1, U = n;
	while(L <= U){
		int m = (L + U) / 2;
		int tmp = query(m,1,n,n);
		if(tmp){
			ans = m;
			val = tmp;
			L = m + 1;
		}
		else{
			U = m - 1;
		}
	}
	int dx1 = ans, dx1v = val, dx2;
	if(val == 2){
		dx2 = dx1;
	}
	else{
		L = 1, U = n;
		while(L <= U){
			int m = (L + U) / 2;
			int tmp = query(m,1,n,n);
			if(tmp > 1){
				ans = m;
				val = tmp;
				L = m + 1;
			}
			else{
				U = m - 1;
			}
		}
		dx2 = ans;
	}
	
	// cout << dx1 << " " << dx2 << "\n";
	
	// now y
	
	L = 1, U = n;
	while(L <= U){
		int m = (L + U) / 2;
		int tmp = query(1,1,n,m);
		if(tmp){
			ans = m;
			val = tmp;
			U = m - 1;
		}
		else{
			L = m + 1;
		}
	}
	
	int ly1 = ans, ly1v = val, ly2;
	if(val == 2){
		ly2 = ly1;
	}
	else{
		L = 1, U = n;
		while(L <= U){
			int m = (L + U) / 2;
			int tmp = query(1,1,n,m);
			if(tmp > 1){
				ans = m;
				val = tmp;
				U = m - 1;
			}
			else{
				L = m + 1;
			}
		}
		ly2 = ans;
	}
	
	L = 1, U = n;
	while(L <= U){
		int m = (L + U) / 2;
		int tmp = query(1,m,n,n);
		if(tmp){
			ans = m;
			val = tmp;
			L = m + 1;
		}
		else{
			U = m - 1;
		}
	}
	int ry1 = ans, ry1v = val, ry2;
	if(val == 2){
		ry2 = ry1;
	}
	else{
		L = 1, U = n;
		while(L <= U){
			int m = (L + U) / 2;
			int tmp = query(1,m,n,n);
			if(tmp > 1){
				ans = m;
				val = tmp;
				L = m + 1;
			}
			else{
				U = m - 1;
			}
		}
		ry2 = ans;
	}
	
	pii x[2] = {make_pair(dx2,ux1),make_pair(dx1,ux2)},
	    y[2] = {make_pair(ry2,ly1),make_pair(ry1,ly2)};
	
	if(check(x[0],y[0],x[1],y[1])){
		answer(x[0],y[0],x[1],y[1]);
		return;
	}
	if(check(x[0],y[1],x[1],y[0])){
		answer(x[0],y[1],x[1],y[0]);
		return;
	}
	x[0] = make_pair(dx2,ux2);
	x[1] = make_pair(dx1,ux1);
	if(check(x[0],y[0],x[1],y[1])){
		answer(x[0],y[0],x[1],y[1]);
		return;
	}
	if(check(x[0],y[1],x[1],y[0])){
		answer(x[0],y[1],x[1],y[0]);
		return;
	}
	x[0] = make_pair(dx2,ux1);
	x[1] = make_pair(dx1,ux2);
	y[0] = make_pair(ry2,ly2);
	y[1] = make_pair(ry1,ly1);
	if(check(x[0],y[0],x[1],y[1])){
		answer(x[0],y[0],x[1],y[1]);
		return;
	}
	if(check(x[0],y[1],x[1],y[0])){
		answer(x[0],y[1],x[1],y[0]);
		return;
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