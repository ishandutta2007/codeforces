#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
long long ans[5003][5003];
int a[5003];
deque<pair<int,long long> > q[5003];
void ins(int p,pair<int,long long> x)
{
	while(!q[p].empty()&&q[p].back().second<=x.second) q[p].pop_back();
	q[p].push_back(x);
	return ;
}
signed main()
{
	int n=read(),t=read(),m=read();
	memset(ans,0xc0,sizeof(ans));
	ans[0][0]=0,ins(0,make_pair(0,0));
	for(int i=1; i<=n; i++) a[i]=read();
	for(int i=1; i<=n; i++) 
	{
		for(int j=0; j<m; j++) if(!q[j].empty()&&q[j].front().first+t<i) q[j].pop_front();
		for(int j=1; j<=m; j++) if(!q[j-1].empty()) ans[i][j]=q[j-1].front().second+a[i];
		for(int j=m; j>=1; j--) ins(j,make_pair(i,ans[i][j]));
	}
	long long Ans=-1;
	for(int i=max(m,n-t+1); i<=n; i++) Ans=max(Ans,ans[i][m]);
	printf("%lld\n",Ans);
	return 0;
}