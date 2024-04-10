#include<cstdio>
int main()
{
	int T,n,k;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		int pos=n-1;
		while(k>(n-pos))k-=n-pos,--pos;
		for(int i=1;i<pos;++i)putchar('a');
		putchar('b');
		for(int i=pos+1;i<n-k+1;++i)putchar('a');
		putchar('b');
		for(int i=n-k+2;i<=n;++i)putchar('a');
		puts("");
	}
	return 0;
}