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

int n, m,A[10001], B[10001], dist[10001];
bool used[10001]; 
vector<int> v[10001];
 
void bfs(){
    queue<int> q;
    for(int i=0; i<n; i++){
        if(!used[i]){
            dist[i] = 0;
            q.push(i);
        }
        else dist[i] = INF;
    }
 
    while(!q.empty()){
        int a = q.front();
        q.pop();
        for(int b: v[a]){
            if(B[b] != -1 && dist[B[b]] == INF){
                dist[B[b]] = dist[a] + 1;
                q.push(B[b]);
            }
        }
    }
}
 
bool dfs(int a){
    for(int b: v[a]){
        if(B[b] == -1 || dist[B[b]] == dist[a]+1 && dfs(B[b])){
            used[a] = true;
            A[a] = b;
            B[b] = a;
            return true;
        }
    }
    return false;
}
int match(){
	int res = 0;
	MEM_1(A);
	MEM_1(B);
	while(1){
		bfs();
			int flow = 0;
		for(int i=0; i<n; i++)
			if(!used[i] && dfs(i)) flow++;
			if(flow == 0) break;
		res += flow;
	}
	return res;
}
Pi p[100000];
int z[100000];
bool ok(int k){
	fup(i,0,n-1,1)v[i].clear();
	fup(i,0,m-1,1){
		if(z[i]<=k)v[p[i].X].pb(p[i].Y);
	}
	MEM0(used);
	if(match()==n)return 1;
	return 0;
}
int main(){
	scanf("%d%d",&n,&m);
	fup(i,0,m-1,1){
		scanf("%d%d%d",&p[i].X,&p[i].Y,&z[i]);
		p[i].X--,p[i].Y--;
	}
	int l=1,r=1e9;
	while(l<=r){
		int k=l+r>>1;
		if(ok(k))r=k-1;
		else l=k+1;
	}
	if(l>1e9)l=-1;
	printf("%d\n",l);
}