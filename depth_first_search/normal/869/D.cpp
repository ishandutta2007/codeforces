#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define M 5
#define X 1000000007
#define LL long long
using namespace std;
LL n;int m,ans,p[M+5],vis[M+5];struct line {LL x,y;}s[M+5];
namespace T
{
	set<LL> vis,ex;I void Ins(LL x) {x&&ex.find(x)==ex.end()&&(ex.insert(x),Ins(x>>1),0);}
	I LL Sz(LL x) {if(!~x) return 0;LL l=x,r=x,t=1;W(l<<=1,(r<<=1)|=1,r<=n) t+=r-l+1;return l<=n&&(t+=n-l+1),t;}
	I bool Tg(LL x,LL y) {W(true) if(x<y&&(swap(x,y),0),vis.find(x)!=vis.end()) return 0;else if(vis.insert(x),x==y) return 1;else x>>=1;}
	I int Get(LL x,LL lst=-1)
	{
		if(!x||x>n||~lst&&vis.find(x)!=vis.end()) return 0;if(ex.find(x)==ex.end()) return Sz(x)%X;RI t=1;
		if(lst^(x>>1)) t=(t+Get(x>>1,x))%X;if(lst^(x<<1)) t=(t+Get(x<<1,x))%X;if(lst^(x<<1|1)) t=(t+Get(x<<1|1,x))%X;return t;
	}
	vector<LL> A,B;I bool GGG(LL a,LL b)
	{
		LL x=a,y=b,px,py;A.clear(),B.clear();W(true) if(x<y&&(swap(x,y),swap(px,py),swap(A,B),0),
			x^a&&x^b&&vis.find(x)!=vis.end()) return 0;else if(x^a&&x^b&&(A.push_back(Get((x<<2|1)-px,x)+1),0),x==y) break;else px=x,x>>=1;
		x^a&&x^b&&(A[A.size()-1]=Get(x>>1,x)+1);W(!B.empty()) A.push_back(B.back()),B.pop_back();return 1;
	}
	I void Calc(CI m)
	{
		RI i;for(vis.clear(),ex.clear(),i=1;i<=m;++i) Ins(s[p[i]].x),Ins(s[p[i]].y);
		for(vis.insert(s[p[1]].x),i=2;i<=m;++i) if(!Tg(s[p[i-1]].y,s[p[i]].x)) return;
		if(vis.find(s[p[m]].y)!=vis.end()) return;vis.insert(s[p[m]].y);
		ans=(ans+1LL*Get(s[p[1]].x)*Get(s[p[m]].y))%X;if(!GGG(s[p[1]].x,s[p[m]].y)) return;
		RI t=0;for(vector<LL>::iterator it=A.begin();it!=A.end();++it) t=(t+*it)%X,ans=(ans-(*it%X)*t%X+X)%X;
	}
}
I void dfs(CI lim,CI x=1)
{
	if(x>lim) return T::Calc(lim);for(RI i=1;i<=m;++i) !vis[i]&&(vis[p[x]=i]=1,dfs(lim,x+1),swap(s[i].x,s[i].y),dfs(lim,x+1),vis[i]=0);
}
int main()
{
	RI i;for(scanf("%lld%d",&n,&m),i=1;i<=m;++i) scanf("%lld%lld",&s[i].x,&s[i].y);
	for(i=1;i<=m;++i) dfs(i);return printf("%d\n",(ans+1LL*(n%X)*(n%X))%X),0;
}