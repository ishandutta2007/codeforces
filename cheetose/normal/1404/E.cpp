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
const int MOD = 998244353;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

int A[40005], B[40005], dist[40005];
bool used[40005]; 
vector<int> v[40005];
 
bool bfs(int n){
	queue<int> q;
	bool ok = 0;
	memset(dist, 0, sizeof(dist));
	for(int i=0; i<n; i++){
		if(A[i] == -1 && !dist[i]){
			q.push(i);
			dist[i] = 1;
		}
	}
	while(!q.empty()){
		int x = q.front();
		q.pop();
		for(auto &i : v[x]){
			if(B[i] == -1) ok = 1;
			else if(!dist[B[i]]){
				dist[B[i]] = dist[x] + 1;
				q.push(B[i]);
			}
		}
	}
	return ok;
}
bool dfs(int x){
	if(used[x]) return 0;
	used[x] = 1;
	for(auto &i : v[x]){
		if(B[i] == -1 || (!used[B[i]] && dist[B[i]] == dist[x] + 1 && dfs(B[i]))){
			A[x] = i; B[i] = x;
			return 1;
		}
	}
	return 0;
}
int match(int n){
	memset(A, -1, sizeof(A));
	memset(B, -1, sizeof(B));
	int ret = 0;
	while(bfs(n)){
		memset(used, 0, sizeof(used));
		for(int i=0; i<n; i++) if(A[i] == -1 && dfs(i)) ret++;
	}
	return ret;
}

char s[205][205];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	fup(i,0,n-1,1)scanf("%s",s[i]);
	int cnt=0,tot=0;
	fup(i,0,n-1,1){
		fup(j,0,m-1,1){
			if(s[i][j]=='#'){
				cnt++;
				if(i<n && s[i+1][j]=='#')tot++;
				if(j<m && s[i][j+1]=='#')tot++;
			}
		}
	}
	fup(i,0,n-2,1){
		fup(j,0,m-1,1){
			if(s[i][j]=='#' && s[i+1][j]=='#'){
				if(j+1<m && s[i][j+1]=='#')v[i*m+j].pb(i*m+j);
				if(j+1<m && s[i+1][j+1]=='#')v[i*m+j].pb((i+1)*m+j);
				if(j>0 && s[i][j-1]=='#')v[i*m+j].pb(i*m+j-1);	
				if(j>0 && s[i+1][j-1]=='#')v[i*m+j].pb((i+1)*m+j-1);
			}
		}
	}
	printf("%d\n",cnt-tot+match(n*m));
}