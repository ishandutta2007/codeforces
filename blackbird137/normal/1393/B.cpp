#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<bitset>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<queue>
#include<map>

#define lowbit(x) (x&(-x))

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
int n,q,sum[N],l1,l2,l3,l4;

int main()
{
	n=read();
	for(int i=1;i<=n;++i)
	{
		int a=read();
		if(sum[a]>=2) l1--;
		if(sum[a]>=4) l2--;
		if(sum[a]>=6) l3--;
		if(sum[a]>=8) l4--;
		sum[a]++;
		if(sum[a]>=2) l1++;
		if(sum[a]>=4) l2++;
		if(sum[a]>=6) l3++;
		if(sum[a]>=8) l4++;
	}
	q=read();
	while(q--)
	{
		char opt[5];
		scanf("%s",opt+1);
		if(opt[1]=='+')
		{
			int a=read();
			if(sum[a]>=2) l1--;
			if(sum[a]>=4) l2--;
			if(sum[a]>=6) l3--;
			if(sum[a]>=8) l4--;
			sum[a]++;
			if(sum[a]>=2) l1++;
			if(sum[a]>=4) l2++;
			if(sum[a]>=6) l3++;
			if(sum[a]>=8) l4++;
		}
		else
		{
			int a=read();
			if(sum[a]>=2) l1--;
			if(sum[a]>=4) l2--;
			if(sum[a]>=6) l3--;
			if(sum[a]>=8) l4--;
			sum[a]--;
			if(sum[a]>=2) l1++;
			if(sum[a]>=4) l2++;
			if(sum[a]>=6) l3++;
			if(sum[a]>=8) l4++;
		}
		int flag=0;
		if(l4>=1) flag=1;
		if(l3>=1&&l1-1>=1) flag=1;
		if(l2>=2) flag=1;
		if(l2>=1&&l1-1>=2) flag=1;
		if(flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}