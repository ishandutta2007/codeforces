#include<bits/stdc++.h>
using namespace std;
int _main()
{
	int x;
	char a='0',b='0',t;
	bool f=1,ff=1;
	scanf("%d",&x);
	getchar();
	for(int i=1; i<=x; i++) 
	{
		if(f) 
		{
			scanf("%c",&a);
			if((int)a%2) f=0;
		}
		else if(ff)
		{
			scanf("%c",&b);
			if((int)b%2) ff=0;
		}
		else scanf("%c",&t);
	}
	
	
	if(b%2) printf("%c%c\n",a,b); else printf("-1\n");
}
int main()
{
	int n;
	scanf("%d",&n);
	while(n--) _main();
}