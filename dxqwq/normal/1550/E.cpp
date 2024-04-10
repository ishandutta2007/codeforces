// Problem: E. Stringforces
// Contest: Codeforces - Educational Codeforces Round 111 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1550/problem/E
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
const int p=998244353;
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
char s[300003];
int n=read();
int k=read(),N=1<<k;
int pre[26][300003];
int qwq[300003];
int pos[26][300003];
int mn[1000003];
int occq(int l,int r)
{
	return qwq[r]-qwq[l-1];
}
int occ(int l,int r,int t)
{
	return pre[t][r]-pre[t][l-1];
}
bool check(int x)
{
	// printf("%d\n",x);
	for(int i=0; i<k; ++i) 
	{
		for(int j=1; j<=n+5; ++j) pos[i][j]=998244353;
		for(int j=n; j>=1; --j)
			if(j+x-1<=n)
			{
				if(occq(j,j+x-1)+occ(j,j+x-1,i)==x)
					pos[i][j]=j+x-1;
				else pos[i][j]=pos[i][j+1];
			}
			else pos[i][j]=pos[i][j+1];
		// for(int j=1; j<=n; ++j) printf("%d ",pos[i][j]);
		// puts("");
	}
	for(int i=0; i<N; ++i) mn[i]=n+1;
	mn[0]=0;
	for(int i=0; i+1<N; ++i)
		for(int j=0; j<k; ++j)
			mn[i|(1<<j)]=min(mn[i|(1<<j)],pos[j][mn[i]+1]);
	// for(int i=0; i<N; ++i) printf("%d ",mn[i]);puts("");
    return mn[N-1]<=n;
}
signed main()
{
	scanf("%s",s+1);
	for(int j=0; j<k; ++j)
	for(int i=1; i<=n; ++i)
	pre[j][i]=pre[j][i-1]+(s[i]=='a'+j);
	for(int i=1; i<=n; ++i)
	qwq[i]=qwq[i-1]+(s[i]=='?');
	int l=1,r=n/k,res=0;
	// printf("%d\n",occq(1,3)+occ(1,3,0));
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid)) res=mid,l=mid+1;
		else r=mid-1;
	}
	printf("%d\n",res);
	return 0;
}