#include<bits/stdc++.h>
const int MaxN = 523;

int n,m;
char c[MaxN][MaxN];

void clear()
{
	for(int i=1;i<=n;++i)
	for(int j=1;j<=m;++j)
	c[i][j]=0;
}

int main()
{
	int T;scanf("%d",&T);
	while(T--)
	{
		clear();
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)
		scanf("%s",c[i]+1);
		
		if(m==1)for(int i=1;i<=n;++i)c[i][1]='X';
		else
		for(int j=2;j<=m;j+=3)
		{
			for(int i=1;i<=n;++i)c[i][j]='X';
			if(j+2<m)
			{
				auto empty=[&](int o)
				{
					for(int i=1;i<=n;++i)
					if(c[i][o]=='X')return false;
					return true;
				};
				
				if(empty(j+1)&&empty(j+2))
				c[1][j+1]=c[1][j+2]='X';
				
				else 
				for(int i=1;i<=n;++i)
				if(c[i][j+1]=='X' || c[i][j+2]=='X')
				{
					c[i][j+1]=c[i][j+2]='X';
					break;
				}
			}
			
			if(j+2==m)
			for(int i=1;i<=n;++i)
			if(c[i][j+2]=='X')c[i][j+1]='X';
		}
		
		for(int i=1;i<=n;++i)
		printf("%s\n",c[i]+1);
	}
	return 0;
}