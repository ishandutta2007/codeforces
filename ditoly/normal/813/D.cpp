#include<cstdio>
#include<vector>
using namespace std;
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=(x<<3)+(x<<1)+c-'0';
	return x;
}
#define MN 5000
#define MX 100000
int a[MN+5],f[MN+5][MN+5],ans,r[MX+5],rr[7];
vector<int> v[MX+5],vv[7];
inline void rw(int&a,int b){if(b>a)a=b;}
int main()
{
	int n=read(),i,j,k;
	for(i=1;i<=n;++i)a[i]=read(),v[a[i]].push_back(i),vv[a[i]%7].push_back(i);
	for(i=0;i<=n;++i)
	{
		for(j=1;j<=n;++j)r[a[j]]=rr[a[j]%7]=0;
		for(j=i+1;j<=n;++j)
		{
			ans=max(ans,f[i][j]=max(f[i][j],1));
			
			while(i&&r[a[i]-1]<v[a[i]-1].size()&&v[a[i]-1][r[a[i]-1]]<=j)++r[a[i]-1];
			if(i&&r[a[i]-1]<v[a[i]-1].size())rw(f[j][v[a[i]-1][r[a[i]-1]]],f[i][j]+1);
			
			while(r[a[i]+1]<v[a[i]+1].size()&&v[a[i]+1][r[a[i]+1]]<=j)++r[a[i]+1];
			if(i&&r[a[i]+1]<v[a[i]+1].size())rw(f[j][v[a[i]+1][r[a[i]+1]]],f[i][j]+1);
			
			while(r[a[j]-1]<v[a[j]-1].size()&&v[a[j]-1][r[a[j]-1]]<=j)++r[a[j]-1];
			if(r[a[j]-1]<v[a[j]-1].size())rw(f[i][v[a[j]-1][r[a[j]-1]]],f[i][j]+1);
			
			while(r[a[j]+1]<v[a[j]+1].size()&&v[a[j]+1][r[a[j]+1]]<=j)++r[a[j]+1];
			if(r[a[j]+1]<v[a[j]+1].size())rw(f[i][v[a[j]+1][r[a[j]+1]]],f[i][j]+1);
			
			while(rr[a[i]%7]<vv[a[i]%7].size()&&vv[a[i]%7][rr[a[i]%7]]<=j)++rr[a[i]%7];
			if(i&&rr[a[i]%7]<vv[a[i]%7].size())rw(f[j][vv[a[i]%7][rr[a[i]%7]]],f[i][j]+1);
			
			while(rr[a[j]%7]<vv[a[j]%7].size()&&vv[a[j]%7][rr[a[j]%7]]<=j)++rr[a[j]%7];
			if(rr[a[j]%7]<vv[a[j]%7].size())rw(f[i][vv[a[j]%7][rr[a[j]%7]]],f[i][j]+1);
			
			if(!i)for(k=j+1;k<=n;++k)rw(f[j][k],f[i][j]+1);
		}
	}
	printf("%d",ans);
}