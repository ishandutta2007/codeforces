#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define y0 y12
#define y1 y22
#define INF 987654321987654321
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

int a[2001];
void solve(){
	int n;
	cin>>n;
	fup(i,1,n,1)a[i]=-1;
	int j=2;
	while(1){
		cout<<"? "<<j-1<<' '<<1<<endl;
		fup(i,1,j-1,1){
			if(i==1)cout<<i;
			else cout<<" "<<i;
		}
		cout<<endl;
		cout<<j<<endl;
		int x;
		cin>>x;
		if(x!=0)break;
		j++;
	}
	a[j]=1;
	fup(i,j+1,n,1){
		cout<<"? 1 1"<<endl;
		cout<<j<<endl;
		cout<<i<<endl;
		int x;
		cin>>x;
		if(x==0)a[i]=0;
		else a[i]=1;
	}
	int l=1,r=j-1;
	while(l<r){
		int m=(l+r)/2;
		cout<<"? "<<m-l+1<<' '<<1<<endl;
		fup(i,l,m,1){
			if(i==l)cout<<i;
			else cout<<' '<<i;
		}
		cout<<endl;
		cout<<j<<endl;
		int x;
		cin>>x;
		if(x){
			fup(i,m+1,r,1)a[i]=0;
			r=m;
		}else{
			fup(i,l,m,1)a[i]=0;
			l=m+1;
		}
	}
	Vi ans;
	fup(i,1,n,1)if(a[i]==0)ans.pb(i);
	cout<<"! "<<ans.size();
	for(int x:ans)cout<<' '<<x;
	cout<<endl;
}
int main() {
	SYNC;
	int tc;
	cin>>tc;
	while(tc--)solve();
}