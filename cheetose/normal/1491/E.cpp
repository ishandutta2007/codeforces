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

int f[26];
int num[200001];
Vi v[200001];
Pi p[200001];
int cnt[200001];
bool killed[200001];
Pi get_sz(int N,int des,int P=-1){
	cnt[N]=1;
	for(int i:v[N]){
		if(i==P || killed[i])continue;
		int next=N^p[i].X^p[i].Y;
		Pi tmp=get_sz(next,des,i);
		if(tmp.X!=-1)return tmp;
		cnt[N]+=cnt[next];
	}
	if(cnt[N]==des)return mp(N,P);
	return mp(-1,-1);
}
bool find(int N,int K){
	if(K<=2)return 1;
	Pi P=get_sz(N,f[K-1]);
	if(P.X!=-1){
		killed[P.Y]=1;
		int a=P.X^p[P.Y].X^p[P.Y].Y;
		int b=P.X;
		return find(a,K-2) && find(b,K-1);
	}
	P=get_sz(N,f[K-2]);
	if(P.X!=-1){
		killed[P.Y]=1;
		int a=P.X^p[P.Y].X^p[P.Y].Y;
		int b=P.X;
		return find(a,K-1) && find(b,K-2);
	}
	return 0;
}
int main() {
	f[0]=1,f[1]=2;
	fup(i,2,25,1)f[i]=f[i-2]+f[i-1];
	MEM_1(num);
	fup(i,0,25,1)num[f[i]]=i;
	int n;
	scanf("%d",&n);
	if(num[n]==-1)return !printf("NO\n");
	if(n<=3)return !printf("YES\n");
	fup(i,1,n-1,1){
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].pb(i);
		v[y].pb(i);
		p[i]=mp(x,y);
	}
	if(find(1,num[n]))puts("YES");
	else puts("NO");
}