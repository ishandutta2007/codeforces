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
#define inc(x,y) {x+=(y);if(x>=mod)x-=mod;}
#define dec(x,y) {x-=(y);if(x<0)x+=mod;}
#define incm(x,y) {x=((x)+(y))%mod;}
#define spln(i,n) (i==n?'\n':' ')
#define fac_init(n){fac[0]=fac[1]=inv[1]=fi[0]=fi[1]=1;fz(i,2,n){fac[i]=1ll*fac[i-1]*i%mod;inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;fi[i]=1ll*fi[i-1]*inv[i]%mod;}}
using namespace std;
inline void read(int &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
const int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};
int _,n,m,i,j,k,a[100005],dis[100015],s=0,t=100001,ss=100002,tt=100003,l[100015];
int dir[100005],res[100005];int px[2000005],py[2000005],pdx[2000005],pdy[2000005];
int id(int x,int y)
{
	return (x-1)*m+y;
}
vector<int> bi[100015];
struct ii
{
	int y,z;
}e[2000005];int tot;
void init()
{
	int i;
	fz1(i,tot) px[i]=py[i]=pdx[i]=pdy[i]=0;
	tot=0;memset(l,0,sizeof(l));
	fz0g(i,tt) bi[i].clear();
}
void add(int x,int y,int z)
{
	tot++;bi[x].push_back(tot+tot-2);bi[y].push_back(tot+tot-1);
	e[tot+tot-2]=(ii){y,z};e[tot+tot-1]=(ii){x,0};
}
bool bfs(int s,int t)
{
	memset(dis,0x3f,sizeof(dis));
	dis[s]=0;queue<int> qx;qx.push(s);
	while(!qx.empty()){
		int x=qx.front();qx.pop();
		ff(bi[x],it)if(e[*it].z&&dis[e[*it].y]>dis[x]+1){
			dis[e[*it].y]=dis[x]+1;qx.push(e[*it].y);
		}
	}
	return dis[t]<dis[100014];
}
int dfs(int x,int tt,int flw)
{
	if(x==tt||!flw) return flw;
	int ans=0;
	ff(bi[x],it)if(dis[x]+1==dis[e[*it].y]&&e[*it].z){
		int t=dfs(e[*it].y,tt,min(flw,e[*it].z));
		//cerr<<x<<' '<<e[*it].y<<' '<<e[*it].z<<' '<<t<<' '<<*it<<endl;
		ans+=t;flw-=t;e[*it].z-=t;e[(*it)^1].z+=t;
	}
	if(flw) dis[x]=-1;
	return ans;
}
int dinic(int s,int t)
{
	int ans=0;
	while(bfs(s,t)){
		ans+=dfs(s,t,0x3f3f3f3f);
	}
	return ans;
}
int main()
{
	read(_);
	while(_--){
		read(n);read(m);
		fz1(i,n)fz1(j,m)read(a[id(i,j)]);
		init();add(t,s,0x3f3f3f3f);
		fz1(i,n*m){
			dir[i]=res[i]=0;
		}
		fz1(i,n)fz1(j,m){
			bool f=0;
			fz0k(k,4){
				int x=i+dx[k],y=j+dy[k];
				if(x<1||x>n||y<1||y>m) continue;
				if(a[id(i,j)]==a[id(x,y)]&&((i+j)&1)){
					add(id(i,j),id(x,y),1);
					px[tot]=id(i,j);py[tot]=id(x,y);
					pdx[tot]=k;pdy[tot]=(k^2);
				}
				if(a[id(i,j)]>a[id(x,y)]){
					dir[id(i,j)]=k;
					res[id(i,j)]=a[id(i,j)]-a[id(x,y)];
					f=1;
				}
			}
			if((i+j)&1){
				if(!f){
					l[s]--;l[id(i,j)]++;
				}
				else add(s,id(i,j),1); 
			}
			else{
				if(!f){
					l[id(i,j)]--;l[t]++;
				}
				else add(id(i,j),t,1);
			}
		}
		int sum=0,ctot=tot;
		fz0g(i,t){
			if(l[i]>0){
				add(ss,i,l[i]);
				sum+=l[i];
			}
			if(l[i]<0){
				add(i,tt,-l[i]);
			}
		}
		int ans=dinic(ss,tt);
		if(ans!=sum){
			puts("NO");continue;
		}
		puts("YES");
		fz(i,2,ctot)if(e[i+i-1].z){
			dir[px[i]]=pdx[i];dir[py[i]]=pdy[i];
			res[px[i]]=1;res[py[i]]=a[py[i]]-1;
		}
		fz1(i,n){
			fz1(j,m){
				printf("%d%c",res[id(i,j)],spln(j,m));
			}
		}
		fz1(i,n){
			fz1(j,m){
				printf("%c%c",dir[id(i,j)]["ULDR"],spln(j,m));
			}
		}
	}
	return 0;
}