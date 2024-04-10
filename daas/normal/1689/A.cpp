#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<vector>
#define ll long long
using namespace std;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int T,n,m,K,ton[30],type[30],num[2];
char a[110],b[110];
int main()
{
	T=read();
	while(T--)
	{
		n=read(),m=read(),K=read();
		scanf("%s",a+1);
		scanf("%s",b+1);
		memset(ton,0,sizeof(ton));
		num[0]=num[1]=0;
		for(int i=1;i<=n;++i)
		{
			if(!ton[a[i]-'a'])
			{
				++num[0];
				type[a[i]-'a']=0;
			}
			++ton[a[i]-'a'];
		}
		for(int i=1;i<=m;++i)
		{
			if(!ton[b[i]-'a'])
			{
				++num[1];
				type[b[i]-'a']=1;
			}
			++ton[b[i]-'a'];
		}
		int las=0,res=K;
		while(num[0] && num[1])
		{
			for(int i=0;i<26;++i) if(ton[i])
			{
				if(las==type[i] && !res) continue;
				if(las==type[i]) --res;
				else las=type[i],res=K-1;
				putchar('a'+i);
				--ton[i];
				if(!ton[i]) --num[type[i]];
				break;
			}
		}
		putchar('\n');
	}
	return 0;
}
//ore no turn,draw!