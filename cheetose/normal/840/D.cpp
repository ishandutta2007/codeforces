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

int l[300000],r[300000],k[300000],ans[300000];
int a[300001];
int cnt[300001],b[300001][5];
Vi vv[300001];
int n,q;
void solve(int L,int R,Vi &v){
	if(v.empty())return;
	if(L==R){
		for(int i:v)ans[i]=a[L];
		return;
	}
	Vi Lv,Rv,now;
	int M=L+R>>1;
	for(int i:v){
		if(r[i]<=M)Lv.pb(i);
		else if(l[i]>M)Rv.pb(i);
		else now.pb(i);
	}
	if(now.size()){
		fup(i,L,R,1)fup(j,0,4,1)b[i][j]=0;

		fup(i,M+1,R,1){
			cnt[a[i]]++;
			int t=4;
			fup(j,0,4,1){
				if(b[i][j]==a[i])t=j;
			}
			fup(j,0,t,1){
				if(cnt[a[i]]>cnt[b[i][j]]){
					fdn(k,t-1,j,1)b[i][k+1]=b[i][k];
					b[i][j]=a[i];
					break;
				}
			}
			if(i+1<=R){
				fup(j,0,4,1)b[i+1][j]=b[i][j];
			}
		}
		fup(i,M+1,R,1)cnt[a[i]]=0;
		fdn(i,M,L,1){
			cnt[a[i]]++;
			int t=4;
			fup(j,0,4,1){
				if(b[i][j]==a[i])t=j;
			}
			fup(j,0,t,1){
				if(cnt[a[i]]>cnt[b[i][j]]){
					fdn(k,t-1,j,1)b[i][k+1]=b[i][k];
					b[i][j]=a[i];
					break;
				}
			}
			if(i-1>=L){
				fup(j,0,4,1)b[i-1][j]=b[i][j];
			}
		}
		fup(i,L,M,1)cnt[a[i]]=0;
		for(int i:now){
			int K=k[i];
			int t=INF;
			fup(j,0,K-1,1){
				int x=b[l[i]][j];
				if(x){
					int cnt=upper_bound(ALL(vv[x]),r[i])-lower_bound(ALL(vv[x]),l[i]);
					if(cnt*K>r[i]-l[i]+1)t=min(t,x);
				}
				x=b[r[i]][j];
				if(x){
					int cnt=upper_bound(ALL(vv[x]),r[i])-lower_bound(ALL(vv[x]),l[i]);
					if(cnt*K>r[i]-l[i]+1)t=min(t,x);
				}
			}
			if(t!=INF)ans[i]=t;
		}
	}
	solve(L,M,Lv);
	solve(M+1,R,Rv);
}
int main() {
	MEM_1(ans);
	scanf("%d%d",&n,&q);
	Vi v;
	fup(i,0,n-1,1)scanf("%d",a+i),vv[a[i]].pb(i);
	fup(i,0,q-1,1){
		scanf("%d%d%d",l+i,r+i,k+i),v.pb(i);
		--l[i],--r[i];
	}
	solve(0,n-1,v);
	fup(i,0,q-1,1)printf("%d\n",ans[i]);
}