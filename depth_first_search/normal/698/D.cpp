#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define K 7
#define N 1000
using namespace std;
int k,n,id[K+5];vector<int> P[K+5][N+5];
I int gcd(CI x,CI y) {return y?gcd(y,x%y):x;}
struct P
{
	int x,y;I P(CI a=0,CI b=0):x(a),y(b){}
	I long long L2() {return 1LL*x*x+1LL*y*y;}
	I P S() {RI d=gcd(abs(x),abs(y))*(x?(x>0?1:-1):(y>0?1:-1));return P(x/d,y/d);}
	I P operator - (Con P& o) Con {return P(x-o.x,y-o.y);}
	I bool operator < (Con P& o) Con {return x^o.x?x<o.x:y<o.y;}
	I bool operator == (Con P& o) Con {return x==o.x&&y==o.y;}
}s[K+5],p[N+5];
int nw,vis[N+5];I bool Check(CI x)
{
	if(nw>k) return 0;RI o=id[nw];vector<int>::iterator it;
	for(it=P[o][x].begin();it!=P[o][x].end();++it) if(!vis[*it]&&(++nw,!Check(*it))) return 0;
	return vis[x]=1;
}
int op;I bool cmp(CI x,CI y) {return (p[x]<p[y])==op;}
int main()
{
	RI i,j,u;for(scanf("%d%d",&k,&n),i=1;i<=k;++i) scanf("%d%d",&s[i].x,&s[i].y);
	for(i=1;i<=n;++i) scanf("%d%d",&p[i].x,&p[i].y);
	for(i=1;i<=k;++i) for(j=1;j<=n;op=s[i]<p[j],sort(P[i][j].begin(),P[i][j].end(),cmp),++j)
		for(u=1;u<=n;++u) j^u&&(s[i]-p[j]).S()==(s[i]-p[u]).S()&&(s[i]<p[u])==(p[u]<p[j])&&(P[i][j].push_back(u),0);
	RI fg,t=0;for(i=1;i<=n;t+=fg,++i) {for(j=1;j<=k;++j) id[j]=j;
		do {memset(vis,0,sizeof(vis)),nw=1,fg=Check(i);} W(!fg&&next_permutation(id+1,id+k+1));}
	return printf("%d\n",t),0;
}