#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define y0 y12
#define y1 y22
#define INF 987654
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

char s[200005];
void solve(){
	int n;
	scanf("%d%s",&n,s);
	int t=accumulate(s,s+n,0);
	if(t&1 || t=='0'*n){
		puts("NO");
		return;
	}
	if(t=='1'*n){
		puts("YES");
		fup(i,2,n,1){
			printf("1 %d\n",i);
		}
		return;
	}
	fup(i,0,n-1,1)if(s[i]=='0' && s[(i+1)%n]=='1'){
		t=i;
		break;
	}
	rotate(s,s+t,s+n);
	VPi ans;
	for(int i=1,j=1;i;i=j){
		int cnt=0;
		int f=s[j]-'0';
		while(1){
			if(s[j]=='1')cnt++;
			if(cnt==2)break;
			j=(j+1)%n;
			if(j==0)break;
		}
		if(f==0){
			ans.pb({0,i});
			fup(k,i,(j+n-2)%n,1){
				ans.pb({k,k+1});
			}
		}else{
			ans.pb({0,(j+n-1)%n});
			fdn(k,(j+n-2)%n,i,1){
				ans.pb({k,k+1});
			}
		}
	}
	puts("YES");
	for(auto [x,y]:ans){
		printf("%d %d\n",(x+t)%n+1,(y+t)%n+1);
	}
}
int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--)solve();
}