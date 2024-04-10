#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define y0 y12
#define y1 y22
#define INF 1987654321
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
const int MOD = 998244353;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

int n,m;
int lg[100005],k[100001];
struct ST{
	int l[100001],r[100001];
	int mn[100001][17],mx[100001][17];
	int to[100001];
	void init(){
		fup(i,0,n,1){
			fup(j,0,16,1){
				mn[i][j]=INF;
				mx[i][j]=-1;
			}
		}
		fup(i,0,n,1){
			mn[i][0]=r[i];
			mx[i][0]=l[i];
		}
		fup(j,0,15,1){
			fup(i,0,n,1){
				if(i+(1<<(j+1))>n+1)break;
				mn[i][j+1]=min(mn[i][j],mn[i+(1<<j)][j]);
				mx[i][j+1]=max(mx[i][j],mx[i+(1<<j)][j]);
			}
		}
	}
	int getmn(int x,int y){
		int t=lg[y-x+1];
		return min(mn[x][t],mn[y-(1<<t)+1][t]);
	}
	int getmx(int x,int y){
		int t=lg[y-x+1];
		return max(mx[x][t],mx[y-(1<<t)+1][t]);
	}
	void cal(){
		fup(i,0,n,1){
			int x=i,y=n;
			while(x<=y){
				int mm=x+y>>1;
				int t1=getmx(i,mm),t2=getmn(i,mm);
				if(t1<=k[i] && k[i]<=t2)x=mm+1;
				else y=mm-1;
			}
			to[i]=y;
		}
	}
}L,R;
int ans[100001];
int okL[100001],okR[100001];
int dL[100001],dR[100001];
int main(){
	fup(i,1,16,1)lg[1<<i]=i;
	fup(i,2,100001,1)if(!lg[i])lg[i]=lg[i-1];
	scanf("%d%d",&n,&m);
	L.l[0]=L.r[0]=R.l[0]=R.r[0]=0;
	fup(i,1,n,1){
		scanf("%d%d%d%d%d",&k[i],&L.l[i],&L.r[i],&R.l[i],&R.r[i]);
		if(L.l[i]<=k[i] && k[i]<=L.r[i])okL[i]=1;
		if(R.l[i]<=k[i] && k[i]<=R.r[i])okR[i]=1;
		okL[i]+=okL[i-1];
		okR[i]+=okR[i-1];
	}
	L.init();R.init();
	L.cal();R.cal();
	int L_=-1,R_=-1;
	if(okL[n]-okL[n-1])dL[n]=1,L_=n;
	if(okR[n]-okR[n-1])dR[n]=1,R_=n;
	fdn(i,n-1,1,1){
		int TL=L_,TR=R_;
		if(L_!=-1){
			if(R.to[i]>=L_ && okL[L_]-okL[i]==L_-i)dR[i]=1,TR=i;
		}
		if(R_!=-1){
			if(L.to[i]>=R_ && okR[R_]-okR[i]==R_-i)dL[i]=1,TL=i;
		}
		L_=TL,R_=TR;
	}
	int t=-1;
	if(L_!=-1){
		if(R.to[0]>=L_ && okL[L_]==L_)dR[0]=1,t=0;
	}
	if(R_!=-1){
		if(L.to[0]>=R_ && okR[R_]==R_)dL[0]=1,t=1;
	}
	if(t==-1)return !printf("No\n");
	puts("Yes");
	fup(i,0,n,1){
		ans[i]=t;
		if(t){
			if(dR[i])t=0;
		}else{
			if(dL[i])t=1;
		}
		if(i)printf("%d ",ans[i]);
	}
}