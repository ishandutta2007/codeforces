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

char s[100005];
int d[100005];
void solve(){
	int n,k;
	scanf("%d%d%s",&n,&k,s+1);
	fup(i,1,n,1){
		if(s[i]=='L')d[i]=0;
		else if(s[i-1]=='W')d[i]=2;
		else d[i]=1;
		d[i]+=d[i-1];
	}
	if(k==0){
		printf("%d\n",d[n]);
		return;
	}
	int ans=d[n];
	priority_queue<int,Vi,greater<int>> q;
	int tmp=-100005;
	fup(i,1,n,1){
		if(s[i]=='W'){
			if(tmp>0)q.push(tmp);
			tmp=0;
		}else{
			tmp++;
		}
	}
	int rem=0;
	fup(i,1,n,1)if(s[i]=='L')rem++;
	if(rem==n){
		printf("%d\n",2*k-1);
		return;
	}
	k=min(rem,k);
	while(!q.empty() && k>=q.top()){
		ans+=q.top()*2+1;
		k-=q.top();
		q.pop();
	}
	printf("%d\n",ans+2*k);
}
int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--)solve();
}