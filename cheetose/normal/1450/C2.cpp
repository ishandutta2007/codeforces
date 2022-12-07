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
const int MOD = 998244353;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

int n;
char s[303][303];
int c[3][2];
void solve(){
	MEM0(c);
	scanf("%d",&n);
	fup(i,0,n-1,1)scanf("%s",s[i]);
	if(n<=2){
		fup(i,0,n-1,1)printf("%s\n",s[i]);
		return;
	}
	fup(i,0,n-1,1){
		fup(j,0,n-1,1){
			if(s[i][j]=='O')c[(i+j)%3][0]++;
			if(s[i][j]=='X')c[(i+j)%3][1]++;
		}
	}
	int t=min({c[0][0]+c[1][1], c[0][0]+c[2][1], c[0][1]+c[1][0], c[0][1]+c[2][0], c[1][0]+c[2][1], c[1][1]+c[2][0]});
	int x,y;
	if(t==c[0][0]+c[1][1])x=0,y=1;
	if(t==c[0][0]+c[2][1])x=0,y=2;
	if(t==c[0][1]+c[1][0])x=1,y=0;
	if(t==c[0][1]+c[2][0])x=2,y=0;
	if(t==c[1][0]+c[2][1])x=1,y=2;
	if(t==c[1][1]+c[2][0])x=2,y=1;
	fup(i,0,n-1,1){
		fup(j,0,n-1,1){
			if((i+j)%3==x && s[i][j]=='O')s[i][j]='X';
			if((i+j)%3==y && s[i][j]=='X')s[i][j]='O';
		}
	}
	fup(i,0,n-1,1)printf("%s\n",s[i]);
}
int main() {
	int tc;
	scanf("%d",&tc);
	while(tc--)solve();
}