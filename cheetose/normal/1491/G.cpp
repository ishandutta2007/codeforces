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

int a[200001];
bool chk[200001];
VPi ans;
void sw(int i,int j){
	ans.pb(mp(i,j));
	swap(a[i],a[j]);
	a[i]*=-1,a[j]*=-1;
}
void go(int i,int j){
	sw(i,j);
	while(a[-a[i]]>0){
		sw(i,-a[i]);
	}
	j=-a[i];
	while(a[-a[j]]>0){
		sw(j,-a[j]);
	}
	sw(j,-a[j]);
}
int main(){
	int n;
	scanf("%d",&n);
	fup(i,1,n,1)scanf("%d",a+i);
	int t=-1;
	fup(i,1,n,1){
		if(a[i]==i || chk[i])continue;
		while(!chk[i]){
			chk[i]=1;
			i=a[i];
		}
		if(t==-1)t=i;
		else{
			go(t,i);
			t=-1;
		}
	}
	if(t!=-1){
		bool ok=0;
		fup(i,1,n,1){
			if(a[i]==i){
				ok=1;
				go(i,t);
				break;
			}
		}
		if(!ok){
			int t1=a[t],t2=a[t1];
			sw(t,t1);
			go(t1,t2);
		}
	}
	printf("%d\n",ans.size());
	for(auto [x,y]:ans)printf("%d %d\n",x,y);
}