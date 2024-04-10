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

int a[2000];
Vi v[1000001];
void solve(){
	int n;
	scanf("%d",&n);
	n<<=1;
	fup(i,0,n-1,1)scanf("%d",a+i);
	sort(a,a+n);
	fdn(i,n-2,0,1){
		vector<bool> chk(n);
		chk[n-1]=chk[i]=1;
		fup(j,0,n-2,1)if(i!=j)v[a[j]].pb(j);
		int j=n-1,x=a[n-1];
		while(j>=0){
			while(j>=0 && chk[j])j--;
			if(j<0)break;
			chk[j]=1;
			v[a[j]].pop_back();
			int t=x-a[j];
			if(v[t].empty())break;
			chk[v[t].back()]=1;
			v[t].pop_back();
			x=a[j];
		}
		bool ok=1;
		fup(k,0,n-2,1){
			while(!v[a[k]].empty()){
				ok=0;
				v[a[k]].pop_back();
			}
		}
		if(!ok)continue;
		puts("YES");
		printf("%d\n",a[i]+a[n-1]);
		fup(k,0,n-1,1)chk[k]=0;
		chk[n-1]=chk[i]=1;
		printf("%d %d\n",a[i],a[n-1]);
		fup(j,0,n-2,1)if(i!=j)v[a[j]].pb(j);
		j=n-1,x=a[n-1];
		while(j>=0){
			while(j>=0 && chk[j])j--;
			if(j<0)break;
			chk[j]=1;
			v[a[j]].pop_back();
			int t=x-a[j];
			if(v[t].empty())break;
			chk[v[t].back()]=1;
			v[t].pop_back();
			x=a[j];
			printf("%d %d\n",t,a[j]);
		}
		return;
	}
	puts("NO");
}
int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--)solve();
}