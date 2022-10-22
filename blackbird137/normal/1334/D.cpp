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

const int N=1e5+5;
int t,n,l,r;

signed main()
{
	t=read();
	while(t--)
	{
		n=read();l=read();r=read();
		int pos=1;
		for(pos=1;pos<=n-1;++pos)
			if(pos*(n*2-pos-1)>l)
				break;
		pos-=2;
		int now=(pos*((n*2)-pos-1));
		pos++; 
		for(int i=pos;i<n;++i)
			for(int j=i+1;j<=n;++j)
			{
				now++;
				if(now>=l&&now<=r) printf("%lld ",i);
				now++;
				if(now>=l&&now<=r) printf("%lld ",j);
				if(now>r) break;
			}
		if(now<r) printf("1");
		printf("\n");
	}
	return 0;
}