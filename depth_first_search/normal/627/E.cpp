#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 3000
#define K 10
#define LL long long
using namespace std;
int r,c,n,k,cnt[N+5],pre[N+5],nxt[N+5],C[N+5],v[N+5][N+5];struct P {int x,y;}p[N+5];
int main()
{
	RI i,j,s,x,y;for(cin>>r>>c>>n>>k,i=1;i<=n;++i) cin>>x>>y,v[x][++C[x]]=y;
	RI t,cur,res;LL ans=0;for(i=1;i<=r;++i)
	{
		for(res=0,j=i;j<=r;++j) for(s=1;s<=C[j];++s) ++cnt[v[j][s]];
		for(pre[1]=0,j=2;j<=c+1;++j) pre[j]=cnt[j-1]?j-1:pre[j-1];
		for(nxt[c]=c+1,j=c-1;~j;--j) nxt[j]=cnt[j+1]?j+1:nxt[j+1];
		for(x=nxt[0];x<=c;x=nxt[x])
		{
			t=0,y=x;W(y<=c&&(t+=cnt[y])<k) y=nxt[y];
			res+=(x-pre[x])*(c-y+1);
		}
		for(j=r;j>=i;--j) for(ans+=res,s=1;s<=C[j];++s)
		{
			if(--cnt[cur=v[j][s]]>=k) continue;
			t=0,y=cur;W(y<=c&&(t+=cnt[y])<k-1) y=nxt[y];
			x=cur;W(x)
			{
				W(y^cur&&t-cnt[y]>=k-1) t-=cnt[y],y=pre[y];if(y==cur&&t>=k) break;
				t+1==k&&(res-=(x-pre[x])*(nxt[y]-y)),t+=cnt[x=pre[x]];
			}
			!cnt[cur]&&(nxt[pre[cur]]=nxt[cur],pre[nxt[cur]]=pre[cur]);
		}
	}return printf("%lld\n",ans),0;
}