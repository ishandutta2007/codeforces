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

int a[2000],d[2000],p[2000];
int main(){
	MEM_1(d);
	int n;
	scanf("%d",&n);
	fup(i,0,2*n-1,1)scanf("%d",a+i),a[i]--;
	queue<int> q;
	fup(i,0,2*n-1,1){
		if(a[i]==0){
			q.push(i);
			d[i]=0;
		}
	}
	while(!q.empty()){
		int x=q.front();
		q.pop();
		if(d[x^1]==-1){
			d[x^1]=d[x]+1;
			p[x^1]=x;
			q.push(x^1);
		}
		if(x<n){
			if(d[x+n]==-1){
				d[x+n]=d[x]+1;
				p[x+n]=x;
				q.push(x+n);
			}
		}else{
			if(d[x-n]==-1){
				d[x-n]=d[x]+1;
				p[x-n]=x;
				q.push(x-n);
			}
		}
	}
	int x=0;
	Vi st;
	while(a[x]){
		st.pb(x);
		x=p[x];
	}
	while(!st.empty()){
		int y=st.back();
		st.pop_back();
		if(abs(x-y)==1){
			fup(i,0,2*n-1,2)swap(a[i],a[i+1]);
		}else{
			rotate(a,a+n,a+2*n);
		}
		x=y;
	}
	fup(i,0,2*n-1,1)if(a[i]!=i)return !printf("-1\n");
	printf("%d\n",d[0]);
}