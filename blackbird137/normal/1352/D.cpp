#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<queue>
#include<map>
#include<set>

using namespace std;

int read()
{
	int ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=getchar();}
	return ans*f;
}

const int N=1005;
int t,n,a[N],x,y,lx,ly,sum;

int main()
{
	t=read();
	while(t--)
	{
		n=read();
		for(int i=1;i<=n;++i)
			a[i]=read();
		int i=1,j=n;
		x=0,y=0,sum=0;
		lx=0,ly=0;
		while(i<=j)
		{
			
			int sx=a[i++];
			while(sx<=ly&&i<=j)
				sx+=a[i++];
			x+=sx,lx=sx;
			sum++;
			if(!(i<=j))
				break;
			int sy=a[j--];
			while(sy<=lx&&i<=j)
				sy+=a[j--];
			y+=sy,ly=sy;
			sum++;
			
		}
		printf("%d %d %d\n",sum,x,y);
	}
	return 0;
}