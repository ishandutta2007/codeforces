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

int m[200000],k[200000];
ll cnt[200001];
int main(){
	int n;
	scanf("%d",&n);
	fup(i,0,n-1,1)scanf("%d%d",m+i,k+i);
	Pll ans(0,1);
	fup(t,1,200,1){
		MEM0(cnt);
		fup(i,0,n-1,1){
			cnt[m[i]]+=min(k[i],t);
		}
		priority_queue<ll,Vll,greater<ll>> q;
		fup(i,1,200000,1){
			if(cnt[i]>0)q.push(cnt[i]);
			if(q.size()>t)q.pop();
		}
		ll s=0;
		while(!q.empty()){
			s+=q.top();
			q.pop();
		}
		if(s*ans.Y > ans.X*t)ans=mp(s,t);
	}
	printf("%lld\n",ans.Y);
	int t=ans.Y;
	MEM0(cnt);
	fup(i,0,n-1,1){
		cnt[m[i]]+=min(k[i],t);
	}
	priority_queue<Pll,VPll,greater<Pll>> q;
	fup(i,1,200000,1){
		if(cnt[i]>0)q.push(mp(cnt[i],i));
		if(q.size()>t)q.pop();
	}
	while(!q.empty()){
		printf("%lld ",q.top().Y);
		q.pop();
	}
}