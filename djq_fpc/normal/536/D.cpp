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
#include<bitset>
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
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();++itr)
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
#define incm(x,y) {x=((x)+(y))%mod;}
#define spln(i,n) (i==n?'\n':' ')
#define fac_init(n){fac[0]=fac[1]=inv[1]=fi[0]=fi[1]=1;fz(i,2,n){fac[i]=1ll*fac[i-1]*i%mod;inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;fi[i]=1ll*fi[i-1]*inv[i]%mod;}}
#define fi first
#define se second
#define mk make_pair
using namespace std;
inline void read(int &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
inline void read(long long &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
int n,m,i,j,a[2005];
int nxtf[2005][2005],nxtg[2005][2005];
long long f[2005][2005],g[2005][2005],disx[2005],disy[2005];
vector<long long> allx,ally;
vector<pair<int,int> > bi[2005];
vector<int> vx[2005],vy[2005];
void sssp(long long *dis,int s)
{
	dis[s]=0;priority_queue<pair<long long,int> > qx;qx.push(make_pair(0,s));
	while(!qx.empty()){
		int x=qx.top().second;long long d=qx.top().first;qx.pop();
		if(dis[x]!=-d) continue;
		ff(bi[x],it){
			int y=it->first;long long z=it->second+dis[x];
			if(dis[y]>z){
				dis[y]=z;
				qx.push(make_pair(-z,y));
			}
		}
	}
}
int main()
{
	read(n);read(m);
	int s,t;read(s);read(t);
	memset(f,-0x3f,sizeof(f));
	memset(g,0x3f,sizeof(g));
	fz1(i,n) read(a[i]);
	fz1(i,m){
		int x,y,z;
		read(x);read(y);read(z);
		bi[x].push_back(make_pair(y,z));
		bi[y].push_back(make_pair(x,z));
	}
	memset(disx,0x3f,sizeof(disx));
	memset(disy,0x3f,sizeof(disy));
	sssp(disx,s);sssp(disy,t);
	fz1(i,n){
		allx.push_back(disx[i]);
		ally.push_back(disy[i]);
	}
	sort(allx.begin(),allx.end());allx.resize(unique(allx.begin(),allx.end())-allx.begin());
	sort(ally.begin(),ally.end());ally.resize(unique(ally.begin(),ally.end())-ally.begin());
	fz1(i,n){
		disx[i]=upper_bound(allx.begin(),allx.end(),disx[i])-allx.begin();
		disy[i]=upper_bound(ally.begin(),ally.end(),disy[i])-ally.begin();
		vx[disx[i]].push_back(i);
		vy[disy[i]].push_back(i);
	}
	fd(i,n,0)fd(j,n,0){
		nxtf[i][j]=(i<n?nxtf[i+1][j]:n+1);
		ff(vx[i+1],it) if(disy[*it]>j) nxtf[i][j]=i+1;
		nxtg[i][j]=(j<n?nxtg[i][j+1]:n+1);
		ff(vy[j+1],it) if(disx[*it]>i) nxtg[i][j]=j+1;
	}
	fd(i,n,0)fd(j,n,0){
		int k;
		k=nxtf[i][j];
		if(k>n){
			f[i][j]=0;
		}
		else{
			f[i][j]=max(f[k][j],g[k][j]);
			ff(vx[k],it) if(disy[*it]>j) f[i][j]+=a[*it];
		}
		k=nxtg[i][j];
		if(k>n){
			g[i][j]=0;
		}
		else{
			g[i][j]=min(f[i][k],g[i][k]);
			ff(vy[k],it) if(disx[*it]>i) g[i][j]-=a[*it];
		}
	}
	if(f[0][0]<0) puts("Cry");
	if(f[0][0]>0) puts("Break a heart");
	if(f[0][0]==0) puts("Flowers");
	return 0;
}