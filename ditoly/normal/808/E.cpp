#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
#define ll long long
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=(x<<3)+(x<<1)+c-'0';
	return x;
}
#define MM 300000
ll f[MM+5];
vector<int> v[4];
int main()
{
	int n,m,i,j,k;ll s,ans=0;
	n=read();m=read();
	while(n--)i=read(),v[i].push_back(read());
	for(i=1;i<4;++i)sort(v[i].begin(),v[i].end());
	for(s=i=0,j=v[1].size(),k=v[2].size();j||k;)
	{
		if(!j)i+=2,s+=v[2][--k];
		else if(!k)++i,s+=v[1][--j];
		else
		{
			f[i+1]=max(f[i+1],s+v[1][j-1]);
			if(j>1)
				if(v[2][k-1]>v[1][j-1]+v[1][j-2])i+=2,s+=v[2][--k];
				else ++i,s+=v[1][--j];
			else
				if(v[2][k-1]>v[1][j-1])i+=2,s+=v[2][--k];
				else ++i,s+=v[1][--j];
		}
		f[i]=max(f[i],s);
	}
	for(i=1;i<=m;++i)f[i]=max(f[i],f[i-1]);
	for(s=i=0;3*i<=m&&i<=v[3].size();++i)ans=max(ans,s+f[m-3*i]),i<v[3].size()?s+=v[3][v[3].size()-i-1]:0; 
	printf("%I64d",ans);
}