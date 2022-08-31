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
int t,n,m,i,j,a[100005],b[100005],dfn[100005],low[100005],col[100005],ti,cnt,vis[100005],sz[100005],ans[100005],ord[100005],rd[100005];
bool cmpa(int x,int y){return a[x]>a[y];}
bool cmpb(int x,int y){return b[x]>b[y];}
vector<int> bi[100005],stk,zbi[100005];
void tarjan(int x)
{
	stk.push_back(x);dfn[x]=low[x]=++ti;
	ff(bi[x],it){
		if(!dfn[*it]) tarjan(*it),low[x]=min(low[x],low[*it]); else if(!col[*it]) low[x]=min(low[x],dfn[*it]);
	}
	if(dfn[x]==low[x]){
		cnt++;
		while(stk.back()!=x){
			col[stk.back()]=cnt;stk.pop_back();
		}
		col[stk.back()]=cnt;stk.pop_back();
	}
}
int main()
{
	read(t);
	while(t--){
		read(n);fz1(i,n)read(a[i]);fz1(i,n)read(b[i]);
		fz1(i,n)bi[i].clear(),zbi[i].clear(),sz[i]=0,ans[i]=0,vis[i]=0,dfn[i]=col[i]=0,rd[i]=0;
		fz1(i,n) ord[i]=i;
		sort(ord+1,ord+n+1,cmpa);
		fz1(i,n-1) bi[ord[i]].push_back(ord[i+1]);
		sort(ord+1,ord+n+1,cmpb);
		fz1(i,n-1) bi[ord[i]].push_back(ord[i+1]);
		ti=0;cnt=0;
		fz1(i,n) if(!dfn[i]) tarjan(i);
		fz1(i,n)ff(bi[i],it)if(col[i]!=col[*it]) rd[col[*it]]++;
		fz1(i,n){
			ans[i]=!rd[col[i]];
			printf("%d",ans[i]);
		}
		puts("");
	}
	return 0;
}