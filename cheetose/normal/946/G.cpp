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

int a[200000];
int tree[2][1048576];
void upd(int i, int node, int S, int E, int k, int dif)
{
	tree[i][node]=max(tree[i][node],dif);
	if (S == E)return;
	if (k <= (S + E) / 2)upd(i, node * 2, S, (S + E) / 2, k, dif);
	else upd(i, node * 2 + 1, (S + E) / 2 + 1, E, k, dif);
}

int find(int k,int node, int S, int E, int i, int j)
{
	if (i > E || j < S)return 0;
	if (i <= S && j >= E)return tree[k][node];
	return max(find(k,node * 2, S, (S + E) / 2, i, j), find(k,node * 2 + 1, (S + E) / 2 + 1, E, i, j));
}
int main(){
	Vi vv;
	int n;
	scanf("%d",&n);
	fup(i,0,n-1,1){
		scanf("%d",a+i);
		a[i]-=i;
		vv.pb(a[i]);vv.pb(a[i]+1);
	}
	sort(ALL(vv));vv.resize(unique(ALL(vv))-vv.begin());
	fup(i,0,n-1,1)a[i]=lower_bound(ALL(vv),a[i])-vv.begin();
	int N=vv.size(),ans=0;
	fup(i,0,n-1,1){
		if(i+1<n){
			int tmp=max(find(0,1,0,N-1,0,a[i+1]+1),find(1,1,0,N-1,0,a[i+1]+1))+1;
			ans=max(ans,tmp);
			upd(1,1,0,N-1,a[i+1]+1,tmp);
		}
		int tmp=find(0,1,0,N-1,0,a[i])+1;
		ans=max(ans,tmp);
		upd(0,1,0,N-1,a[i],tmp);
	}
	printf("%d\n",max(0,n-1-ans));
}