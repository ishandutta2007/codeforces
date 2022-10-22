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
int n;vector<int> A[N+5],B[N+5];vector<int>::iterator ti,tj;
int ee,c[N+5],lnk[N+5];struct edge {int to,nxt;}e[4*N+5];
I void Col(CI x) {for(RI i=lnk[x];i;i=e[i].nxt) !~c[e[i].to]&&(c[e[i].to]=c[x]^1,Col(e[i].to),0);}
int main()
{
	RI i,x,y;for(scanf("%d",&n),i=1;i<=n;++i)
		scanf("%d%d",&x,&y),A[x].push_back(i),B[y].push_back(i);
	for(i=1;i<=N;++i) if(A[i].size())
	{
		ti=tj=A[i].begin(),A[i].size()&1&&(++ti,++tj,0);
		W(ti!=A[i].end()) ++tj,add(*ti,*tj),add(*tj,*ti),++ti,++ti,++tj;
	}
	for(i=1;i<=N;++i) if(B[i].size())
	{
		ti=tj=B[i].begin(),B[i].size()&1&&(++ti,++tj,0);
		W(ti!=B[i].end()) ++tj,add(*ti,*tj),add(*tj,*ti),++ti,++ti,++tj;
	}
	for(memset(c,-1,sizeof(c)),i=1;i<=n;++i)
		!~c[i]&&(c[i]=1,Col(i),0),putchar(c[i]?'r':'b');return 0;
}