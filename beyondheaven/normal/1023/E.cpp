#include<bits/stdc++.h>
inline bool Query(int a,int b,int c,int d)
{
	static char ret[10];
	printf("? %d %d %d %d\n",a,b,c,d);
	fflush(stdout);
	scanf("%s",ret);
	return ret[0]=='Y';
}
int n;
int main()
{
	scanf("%d",&n);
	std::string path1,path2;
	int x=1,y=1;
	while(x+y<=n)
	{
		if(y<n&&Query(x,y+1,n,n))
		{
			++y;
			path1+='R';
		}
		else
		{
			++x;
			path1+='D';
		}
	}
	x=n,y=n;
	while(x+y>n+1)
	{
		if(x>1&&Query(1,1,x-1,y))
		{
			--x;
			path2+='D';
		}
		else
		{
			--y;
			path2+='R';
		}
	}
	std::reverse(path2.begin(),path2.end());
	std::cout<<"! "<<path1<<path2<<std::endl;
	std::cout.flush();
	return 0;
}