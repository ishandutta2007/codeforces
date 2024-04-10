#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 200000
#define add(x,y) (e[++ee].nxt=lnk[x],e[lnk[x]=ee].to=y)
using namespace std;
int n,ans,ee,lnk[N+5];struct edge {int to,nxt;}e[2*N+5];
I bool cmp(CI x,CI y) {return x>y;}
vector<int> v[N+5];I int dfs(CI x=1,CI lst=0)
{
	v[x].clear();for(RI i=lnk[x];i;i=e[i].nxt)
		e[i].to^lst&&(v[x].push_back(dfs(e[i].to,x)+1),0);
	if(sort(v[x].begin(),v[x].end(),cmp),x==1)
		return ans=max(ans,v[x][0]),v[x].size()>1&&(ans=max(ans,v[x][1]+1));
	if(v[x].empty()) return 0;if(v[x].size()==1) return v[x][0];
	return ans=max(ans,v[x][0]+1),v[x].back();
}
int main()
{
	RI Tt,i,x,y;scanf("%d",&Tt);W(Tt--)
	{
		for(scanf("%d",&n),ee=0,i=1;i<=n;++i) lnk[i]=0;
		for(i=1;i^n;++i) scanf("%d%d",&x,&y),add(x,y),add(y,x);
		ans=0,x=dfs(),printf("%d\n",ans);
	}return 0;
}