#include<bits/stdc++.h>
//#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ALL(x) (x).begin(),(x).end()
#define rALL(x) (x).rbegin(),(x).rend()
#define srt(x) sort(ALL(x))
#define rev(x) reverse(ALL(x))
#define rsrt(x) sort(rALL(x))
#define sz(x) (int)(x.size())
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define lb(v,x) (lower_bound(ALL(v),x)-v.begin())
#define ub(v,x) (upper_bound(ALL(v),x)-v.begin())
void die(string S){puts(S.c_str());exit(0);}
pii fa[3030][6030];
int siz[3030][6030];
int cntl[3030][6030],cntr[3030][6030];
const pii _1=mp(-1,-1);
pii anc(pii p)
{
	if(fa[p.first][p.second]==_1)
		return p;
	return anc(fa[p.first][p.second]);
}
vector<pair<pii,pii> > vp;
inline bool add_edge(pii a,pii b)
{
	a=anc(a);
	b=anc(b);
	if(a==b)
		return false;
	if(siz[a.first][a.second]>siz[b.first][b.second])
		swap(a,b);
	fa[a.first][a.second]=b;
	siz[b.first][b.second]+=siz[a.first][a.second];
	vp.pb(mp(a,b));
	return true;
}
inline void del_edge()
{
	fa[vp.back().first.first][vp.back().first.second]=_1;
	pii a=vp.back().first;
	pii b=vp.back().second;
	siz[b.first][b.second]-=siz[a.first][a.second];
	vp.pop_back();
	return ;
}
bool vis[3030][6030];
const int dx[]={0,0,1,1,1,-1,-1,-1};
const int dy[]={1,-1,1,0,-1,1,0,-1};
int main()
{
	for(int i=0;i<3030;i++)
		for(int j=0;j<6030;j++)
		{
			fa[i][j]=_1;
			siz[i][j]=1;
		}
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	int ans=k;
	while(k--)
	{
		pii pos;
		scanf("%d%d",&pos.first,&pos.second);
		vis[pos.first][pos.second]=1;
		int cnt=0;
		for(int d=0;d<8;d++)
		{
			int nx=pos.first+dx[d];
			int ny=pos.second+dy[d];
			if(ny==0)
				ny=m+m;
			if(ny==m+m+1)
				ny=1;
			if(vis[nx][ny])
				cnt+=add_edge(pos,mp(nx,ny));
		}
		pos.second+=m;
		vis[pos.first][pos.second]=1;
		for(int d=0;d<8;d++)
		{
			int nx=pos.first+dx[d];
			int ny=pos.second+dy[d];
			if(ny==0)
				ny=m+m;
			if(ny==m+m+1)
				ny=1;
			if(vis[nx][ny])
				cnt+=add_edge(pos,mp(nx,ny));
		}
		pii p2=pos;
		p2.second-=m;
		if(anc(pos)==anc(p2))
		{
			while(cnt--)
				del_edge();
			vis[pos.first][pos.second]=0;
			vis[p2.first][p2.second]=0;
			ans--;
		}
	}
	cout<<ans<<endl;
	return 0;
}