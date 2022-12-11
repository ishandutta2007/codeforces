#include<bits/stdc++.h>
typedef long long LL;

inline LL Binom(int n,int m)
{
	LL res=1;
	for(int i=0;i<m;++i)res*=n-i;
	for(int i=1;i<=m;++i)res/=i;
	return res;
}

int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	
	LL res=0;
	switch(k)
	{
		case 4:
			res+=9*Binom(n,4);
		case 3:
			res+=2*Binom(n,3);
		case 2:
			res+=Binom(n,2);
		case 1:
			++res;
	}
	printf("%lld\n",res);
	return 0;
}