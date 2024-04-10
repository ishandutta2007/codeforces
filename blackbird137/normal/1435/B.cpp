#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#define int long long

using namespace std;

int read()
{
	int ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=getchar();}
	return ans*f;
}

const int N=505;
int t,n,m,pos[N*N],ans[N];

vector<int> h[N],l[N];

signed main()
{
	t=read();
	while(t--)
	{
		n=read();m=read();
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
			{
				h[i].push_back(read());
				pos[h[i][j-1]]=i;
			}
		for(int j=1;j<=m;++j)
			for(int i=1;i<=n;++i)
				l[j].push_back(read());
		for(int i=1;i<=n;++i)
			ans[i]=pos[l[1][i-1]];
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=m;++j)
				printf("%lld ",h[ans[i]][j-1]);
			printf("\n");
		}
		for(int i=1;i<=n;++i) h[i].clear();
		for(int i=1;i<=m;++i) l[i].clear();
	}
	return 0;
}