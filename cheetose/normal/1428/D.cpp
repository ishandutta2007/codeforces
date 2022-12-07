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

VPi ans;
int a[100001];
bool chk[100001];
int main(){
	int n;
	scanf("%d",&n);
	fup(i,1,n,1)scanf("%d",a+i);
	queue<int> q2,q3;
	fup(i,1,n,1){
		if(a[i]>0)q3.push(i);
		if(a[i]==1){
			q2.push(i);
		}
	}
	int now=1;
	fup(i,1,n,1){
		if(a[i]==0)continue;
		if(a[i]==1){
			if(chk[i])continue;
			ans.pb(mp(i,now));
			chk[i]=1;
			now++;
		}
		if(a[i]==2){
			while(!q2.empty() && chk[q2.front()])q2.pop(); 
			if(q2.empty()){
				puts("-1");
				return 0;
			}
			chk[i]=1;
			int y=q2.front();
			chk[y]=1;
			ans.pb(mp(i,now));
			ans.pb(mp(y,now));
			now++;
		}
		if(a[i]==3){
			while(!q3.empty() && (q3.front()==i || chk[q3.front()]))q3.pop();
			if(q3.empty()){
				puts("-1");
				return 0;
			}
			chk[i]=1;
			int y=q3.front();
			ans.pb(mp(i,now));
			ans.pb(mp(y,now));
			now++;
		}
	}
	printf("%d\n",ans.size());
	for(Pi P:ans)printf("%d %d\n",P.Y,P.X);
}