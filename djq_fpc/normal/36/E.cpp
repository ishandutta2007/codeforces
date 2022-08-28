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
int n,m,i,j,deg[10005],cnt,ce,vis[20005];
int hd[10005],nxt[40005],to[40005],id[40005];
vector<int> v,vv;
vector<int> ans[2];
void add(int x,int y,int z)
{
	ce++;
	nxt[ce]=hd[x];hd[x]=ce;
	to[ce]=y;id[ce]=z;
}
void dfs(int x)
{
	while(hd[x]){
		while(hd[x]&&vis[id[hd[x]]]) hd[x]=nxt[hd[x]];
		if(!hd[x]) break;
		int t=hd[x];
		vis[id[t]]=1;hd[x]=nxt[hd[x]];
		dfs(to[t]);
		v.push_back(id[t]);
	}
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	read(m);
	if(m<=1){
		puts("-1");
		return 0;
	}
	fz1(i,m){
		int x,y;
		read(x);read(y);
		add(x,y,i);add(y,x,i);
		deg[x]++;deg[y]++;
	}
	int te=m;
	fz1(i,10000)if(deg[i]&1){
		te++;
		add(0,i,te);add(i,0,te);
	}
	fz0g(i,10000)if(hd[i]){
		v.clear();vv.clear(); 
		dfs(i);
		v.push_back(123456789);
		ff(v,it){
			if(*it>m){
				if(vv.empty()) continue;
				if(cnt>=2){
					puts("-1"); 
					return 0;
				}
				ans[cnt]=vv;
				cnt++;
				vv.clear();
			}
			else vv.push_back(*it);
		}
	}
	if(cnt==1){
		ans[1].push_back(ans[0].back());
		ans[0].pop_back();
	}
	printf("%d\n",ans[0].size());
	ff(ans[0],it) printf("%d ",*it);puts("");
	printf("%d\n",ans[1].size());
	ff(ans[1],it) printf("%d ",*it);puts("");
	return 0;
}