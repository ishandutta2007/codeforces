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

void fft(vector<base> &a, bool inv){
	int n = a.size(), j = 0;
	vector<base> roots(n/2);
	for(int i=1; i<n; i++){
		int bit = (n >> 1);
		while(j >= bit){
			j -= bit;
			bit >>= 1;
		}
		j += bit;
		if(i < j) swap(a[i], a[j]);
	}
	double ang = 2 * acos(-1) / n * (inv ? -1 : 1);
	for(int i=0; i<n/2; i++){
		roots[i] = base(cos(ang * i), sin(ang * i));
	}
	for(int i=2; i<=n; i<<=1){
		int step = n / i;
		for(int j=0; j<n; j+=i){
			for(int k=0; k<i/2; k++){
				base u = a[j+k], v = a[j+k+i/2] * roots[step * k];
				a[j+k] = u+v;
				a[j+k+i/2] = u-v;
			}
		}
	}
	if(inv) for(int i=0; i<n; i++) a[i] /= n;
}

vector<int> multiply(vector<int> &v, vector<int> &w){
	vector<base> fv(v.begin(), v.end()), fw(w.begin(), w.end());
	int n = 2; while(n < v.size() + w.size()) n <<= 1;
	fv.resize(n); fw.resize(n);
	fft(fv, 0); fft(fw, 0);
	for(int i=0; i<n; i++) fv[i] *= fw[i];
	fft(fv, 1);
	vector<int> ret(n);
	for(int i=0; i<n; i++) ret[i] = (int)round(fv[i].real());
	return ret;
}
int a[200005];
bool chk[200005];
Vi v[500001];
int main(){
	fup(i,2,500000,1){
		fup(j,i,500000,i){
			v[j].pb(i);
		}
	}
	int n,x1,y;
	scanf("%d%d%d",&n,&x1,&y);
	fup(i,0,n,1)scanf("%d",a+i);
	Vi A(2*x1+2),B(2*x1+1);
	fup(i,0,n,1)A[x1+a[i]]=1;
	fup(i,0,n,1)B[x1-a[i]]=1;
	Vi C=multiply(A,B);
	fup(i,0,x1,1)if(C[i+2*x1])chk[i]=1;
	int q;
	scanf("%d",&q);
	while(q--){
		int x;
		scanf("%d",&x);
		x/=2;
		bool ok=0;
		fdn(i,(int)v[x].size()-1,0,1){
			int xx=v[x][i]-y;
			if(xx>0 && xx<=x1 && chk[xx]){
				ok=1;
				printf("%d ",(xx+y)*2);
				break;
			}
		}
		if(!ok)printf("-1 ");
	}
}