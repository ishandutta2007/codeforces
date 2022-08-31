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

#define double long double


const int N=0;

double dist(double x1, double y1, double x2, double y2){
	double ans = (x2 - x1) * (x2 - x1) + (y2 - y1)  * (y2 - y1);
	ans = sqrt(ans);
	return ans;
}

double M = 0,C = -100;
void line(double x1,double y1,double x2,double y2){
	M = (y2 - y1) / (x2 - x1);
	C = y1 - M * x1;
}

double query(double x){
	return M*x + C;
}

void solve(){
	int n,h;
	cin >> n >> h;
	int x[n], y[n];
	rep(i,0,n){
		cin >> x[i] >> y[i];
	}
	
	int X = x[n-1], Y = y[n-1] + h;
	
	double pr = 0;
	
	for(int i = n - 2; i >= 0; i--){
		double x1 = x[i], y1 = y[i];
		double x2 = x[i+1], y2 = y[i+1];
		
		rep(j,0,60){
			double m = (x1 + x2) / 2;
			double y = query(m);
			if(y <= y1 + (y2 - y1) / (x[i+1] - x[i]) * (m - x[i])){
				x1 = m;
			}
			else{
				x2 = m;
			}
		}
		
		double ans = x1;
		x1 = x[i], x2 = x[i+1];
		
		double y = y1 + (y2 - y1) / (x2 - x1) * (ans - x1);
		
		pr += dist(ans,y,x1,y1);
		
		if(query(x1) < y1){
			line(x1,y1,X,Y);
		}
		
	}
	
	cout<<setprecision(10);
	cout<<fixed;
	cout << pr;
	
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
//