#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<queue>
#include<bitset>
#include<string>
#include<stack>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
#include<cstring>
#include<complex>
#include<cmath>
#include<iomanip>
#include<numeric>
#include<algorithm>
#include<list>
#include<functional>
#include<cassert>
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
const ll MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };

VPi vv[601];
int dist[601][601],n,m,t,k;
bool chk[601];
void dij(int S)
{
	MEM0(chk);
	priority_queue<Pi> q;
	fup(i,0,n-1,1)dist[S][i]=INF;
	dist[S][S] = 0;
	q.push({ 0,S });
	while (!q.empty())
	{
		int x = q.top().Y;
		q.pop();
		if (chk[x])continue;
		chk[x] = 1;
		for (const auto& p : vv[x])
		{
			int next = p.X, cost = p.Y;
			if (dist[S][next] > dist[S][x]+cost)
			{
				dist[S][next] = dist[S][x] + cost;
				q.push({ -dist[S][next],next });
			}
		}
	}
}
int A[601], B[601], Dist[601];
bool used[601]; 
Vi v[601];
void bfs(){
    queue<int> q;
    for(int i=0; i<t; i++){
        if(!used[i]){
            Dist[i] = 0;
            q.push(i);
        }
        else Dist[i] = INF;
    }
 
    while(!q.empty()){
        int a = q.front();
        q.pop();
        for(int b: v[a]){
            if(B[b] != -1 && Dist[B[b]] == INF){
                Dist[B[b]] = Dist[a] + 1;
                q.push(B[b]);
            }
        }
    }
}

bool dfs(int a){
    for(int b: v[a]){
        if(B[b] == -1 || Dist[B[b]] == Dist[a]+1 && dfs(B[b])){
            used[a] = true;
            A[a] = b;
            B[b] = a;
            return true;
        }
    }
    return false;
}
int a[201];
bool ok(int mid)
{
	fup(i,0,t-1,1)v[i].clear();
	fup(i,0,t-1,1)
	{
		int x=a[i];
		fup(j,0,n-1,1)if(dist[x][j]<=mid)
		{
			v[i].pb(j);
		}
	}
	int match = 0;
	MEM0(used);
	MEM_1(A);
	MEM_1(B);
	while(1){
		bfs();

		int flow = 0;
		for(int i=0; i<t; i++)
			if(!used[i] && dfs(i)) flow++;

		if(flow == 0) break;
		match += flow;
	}
	return match>=k;
}
int main() {
	scanf("%d%d%d%d",&n,&m,&t,&k);
	fup(i,0,t-1,1)scanf("%d",a+i),a[i]--;
	fup(i,1,m,1)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		x--,y--;
		vv[x].pb(mp(y,z));
		vv[y].pb(mp(x,z));
	}
	fup(i,0,n-1,1)dij(i);
	int l=0,r=1731311;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(ok(mid))r=mid-1;
		else l=mid+1;
	}
	if(l>1731311)l=-1;
	printf("%d",l);
}