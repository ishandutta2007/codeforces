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
const int MOD = 993244853;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

VPi v[1005];
bitset<1005> L[1005];
int parent[1005],depth[1005],t[1005];
int LCA[1005][1005];
int lca(int x,int y){
	if(x==y)return x;
	int &ret=LCA[x][y];
	if(~ret)return ret;
	if(depth[x]>depth[y])return ret=lca(parent[x],y);
	return ret=lca(x,parent[y]);
}
void dfs(int N,int p=-1)
{
	parent[N]=p;
	if(v[N].size()==1)
	{
		L[N][N]=1;
		return;
	}
	for(auto P:v[N])
	{
		if(P.X==p)continue;
		depth[P.X]=depth[N]+1;
		t[P.X]=P.Y;
		dfs(P.X,N);
		L[N]|=L[P.X];
	}
}
void upd(int x,int y,int c)
{
	int u=lca(x,y);
	int tt=x;
	while(tt!=u)
	{
		t[tt]-=c;
		tt=parent[tt];
	}
	tt=y;
	while(tt!=u)
	{
		t[tt]-=c;
		tt=parent[tt];
	}
}
int main() {
	MEM_1(LCA);
	int n;
	scanf("%d",&n);
	fup(i,1,n-1,1)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		v[x].pb(mp(y,z));
		v[y].pb(mp(x,z));
	}
	int R=-1;
	fup(i,1,n,1)
	{
		if(v[i].size()==2)
		{
			if(v[i][0].Y!=v[i][1].Y)return !printf("NO");
		}
		if(v[i].size()>2)R=i;
	}
	if(R==-1)
	{
		puts("YES");
		puts("1");
		int x=-1,y=-1;
		fup(i,1,n,1)if(v[i].size()==1)
		{
			y=x,x=i;
		}
		return !printf("%d %d %d\n",x,y,v[1][0].Y);
	}
	dfs(R);
	Vi vv;
	fup(i,1,n,1)
	{
		if(v[i].size()==1 && t[i]&1)vv.pb(i);
	}
	if(vv.size()&1)return !printf("NO");
	fup(i,0,(int)vv.size()-2,2)
	{
		upd(vv[i],vv[i+1],1);
	}
	fup(i,1,n,1)
	{
		if(i==R)continue;
		if(t[i]&1)return !printf("NO");
	}
	puts("YES");
	VLLL ans;
	fup(i,0,(int)vv.size()-2,2)ans.pb(iii(vv[i],vv[i+1],1));
	Vi leaf;
	fup(i,1,n,1)
	{
		if(v[i].size()==1)leaf.pb(i);
	}
	fup(i,1,(int)leaf.size()-1,1)
	{
		int x=leaf[0],y=leaf[i];
		int c=t[y];
		upd(x,y,c);
		ans.pb(iii(x,y,c));
	}
	if(t[leaf[0]]!=0)
	{
		int w=leaf[0],x=leaf[1],y=leaf[2];
		int z=t[w]/2;
		upd(w,x,z);
		upd(w,y,z);
		upd(x,y,-z);
		ans.pb(iii(w,x,z));
		ans.pb(iii(w,y,z));
		ans.pb(iii(x,y,-z));
	}
	fup(i,1,n,1)
	{
		if(t[i]==0 || v[i].size()==2)continue;
		int a=-1,b=-1,c=-1,d=-1;
		int z=t[i]/2;
		for(Pi P:v[i])
		{
			if(P.X==parent[i])continue;
			fup(j,1,n,1)
			{
				if(L[P.X][j])
				{
					if(a==-1)a=j;
					else if(b==-1)b=j;
					break;
				}
			}
			if(b!=-1)break;
		}
		int last=i,now=parent[i];
		while(1)
		{
			for(Pi P:v[now])
			{
				if(P.X==last || P.X==parent[now])continue;
				fup(j,1,n,1)
				{
					if(L[P.X][j])
					{
						if(c==-1)c=j;
						else if(d==-1)d=j;
						break;
					}
				}
				if(d!=-1)break;
			}
			if(d!=-1)break;
			last=now;
			now=parent[now];
		}
		ans.pb(iii(a,c,z));
		ans.pb(iii(b,d,z));
		ans.pb(iii(a,b,-z));
		ans.pb(iii(c,d,-z));
	}
	printf("%d\n",ans.size());
	for(auto I:ans)
	{
		int x,y,z;
		tie(x,y,z)=I;
		printf("%d %d %d\n",x,y,z);
	}
}