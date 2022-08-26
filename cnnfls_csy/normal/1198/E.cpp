#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<ctime>
#include<set>
#include<map>
#include<queue>
#include<stack>
#define sqr(x) ((x)*(x))
#define fz1(i,n) for ((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for ((i)=(n);(i)>=1;(i)--)
#define fz0g(i,n) for ((i)=0;(i)<=(n);(i)++)
#define fd0g(i,n) for ((i)=(n);(i)>=0;(i)--)
#define fz0k(i,n) for ((i)=0;(i)<(n);(i)++)
#define fd0k(i,n) for ((i)=(long long)((n)-1);(i)>=0;(i)--)
#define fz(i,x,y) for ((i)=(x);(i)<=(y);(i)++)
#define fd(i,y,x) for ((i)=(y);(i)>=(x);(i)--)
#define fzin fz1(i,n)
#define fzim fz1(i,m)
#define fzjn fz1(j,n)
#define fzjm fz1(j,m)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
#define inc(x,y) {x+=(y);if(x>=mod)x-=mod;}
#define dec(x,y) {x-=(y);if(x<0)x+=mod;}
using namespace std;
const long long inf=0x3f3f3f3f3f3f3f3fll;
long long dis[505],cnt,s=0,t=501;
struct ed
{
	long long fr,to,c,re;
}e[1000005];
vector<long long> bi[505];
bool bfs(long long st,long long ed)
{
	long long i;
	queue<long long> qx;
	memset(dis,-1,sizeof(dis));
	dis[st]=0;
	qx.push(st);
	while (!qx.empty())
	{
		long long x=qx.front();
		qx.pop();
		for (i=0;i<bi[x].size();i++)
		{
			if (e[bi[x][i]].to!=st&&e[bi[x][i]].c>0&&dis[e[bi[x][i]].to]==-1)
			{
				dis[e[bi[x][i]].to]=dis[x]+1;
				qx.push(e[bi[x][i]].to);
			}
		}
	}
	if (dis[ed]==-1) return 0;
	return 1;
}
long long dfs(long long x,long long ed,long long flw)
{
	if (x==ed)
	{
		return flw;
	}
	long long i,res=0;
	for (i=0;i<bi[x].size();i++)
	{
		if (dis[x]+1==dis[e[bi[x][i]].to]&&e[bi[x][i]].c>0)
		{  
        	long long t=dfs(e[bi[x][i]].to,ed,min(e[bi[x][i]].c,flw));
    		e[bi[x][i]].c-=t;  
        	e[e[bi[x][i]].re].c+=t;  
        	flw-=t;  
        	res+=t;  
        	if (flw<1) break;  
    	}
	}
	if (res==0) dis[x]=-123456;
	return res;
}  
long long maxflow(long long st,long long ed)
{
	long long ans=0;
	while (bfs(st,ed)) ans+=dfs(st,ed,0x3f3f3f3f3f3f3f3fll);
	return ans;
}
void addedg(long long x,long long y,long long sz)
{
	cnt+=2;
	e[cnt-1]={x,y,sz,cnt};
	e[cnt]={y,x,0,cnt-1};
	bi[x].push_back(cnt-1);
	bi[y].push_back(cnt);
}
int n,m,i,j,px[105],py[105],qx[105],qy[105],lenx[105],leny[105],a[105][105];
vector<int> allx,ally;
int main()
{
	scanf("%d%d",&n,&m);
	fz1(i,m){
		scanf("%d%d%d%d",&px[i],&py[i],&qx[i],&qy[i]);
		allx.push_back(px[i]-1);
		allx.push_back(qx[i]);
		ally.push_back(py[i]-1);
		ally.push_back(qy[i]);
	}
	sort(allx.begin(),allx.end());allx.resize(unique(allx.begin(),allx.end())-allx.begin());
	sort(ally.begin(),ally.end());ally.resize(unique(ally.begin(),ally.end())-ally.begin());
	int numx=allx.size()-1,numy=ally.size()-1;
	for(i=1;i<allx.size();i++){
		lenx[i]=allx[i]-allx[i-1];
	}
	for(i=1;i<ally.size();i++){
		leny[i]=ally[i]-ally[i-1];
	}
	fz1(i,m){
		px[i]=upper_bound(allx.begin(),allx.end(),px[i]-1)-allx.begin();
		qx[i]=upper_bound(allx.begin(),allx.end(),qx[i])-allx.begin();
		py[i]=upper_bound(ally.begin(),ally.end(),py[i]-1)-ally.begin();
		qy[i]=upper_bound(ally.begin(),ally.end(),qy[i])-ally.begin();
		int x,y;
		fz(x,px[i],qx[i]-1){
			fz(y,py[i],qy[i]-1){
				a[x][y]=1;
			}
		}
	}
	fz1(i,numx){
		addedg(s,i,lenx[i]);
	}
	fz1(i,numy){
		addedg(i+250,t,leny[i]);
	}
	fz1(i,numx)fz1(j,numy)if(a[i][j]){
		addedg(i,j+250,inf);
	}
	printf("%d\n",maxflow(s,t));
	return 0;
}