#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
const int N=200005,E=524288;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
int p[N],i,j,t,n,e[N];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;++i)
		{
			scanf("%d",&p[i]);
			e[p[i]]=i;
		}
		int l=n;
		bool flag=true;
		for(i=1;flag&&i<=n;++i)
		{
			for(j=e[i];j<l;++j)
				if(p[j+1]!=p[j]+1)
				{
					flag=false;
					break;
				}
			l=e[i]-1;
			i=p[j];
		}
		puts(flag?"Yes":"No");
	}
}