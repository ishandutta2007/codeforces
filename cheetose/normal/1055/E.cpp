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
typedef vector<db> Vd;
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

int n,s,m,k;
bool chk[1500];
int a[1500],b[1500];
int c[1500][1500],d[1502][1502];
int le[1500];
Pi p[1500];
VPi v;
Vi vv;
inline int sum(int l,int r){
	return b[r]-(l==0?0:b[l-1]);
}
bool ok(int t){
	MEM0(d);
	fup(i,0,n-1,1){
		if(a[i]<=t)b[i]=1;
		else b[i]=0;
		if(i>0)b[i]+=b[i-1];
	}
	int N=v.size();
	fup(i,0,N-1,1){
		fup(j,i,N-1,1){
			if(i==j)c[i][j]=sum(v[i].X,v[i].Y);
			else if(v[i].Y>=v[j].X)c[i][j]=sum(v[i].Y+1,v[j].Y);
			else c[i][j]=sum(v[j].X,v[j].Y);
		}
	}
	fup(i,0,N-1,1){
		d[1][i]=c[i][i];
	}
	fup(k,2,m,1){
		Vi mx(N);
		mx[0]=d[k-1][0];
		fup(i,1,N-1,1)mx[i]=max(mx[i-1],d[k-1][i]);
		fup(i,k-1,N-1,1){
			int t=le[i];
			if(t+1!=i)d[k][i]=mx[t+1]+c[t+1][i];
			if(t!=-1)d[k][i]=max(d[k][i],mx[t]+c[i][i]);
		}
	}
	fup(i,0,N-1,1)fup(j,1,m,1)if(d[j][i]>=k)return 1;
	return 0;
}
int main(){
	scanf("%d%d%d%d",&n,&s,&m,&k);
	fup(i,0,n-1,1){
		scanf("%d",a+i);
		vv.pb(a[i]);
	}
	sort(ALL(vv));vv.resize(unique(ALL(vv))-vv.begin());
	fup(i,0,n-1,1)a[i]=lower_bound(ALL(vv),a[i])-vv.begin();
	fup(i,0,s-1,1){
		scanf("%d%d",&p[i].X,&p[i].Y);
		p[i].X--,p[i].Y--;
	}
	sort(p,p+s,[&](Pi p1,Pi p2){
		if(p1.X!=p2.X)return p1.X<p2.X;
		return p1.Y>p2.Y;
	});
	fup(i,0,s-1,1){
		fup(j,i+1,s-1,1){
			if(p[i].Y>=p[j].Y)chk[j]=1;
		}
	}
	fup(i,0,s-1,1)if(!chk[i])v.pb(p[i]);
	for(int i=0,j=0;i<v.size();i++){
		while(j<i && v[j].Y<v[i].X)j++;
		le[i]=j-1;
	}
	int l=0,r=vv.size()-1;
	while(l<=r){
		int t=l+r>>1;
		if(ok(t))r=t-1;
		else l=t+1;
	}
	if(l==vv.size())puts("-1");
	else printf("%d\n",vv[l]);
}