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
#define MEM0(a) memset((a),0,sizeof(a));
#define MEM_1(a) memset((a),-1,sizeof(a));
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
typedef vector<double> Vd;
typedef vector<Pi> VPi;
typedef vector<Pll> VPll;
typedef vector<Pd> VPd;
typedef tuple<int, int, int> iii;
typedef tuple<int,int,int,int> iiii;
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
const int MOD = 11092019;
ll POW(ll a, ll b, ll MMM=MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[]={2,2,-2,-2,1,1,-1,-1},ddy[]={1,-1,1,-1,2,-2,2,-2};

int cnt[100001];
int t[9];
int main(){
	int n;
	scanf("%d",&n);
	fup(i,1,n,1){
		int x;
		scanf("%d",&x);
		cnt[x]++;
		if(cnt[x]==2)t[2]++;
		if(cnt[x]==4)t[4]++;
		if(cnt[x]==6)t[6]++;
		if(cnt[x]==8)t[8]++;
	}
	int m;
	scanf("%d",&m);
	fup(i,1,m,1){
		char c;
		int x;
		scanf(" %c%d",&c,&x);
		if(c=='+'){
			cnt[x]++;
			if(cnt[x]==2)t[2]++;
			if(cnt[x]==4)t[4]++;
			if(cnt[x]==6)t[6]++;
			if(cnt[x]==8)t[8]++;
		}else{
			cnt[x]--;
			if(cnt[x]==1)t[2]--;
			if(cnt[x]==3)t[4]--;
			if(cnt[x]==5)t[6]--;
			if(cnt[x]==7)t[8]--;
		}
		if(t[8]>=1 || (t[6]>=1 && t[2]>=2) || (t[4]>=1 && t[2]>=3) || (t[4]>=2))puts("YES");
		else puts("NO");
	}
}