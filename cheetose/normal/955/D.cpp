#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define y0 y12
#define y1 y22
#define INF 987654321
#define PI 3.141592653589793238462643383279502884
#define fup(i,a,b,c) for(int (i)=(a);(i)<=(b);(i)+=(c))
#define fdn(i,a,b,c) for(int (i)=(a);(i)>=(b);(i)-=(c))
#define MEM0(a) memset((a),0,sizeof(a))
#define MEM_1(a) memset((a),-1,sizeof(a))
#define ALL(a) a.begin(),a.end()
#define COMPRESS(a) sort(ALL(a));a.resize(unique(ALL(a))-a.begin())
#define SYNC ios_base::sync_with_stdio(false);cin.tie(0)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> Pi;
typedef pair<ll, ll> Pll;
typedef pair<ld, ld> Pd;
typedef vector<int> Vi;
typedef vector<ll> Vll;
typedef vector<ld> Vd;
typedef vector<Pi> VPi;
typedef vector<Pll> VPll;
typedef vector<Pd> VPd;
typedef tuple<int, int, int> iii;
typedef tuple<int, int, int, int> iiii;
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
const int MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

int n,m,k;
vector<int> zf(string& s) {
	int N = s.size();
	vector<int> z(N);
	for (int i=1, l=0, r=0; i<N; ++i) {
		if (i < r) z[i] = min(r-i, z[i-l]);
		while (i+z[i] < N && s[z[i]] == s[i+z[i]]) ++z[i];
		if (i+z[i] > r) l = i, r = i+z[i];
	}
	Vi zz(n);
	fup(i,0,n-1,1)zz[i]=z[i+m+1];
	return zz;
}
Vi pos(const Vi &z){
	Vi P(m+1,-1);
	vector<Vi> t(m+1);
	fup(i,0,n-1,1)t[z[i]].pb(i);

	set<int> S;
	fdn(i,m,1,1){
		for(int x:t[i])S.insert(x);
		auto it=S.lower_bound(k-i);
		if(it!=S.end()){
			P[i]=*it;
		}
	}
	return P;
}
int main(){
	SYNC;
	cin>>n>>m>>k;
	string s,t;
	cin>>s>>t;
	string S=t+'#'+s;
	Vi Z=zf(S);
	fup(i,0,n-1,1){
		if(Z[i]>=m){
			cout<<"Yes\n";
			int L=min(i,n-2*k),R=L+k;
			return cout<<L+1<<' '<<R+1<<'\n',0;
		}
	}
	Vi Lp=pos(Z);
	reverse(S.begin(),S.begin()+m);reverse(S.begin()+m+1,S.end());
	Z=zf(S);
	Vi Rp=pos(Z);
	fup(i,1,min(m-1,k),1){
		if(m-i>k)continue;
		if(Lp[i]==-1 || Rp[m-i]==-1)continue;
		int L=Lp[i]+i-1,R=Rp[m-i]+m-i-1;
		if(L+R>=n-1)continue;
		cout<<"Yes\n";
		return cout<<Lp[i]+i-k+1<<' '<<n-Rp[m-i]-m+i+1,0;
	}
	cout<<"No\n";
}