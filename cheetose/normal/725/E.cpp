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

int c,n;
int cnt[200001],parent[200001];
int find(int x){
	if(parent[x]<0)return x;
	return parent[x]=find(parent[x]);
}
void merge(int x,int y){
	x=find(x),y=find(y);
	if(x!=y)parent[y]=x;
}
int main(){
	MEM_1(parent);
	scanf("%d%d",&c,&n);
	fup(i,1,n,1){
		int x;
		scanf("%d",&x);
		cnt[x]++;
	}
	fup(i,1,c,1)if(!cnt[i])merge(i-1,i);
	fup(k,1,c,1){
		bool ok=0;
		int now=c,rem=c;
		while(1){
			now=find(now);
			if(now<=k && rem>=k && !ok){
				rem-=k;
				ok=1;
				now=min(now,rem);
				continue;
			}
			if(now==0)break;
			int t=min(rem/now,cnt[now]);
			rem-=t*now;
			now=min(now-1,rem);
		}
		if(rem>0)return !printf("%d\n",k);
	}
	puts("Greed is good");
}