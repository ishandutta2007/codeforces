#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>
using namespace std;
#pragma G++ optimize ("O3")
typedef long long ll;
const int lowbit(int x) { return x&-x; }
int read(){ int v = 0, f = 1;char c =getchar();
while( c < 48 || 57 < c ){if(c=='-') f = -1;c = getchar();}
while(48 <= c && c <= 57) v = v*10+c-48, c = getchar();
return v*f;}
/*
ios::sync_with_stdio(0);
cin.tie(0);
*/
/***************************timer******************************/
struct timer
{
   double t;
   timer() { t=clock(); }
   ~timer() { printf("\nruntime %.3f s\n", get_time()); }
   double get_time() { return (clock()-t)/CLOCKS_PER_SEC; }
};
/*************************************************************/
int f[12];
char s[12];
int main()
{
	int t;
	t=read();
	while(t--)
	{
		int d;
		scanf("%s%d",s,&d);
		if(s[0]=='&')
		{
			for(int i=0;i<10;i++)
			{
				if(((d>>i)&1)==0)
				{
					f[i]=2;
				}		
			}
				
		}
		else if(s[0]=='|')
		{
			for(int i=0;i<10;i++)
			{
				if(((d>>i)&1)==1)
				{
					f[i] = 3;
				}
			}
		}
		else
		{
			for(int i=0;i<10;i++)
			{
				if(((d>>i)&1)==1)
				{
					if(f[i]>1)
					{
						f[i]=5-f[i];
					}
					else f[i]=1-f[i];
				}
			}
				
		}
	}
	printf("%d\n",3);
	int d=1023;
	for(int i=0;i<10;i++)
	{
		if(f[i]==2)
		{
			d-=1<<i;	
		}
			
	}	
	printf("& %d\n",d);
	d=0;
	for(int i=0;i<10;i++)
	{
		if(f[i]==3)
		{
			d+=1<<i;
		}		
	}	
	printf("| %d\n",d);
	d=0;
	for(int i=0;i<10;i++)
	{
		if(f[i]==1)
		{
			d+=1<<i;
		}			
	}		
	printf("^ %d\n",d);
	return 0;
}