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
const int MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

char s[200005];
struct T{
	int a[5][5];
	T(){
		MEM_1(a);
		fup(i,0,4,1)a[i][i]=0;
	}
}tree[524288];
T merge(T t1,T t2){
	T res;
	fup(i,0,4,1)res.a[i][i]=-1;
	fup(i,0,4,1){
		fup(j,i,4,1){
			if(t1.a[i][j]==-1)continue;
			fup(k,j,4,1){
				if(t2.a[j][k]==-1)continue;
				if(res.a[i][k]==-1)res.a[i][k]=t1.a[i][j]+t2.a[j][k];
				else res.a[i][k]=min(res.a[i][k],t1.a[i][j]+t2.a[j][k]);
			}
		}
	}
	return res;
}
void init(int node,int S,int E){
	if(S==E){
		if(s[S]=='2'){
			tree[node].a[0][0]=1;
			tree[node].a[0][1]=0;
		}
		if(s[S]=='0'){
			tree[node].a[1][1]=1;
			tree[node].a[1][2]=0;
		}
		if(s[S]=='1'){
			tree[node].a[2][2]=1;
			tree[node].a[2][3]=0;
		}
		if(s[S]=='6'){
			tree[node].a[3][3]=1;
			tree[node].a[4][4]=1;
		}
		if(s[S]=='7'){
			tree[node].a[3][3]=1;
			tree[node].a[3][4]=0;
		}
		return;
	}
	init(node*2,S,(S+E)/2);init(node*2+1,(S+E)/2+1,E);
	tree[node]=merge(tree[node*2],tree[node*2+1]);
}
T find(int node,int S,int E,int i,int j){
	T tmp;
	tmp.a[4][0]=-2;
	if (i > E || j < S)return tmp;
	if (i <= S && j >= E)return tree[node];
	T L=find(node*2,S,(S+E)/2,i,j),R=find(node*2+1,(S+E)/2+1,E,i,j);
	if(L.a[4][0]==-2)return R;
	if(R.a[4][0]==-2)return L;
	return merge(L,R);
}
int main(){
	int n,q;
	scanf("%d%d",&n,&q);
	scanf("%s",s+1);
	init(1,1,n);
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		T res=find(1,1,n,x,y);
		printf("%d\n",res.a[0][4]);
	}
}