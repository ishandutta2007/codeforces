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
int t,n,m,i,j,deg[200005],f[200005][2],fa[200005];
vector<int> bi[200005];
vector<pair<int,int> > ans;
bool ok=1;
void dfs2(int x,int fa)
{
	if(bi[x].size()-!!fa==0){
		ans.push_back(make_pair(x,fa));
		;return;
	}
	int c0=0,c1=0,cc=0;
	vector<int> v0,v1,vc;
	ff(bi[x],it)if(*it!=fa){
		if(!f[*it][0]&&!f[*it][1]){
			ok=0;return;
		}
		if(f[*it][0]&&f[*it][1]) cc++,vc.push_back(*it);
		else if(f[*it][0])c0++,v0.push_back(*it);
		else c1++,v1.push_back(*it);
	}
	if(f[x][0]){
		v0.push_back(fa);
	}
	else{
		v1.push_back(fa);
	}
	int tmp=deg[x],fg=1;
	vector<int> res;
	while(tmp){
		if(tmp%2==0){
			if(v0.size()) res.push_back(v0.back()),v0.pop_back();
			else if(vc.size()) res.push_back(vc.back()),vc.pop_back(); else fg=0;
		}
		else{
			if(v1.size()) res.push_back(v1.back()),v1.pop_back();
			else if(vc.size()) res.push_back(vc.back()),vc.pop_back(); else fg=0;
		}
		tmp--;
	}
	assert(fg);
	ff(res,it) if(*it==fa) ans.push_back(make_pair(x,fa)); else dfs2(*it,x);
}
void dfs(int x,int fa)
{
	f[x][0]=f[x][1]=0;::fa[x]=fa;
	if(bi[x].size()-!!fa==0){
		f[x][1]=1;return;
	}
	int c0=0,c1=0,cc=0;
	vector<int> v0,v1,vc;
	ff(bi[x],it)if(*it!=fa){
		dfs(*it,x);
		if(!f[*it][0]&&!f[*it][1]){
			ok=0;return;
		}
		if(f[*it][0]&&f[*it][1]) cc++,vc.push_back(*it);
		else if(f[*it][0])c0++,v0.push_back(*it);
		else c1++,v1.push_back(*it);
	}
	if(x!=1){
		int tmp=deg[x],t0=c0+1,t1=c1,tc=cc,fg=1;
		while(tmp){
			if(tmp%2==0){
				if(t0) t0--; else if(tc) tc--; else fg=0;
			}
			else{
				if(t1) t1--; else if(tc) tc--; else fg=0;
			}
			tmp--;
		}
		f[x][0]=fg;
		tmp=deg[x],t0=c0,t1=c1+1,tc=cc,fg=1;
		while(tmp){
			if(tmp%2==0){
				if(t0) t0--; else if(tc) tc--; else fg=0;
			}
			else{
				if(t1) t1--; else if(tc) tc--; else fg=0;
			}
			tmp--;
		}
		f[x][1]=fg;
	}
	else{
		int tmp=deg[x],fg=1;
		vector<int> res;
		while(tmp){
			if(tmp%2==0){
				if(v0.size()) res.push_back(v0.back()),v0.pop_back();
				else if(vc.size()) res.push_back(vc.back()),vc.pop_back(); else fg=0;
			}
			else{
				if(v1.size()) res.push_back(v1.back()),v1.pop_back();
				else if(vc.size()) res.push_back(vc.back()),vc.pop_back(); else fg=0;
			}
			tmp--;
		}
		if(!fg){
			ok=0;return;
		}
		ff(res,it) dfs2(*it,x);
	} 
}
int main()
{
	read(t);
	while(t--){
		read(n);fz1(i,n) bi[i].clear(),deg[i]=0;
		fz1(i,n-1){
			int x,y;read(x);read(y);
			bi[x].push_back(y);
			bi[y].push_back(x);
			deg[x]++;deg[y]++;
		}
		ok=1;
		ans.clear();
		dfs(1,0);
		if(ok==0){
			puts("NO");
		}
		else{
			puts("YES");
			ff(ans,it) printf("%d %d\n",it->first,it->second);
		}
	}
	return 0;
}