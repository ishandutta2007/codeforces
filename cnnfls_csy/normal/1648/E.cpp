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
#include<cassert>
#define sqr(x) ((x)*(x))
#define fz1(i,n) for ((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for ((i)=(n);(i)>=1;(i)--)
#define fz0g(i,n) for ((i)=0;(i)<=(n);(i)++)
#define fd0g(i,n) for ((i)=(n);(i)>=0;(i)--)
#define fz0k(i,n) for ((i)=0;(i)<(n);(i)++)
#define fd0k(i,n) for ((i)=(((long long)(n))-1);(i)>=0;(i)--)
#define fz(i,x,y) for ((i)=(x);(i)<=(y);(i)++)
#define fd(i,y,x) for ((i)=(y);(i)>=(x);(i)--)
#define fzin fz1(i,n)
#define fzim fz1(i,m)
#define fzjn fz1(j,n)
#define fzjm fz1(j,m)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();++itr)
#define pb push_back
#define mk make_pair
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
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
namespace hashmap
{
	int hd[11234569];
	int nxt[200005],a[200005],b[200005],cnt;
	int f(int x,int y){return (2000007ll*x+y)%11234567;}
	void init(){int i;fz1(i,cnt) hd[f(a[i],b[i])]=nxt[i]=0;cnt=0;}
	void ins(int x,int y)
	{
		if(x>y)swap(x,y);int t=f(x,y);cnt++;
		nxt[cnt]=hd[t];hd[t]=cnt;a[cnt]=x;b[cnt]=y;
	}
	bool query(int x,int y)
	{
		if(x>y)swap(x,y);int t=f(x,y),i;
		for(i=hd[t];i;i=nxt[i])if(a[i]==x&&b[i]==y) return 1;
		return 0;
	}
}
int t,n,m,i,j,k,ans[200005],fat[200005],fac[200005];
struct ii{int x,y,z;}a[200005];bool cmp(ii x,ii y){return x.z<y.z;}
vector<int> con[200005];
set<int> sv[200005];
multiset<pair<int,int> > sq[200005];
int fndt(int x){if(x==fat[x])return x;return fat[x]=fndt(fat[x]);}
int fndc(int x){if(x==fac[x])return x;return fac[x]=fndc(fac[x]);}
int g[3005][3005],vis[200005];
void mercon(int x,int y,int z)
{
	if(sv[x].size()+sq[x].size()>sv[y].size()+sq[y].size()) swap(x,y);
	ff(sq[x],it){
		if(sv[y].count(it->first)){
			ans[it->second]=min(ans[it->second],z);
		}
		else{
			sq[y].insert(*it);
		}
	}
	ff(sv[x],it){
		sv[y].insert(*it);
	}
	fac[x]=y;
}
void solve()
{
	read(n);read(m);fz1(i,m)ans[i]=0x3f3f3f3f,read(a[i].x),read(a[i].y),read(a[i].z),hashmap::ins(a[i].x,a[i].y);
	fz1(i,n) fat[i]=fac[i]=i,con[i].clear(),con[i].push_back(i),sv[i].clear(),sv[i].insert(i),sq[i].clear();
	fz1(i,m) sq[a[i].x].insert(make_pair(a[i].y,i)),sq[a[i].y].insert(make_pair(a[i].x,i));
	sort(a+1,a+m+1,cmp);
	fz1(i,m)if(fndt(a[i].x)!=fndt(a[i].y)){
		int x=fndt(a[i].x),y=fndt(a[i].y);
		fz0k(j,con[x].size())fz0k(k,con[y].size()){
			g[j][k]=0;
			ff(sv[con[x][j]],it1){
				ff(sv[con[y][k]],it2)if(!hashmap::query(*it1,*it2)){
					g[j][k]=1;break;
				}
				if(g[j][k])break;
			}
		}
		fz0k(j,con[x].size())fz0k(k,con[y].size())if(g[j][k]&&fndc(con[x][j])!=fndc(con[y][k])){
			mercon(fndc(con[x][j]),fndc(con[y][k]),a[i].z);
		}
		fz0k(j,con[x].size()) vis[fndc(con[x][j])]=1;
		fz0k(j,con[y].size()) vis[fndc(con[y][j])]=1;
		vector<int> ncon,_;
		fz0k(j,con[x].size()) if(vis[fndc(con[x][j])]) vis[fndc(con[x][j])]=0,ncon.push_back(fndc(con[x][j]));
		fz0k(j,con[y].size()) if(vis[fndc(con[y][j])]) vis[fndc(con[y][j])]=0,ncon.push_back(fndc(con[y][j]));
		fat[y]=x;swap(con[x],ncon);swap(_,con[y]);
	}
	fz1(i,m)printf("%d%c",ans[i],spln(i,m));
}
int main()
{
	read(t);
	while(t--){
		hashmap::init();
		solve();
	}
	return 0;
}