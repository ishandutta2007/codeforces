#include<bits/stdc++.h>
#define MaxN 200123
char s[MaxN];
int main()
{
	int T,n;
	scanf("%d",&T);
	while(T--)
	{
		memset(s,0,sizeof(s));
		scanf("%s",s+1);
		n=strlen(s+1);
		int cntR=0,cntS=0,cntP=0;
		for(int i=1;i<=n;++i)
		switch(s[i])
		{
			case 'R':++cntR;break;
			case 'S':++cntS;break;
			case 'P':++cntP;break; 
		}
		if(cntR>=cntS&&cntR>=cntP)
		for(int i=1;i<=n;++i)
		printf("P");
		else if(cntS>=cntR&&cntS>=cntP)
		for(int i=1;i<=n;++i)
		printf("R");
		else if(cntP>=cntR&&cntP>=cntS)
		for(int i=1;i<=n;++i)
		printf("S");
		puts("");
	}
	return 0;
}