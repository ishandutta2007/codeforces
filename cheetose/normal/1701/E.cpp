#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define y0 y12
#define y1 y22
#define INF 11111
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

string s,t;
short t1[5005][5005],t2[5005][5005];
short d1[5005][5005],d2[5005][5005];
vector<int> zf(string& s) {
	int n = s.size();
	vector<int> z(n);
	for (int i=1, l=0, r=0; i<n; ++i) { // [l, r)
		if (i < r) z[i] = min(r-i, z[i-l]);
		while (i+z[i] < n && s[z[i]] == s[i+z[i]]) ++z[i];
		if (i+z[i] > r) l = i, r = i+z[i];
	}
	return z;// z[i]=longest common prefix of [i,n-1] and s
}
int n,m;
inline short mn(short a,short b){
	if(a<b)return a;
	return b;
}
short go1(int x,int y){
	if(y==m)return n-x;
	if(x==n)return INF;
	short &ret=d1[x][y];
	if(~ret)return ret;
	ret=go1(x+1,y)+1;
	if(s[x]==t[y])ret=mn(ret,go1(x+1,y+1)+1);
	return ret;
}
short go2(int x,int y){
	if(y==-1)return 2*(x+1);
	if(x==-1)return INF;
	short &ret=d2[x][y];
	if(~ret)return ret;
	ret=go2(x-1,y)+2;
	if(s[x]==t[y])ret=mn(ret,go2(x-1,y-1)+1);
	return ret;
}
void solve(){
	cin>>n>>m;
	fup(i,0,n-1,1)fup(j,0,m-1,1)d1[i][j]=d2[i][j]=-1;
	cin>>s>>t;
	fup(i,0,m-1,1){
		string tmp=string(t.begin()+i,t.end())+s;
		Vi V=zf(tmp);
		fup(j,0,n-1,1)t1[j][i]=min(m-i,V[j+m-i]);
	}
	reverse(ALL(s));
	reverse(ALL(t));
	fup(i,0,m-1,1){
		string tmp=string(t.begin()+i,t.end())+s;
		Vi V=zf(tmp);
		fup(j,0,n-1,1)t2[j][i]=min(m-i,V[j+m-i]);
	}
	reverse(ALL(s));
	reverse(ALL(t));
	fup(i,0,n-1,1){
		reverse(t2[i],t2[i]+m);
	}
	fup(j,0,m-1,1){
		fup(i,0,(n-1)/2,1){
			swap(t2[i][j],t2[n-1-i][j]);
		}
	}
	short ans=mn(go1(0,0)-t1[0][0],go2(n-1,m-1)-t2[n-1][m-1]+1);
	fup(i,1,n-1,1){
		fup(j,1,m-1,1){
			ans=mn(ans,go1(i,j)-t1[i][j]+go2(i-1,j-1)-t2[i-1][j-1]+1);
		}
	}
	fup(i,1,n-1,1)ans=mn(ans,go1(i,m)+go2(i-1,m-1)-t2[i-1][m-1]+1);
	if(ans>=INF)ans=-1;
	cout<<ans<<'\n';
}
int main(){
	SYNC;
	int tc;
	cin>>tc;
	while(tc--)solve();
}