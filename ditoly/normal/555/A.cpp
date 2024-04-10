#include<cstdio>
#include<vector>
using namespace std;
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 100000
vector<int> v[MN+5];
int main()
{
	int n,k,i,j,x,ans=0;
	n=read();k=read();
	for(i=1;i<=k;++i)
	{
		for(j=read();j--;)v[i].push_back(read());
		for(j=0;j<v[i].size();++j)if(v[i][j]!=j+1)break;
		if(j)ans=j-1;
	}
	printf("%d",n-k+n-1-2*ans);
}