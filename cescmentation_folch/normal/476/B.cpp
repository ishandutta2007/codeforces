#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<string>
#include<stack>
#include<iomanip>

using namespace std;

#define X first
#define Y second
#define FOR(i,a,f) for(int i = a;i < f;++i)
#define ROF(i,a,f) for(int i = a;i > f;--i)

typedef vector<double> VD;
typedef vector<VD> VVD;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long ll;
typedef vector<ll> Vll;
typedef vector<Vll> VVll;
typedef pair<int, int> PI;
typedef pair<bool , int> PBI;
typedef pair<PI,PBI> PIB;
typedef vector<PI> VPI;
typedef vector<VPI> VVPI;
typedef priority_queue<PI> PQPI;
typedef queue<PI> QPI;
typedef queue<PIB> QPIB;
typedef vector<bool> VB;
typedef vector<char> VC;
typedef vector<VC> VVC;

ll ab(ll x){
	return x<0? -x : x;
}

VVD V;

double f(int n, int m){
	if(n < m) return 0;
	if(m < 0) return 0;
	if(n == 0 && m == 0) return 1;
	if(V[n][m] > -1) return V[n][m];
	V[n][m] = 0.5*f(n-1,m);
	V[n][m] += 0.5*f(n-1,m-1);
	return V[n][m];
}

int main(){
	string a,b;
	cin>>a>>b;
	ll k = 0;
	FOR(i,0,(int)a.size()){
		if(a[i] == '+') ++k;
		else --k;
	}
	ll q = 0;
	ll t = 0;
	FOR(i,0,(int)b.size()){
		if(b[i] == '+') ++q;
		else if(b[i] == '-') --q;
		else ++t;
	}
	ll r = ab(k-q);
	ll y = t-r;
	if(y%2 == 1){
		cout<<0<<endl;
		return 0;
	}
	r += y/2;
	V = VVD(t+1,(VD(r+1,-1)));
	cout<<setprecision(12)<<fixed<<f(t,r)<<endl;
}