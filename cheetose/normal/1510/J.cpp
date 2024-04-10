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
const int MOD = 1000000021;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

char s[100005];
int main(){
	scanf("%s",s);
	int n=strlen(s);
	Vi blank,C;
	int tmp=0;
	if(s[0]=='#')blank.pb(0);
	else tmp=1;
	fup(i,1,n-1,1){
		if(s[i]=='_')tmp++;
		else if(tmp>0){
			blank.pb(tmp);
			tmp=0;
		}
	}
	blank.pb(tmp);
	blank[0]++;
	blank.back()++;
	tmp=0;
	fup(i,0,n-1,1){
		if(s[i]=='#')tmp++;
		else if(tmp>0){
			C.pb(tmp);
			tmp=0;
		}
	}
	if(tmp>0)C.pb(tmp);
	if(C.empty()){
		puts("0\n");
		return 0;
	}
	if(*max_element(ALL(blank))==1){
		printf("%d\n",C.size());
		for(int x:C)printf("%d ",x);
		return 0;
	}
	int N=C.size();
	if(s[0]=='#' || s[n-1]=='#')return !printf("-1\n");
	if(*min_element(ALL(blank))==1)return !printf("-1\n");
	Vi ans;
	bool odd=0;
	for(int x:blank)if(x&1)odd=1;
	if(!odd){
		fup(i,0,N-1,1){
			while(blank[i]>2){
				ans.pb(1);
				blank[i]-=2;
			}
			ans.pb(C[i]+1);
		}
		while(blank[N]>2){
			ans.pb(1);
			blank[N]-=2;
		}
		printf("%d\n",ans.size());
		for(int x:ans)printf("%d ",x);
		return 0;
	}
	int mn=INF,four=0,five=0;
	for(int x:blank){
		mn=min(mn,x);
		if(x==4)four=1;
		if(x==5)five=1;
	}
	if(mn>=3 && !four){
		fup(i,0,N-1,1){
			if(blank[i]%2==0){
				ans.pb(2);
				blank[i]-=3;
			}
			while(blank[i]>3){
				ans.pb(1);
				blank[i]-=2;
			}
			ans.pb(C[i]+2);
		}
		if(blank[N]%2==0){
			ans.pb(2);
			blank[N]-=3;
		}
		while(blank[N]>3){
			ans.pb(1);
			blank[N]-=2;
		}
		printf("%d\n",ans.size());
		for(int x:ans)printf("%d ",x);
		return 0;
	}
	if(mn>=4 && !five){
		fup(i,0,N-1,1){
			if(blank[i]%2==1){
				ans.pb(2);
				blank[i]-=3;
			}
			while(blank[i]>4){
				ans.pb(1);
				blank[i]-=2;
			}
			ans.pb(C[i]+3);
		}
		if(blank[N]%2==1){
			ans.pb(2);
			blank[N]-=3;
		}
		while(blank[N]>4){
			ans.pb(1);
			blank[N]-=2;
		}
		printf("%d\n",ans.size());
		for(int x:ans)printf("%d ",x);
		return 0;
	}
	puts("-1");
}