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

int A[2][100005],B[2][100005],T[2][100005];
char s[2][100005];
int main(){
	fup(i,0,1,1)scanf("%s",s[i]+1);
	int n=strlen(s[0]+1),m=strlen(s[1]+1);
	fup(i,1,n,1){
		A[0][i]=A[0][i-1], B[0][i]=B[0][i-1];
		if(s[0][i]=='A')A[0][i]++,T[0][i]=T[0][i-1]+1;
		else B[0][i]++;
	}
	fup(i,1,m,1){
		A[1][i]=A[1][i-1], B[1][i]=B[1][i-1];
		if(s[1][i]=='A')A[1][i]++,T[1][i]=T[1][i-1]+1;
		else B[1][i]++;
	}
	int q;
	scanf("%d",&q);
	while(q--){
		int l,r,x,y;
		scanf("%d%d%d%d",&l,&r,&x,&y);
		int a1=A[0][r]-A[0][l-1],b1=B[0][r]-B[0][l-1],t1=min(T[0][r],r-l+1);
		int a2=A[1][y]-A[1][x-1],b2=B[1][y]-B[1][x-1],t2=min(T[1][y],y-x+1);
		if((b1+b2)%2 || b1>b2){
			putchar('0');
			continue;
		}
		if(!b1 && !b2){
			putchar(t1>=t2 && t1%3==t2%3?'1':'0');
		}else if(!b1 && b2){
			putchar(t1>t2?'1':'0');
		}else if(b1==b2){
			putchar(t1>=t2 && t1%3==t2%3?'1':'0');
		}else{
			putchar(t1>=t2?'1':'0');
		}
	}
}