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

Vi v[200005];
int a[200005],ans[200005];
bool chk[200005];
void solve(){
	int n;
	scanf("%d",&n);
	fup(i,1,n,1){
		v[i].clear();
		ans[i]=-1;
		chk[i]=0;
	}
	fup(i,1,n,1){
		scanf("%d",a+i);
		v[a[i]].pb(i);
	}
	fup(i,1,n,1){
		if(v[i].empty())continue;
		if(v[i].size()==1){
			ans[v[i][0]]=i;
			chk[i]=1;
		}else{
			bool ok=0;
			for(int j:v[i]){
				if(ans[j]==-1 && v[j].empty()){
					ok=1;
					ans[j]=i;
					chk[i]=1;
					break;
				}
			}
			if(!ok){
				for(int j:v[i]){
					if(ans[j]==-1){
						ans[j]=i;
						chk[i]=1;
						break;
					}
				}
			}
		}
	}
	int res=0;
	fup(i,1,n,1){
		if(a[i]==ans[i])res++;
	}
	printf("%d\n",res);
	set<int> S1,S2;
	fup(i,1,n,1){
		if(ans[i]==-1)S1.insert(i);
		if(!chk[i])S2.insert(i);
	}
	for(auto it=S2.begin();it!=S2.end();){
		int x=*it;
		auto it2=S1.find(x);
		if(it2!=S1.end()){
			if(it2!=S1.begin()){
				it2--;
			}else{
				it2++;
			}
			ans[*it2]=x;
			S1.erase(it2);
			it=S2.erase(it);
		}else{
			it++;
		}
	}
	for(auto it1=S1.begin(),it2=S2.begin();it1!=S1.end();it1++,it2++){
		ans[*it1]=*it2;
	}
	fup(i,1,n,1)printf("%d ",ans[i]);
	puts("");
}
int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--)solve();
}