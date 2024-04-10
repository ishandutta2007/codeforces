#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 1000
#define LL long long
using namespace std;
int n,p[N+5];LL v[13];vector<int> V;
int t;void dfs(RI x,RI s=0,RI c=0)
{
	if(t==n||c+13-x<6||c>6) return;if(x==13) return (void)(p[++t]=s);
	dfs(x+1,s<<1,c),dfs(x+1,s<<1|1,c+1);
}
I LL Q(vector<int>& V)
{
	if(V.empty()) return 0;printf("? %d ",(int)V.size());
	for(vector<int>::iterator it=V.begin();it!=V.end();++it) printf("%d ",*it);putchar('\n'),fflush(stdout);
	LL t;scanf("%lld",&t);return t;
}
int main()
{
	RI i,j;for(scanf("%d",&n),dfs(0),j=0;j^13;++j) {for(V.clear(),i=1;i<=n;++i) p[i]>>j&1&&(V.push_back(i),0);v[j]=Q(V);}
	LL t;for(printf("! "),i=1;i<=n;++i) {for(t=j=0;j^13;++j) !(p[i]>>j&1)&&(t|=v[j]);printf("%lld ",t);}return 0;
}