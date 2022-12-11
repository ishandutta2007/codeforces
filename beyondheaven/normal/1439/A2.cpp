#include<bits/stdc++.h>
#define MaxN 123
int n,m;
int a[MaxN][MaxN];
std::vector<std::vector<int>>ans;

inline void Modify(int x1,int y1,int x2,int y2,int x3,int y3)
{
	a[x1][y1]^=1;
	a[x2][y2]^=1;
	a[x3][y3]^=1;
	ans.emplace_back(std::vector<int>({x1,y1,x2,y2,x3,y3}));
}

inline void Bruteforce()
{
	int tmp[5];
	tmp[1]=a[n-1][m-1];
	tmp[2]=a[n-1][m];
	tmp[3]=a[n][m-1];
	tmp[4]=a[n][m];
	
	for(int i=0;i<16;++i)
	{
		a[n-1][m-1]=tmp[1];
		a[n-1][m]=tmp[2];
		a[n][m-1]=tmp[3];
		a[n][m]=tmp[4];
		
		if(i&1)
		{
			//a[n-1][m-1]^=1;
			a[n-1][m]^=1;
			a[n][m-1]^=1;
			a[n][m]^=1;
		}
		if((i>>1)&1)
		{
			a[n-1][m-1]^=1;
			//a[n-1][m]^=1;
			a[n][m-1]^=1;
			a[n][m]^=1;
		}
		if((i>>2)&1)
		{
			a[n-1][m-1]^=1;
			a[n-1][m]^=1;
			//a[n][m-1]^=1;
			a[n][m]^=1;
		}
		if((i>>3)&1)
		{
			a[n-1][m-1]^=1;
			a[n-1][m]^=1;
			a[n][m-1]^=1;
			//a[n][m]^=1;
		}
		
		if(a[n-1][m-1]==0&&a[n-1][m]==0&&a[n][m-1]==0&&a[n][m]==0)
		{
			if(i&1)Modify(n-1,m,n,m-1,n,m);
			if((i>>1)&1)Modify(n-1,m-1,n,m-1,n,m);
			if((i>>2)&1)Modify(n-1,m-1,n-1,m,n,m);
			if((i>>3)&1)Modify(n-1,m-1,n-1,m,n,m-1);
			break;
		}
	}
}

inline void Solve()
{
	memset(a,0,sizeof(a));
	ans.clear();
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
	for(int j=1;j<=m;++j)
	{
		char ch=getchar();
		while(!isdigit(ch))ch=getchar();
		a[i][j]=ch-'0';
	}
	
	for(int i=1;i<=n-2;++i)
	for(int j=1;j<=m-2;++j)
	if(a[i][j]==1)
	Modify(i,j,i,j+1,i+1,j);
	
	for(int i=1;i<=n-2;++i)
	{
		if(a[i][m-1]==1)
		Modify(i,m-1,i,m,i+1,m-1);
		if(a[i][m]==1)
		Modify(i,m,i+1,m,i+1,m-1);
	}
	
	for(int j=1;j<=m-2;++j)
	{
		if(a[n-1][j]==1)
		Modify(n-1,j,n-1,j+1,n,j);
		if(a[n][j]==1)
		Modify(n,j,n,j+1,n-1,j+1);
	}
	
	Bruteforce();
	
	printf("%d\n",static_cast<int>(ans.size()));
	for(auto&v:ans)
	{
		for(int x:v)
		printf("%d ",x);
		puts("");
	}
}

int main()
{
	int T;scanf("%d",&T);
	while(T--)Solve();
	return 0;
}