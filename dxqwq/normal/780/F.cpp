#include<bits/stdc++.h>
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
using namespace std;
bitset<503> dp[64][503],rev[64][503];
int da[503][503],ra[503][503],A[503][503],B[503][503];
signed main()
{
	int n=read(),m=read();
	for(int i=1,u,v,w; i<=m; i++) 
	{
		u=read(),v=read(),w=read();
		if(w) rev[0][u][v]=1;
		else dp[0][u][v]=1;
	}
	for(int i=1; i<=60; i++)
	{
		for(int j=1; j<=n; j++) for(int k=1; k<=n; k++)
		{
			if(dp[i-1][j][k]) dp[i][j]|=rev[i-1][k];
			if(rev[i-1][j][k]) rev[i][j]|=dp[i-1][k];
		}
	}
	int F=0;
	bitset<503> g,tmp;
    tmp[1]=1;
    int ans_=0;
    for(int i=60;i>=0;i--){
        g.reset();
        for(int j=1; j<=n; j++) if(tmp[j]) if(F) g|=rev[i][j]; else g|=dp[i][j];
        if(g.any()) F=(!F),tmp=g,ans_+=(1ll<<i);
    }
	for(int j=1; j<=n; j++) for(int k=1; k<=n; k++) ans_=max(ans_,da[j][k]);
		if(ans_>1000000000000000000ll) puts("-1");
		else printf("%lld\n",ans_);
    return 0;
}