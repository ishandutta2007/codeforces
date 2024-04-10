#include<bits/stdc++.h>
#define mp make_pair
#define pi pair<int,int>
#define pb push_back
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int a[1000003];
int main()
{
	int n=read();
	puts("XOR 1 2");
	fflush(stdout);
	int x=read();
	puts("XOR 2 3");
	fflush(stdout);
	int y=read();
	puts("OR 1 3");
	fflush(stdout);
	int z=read(),w=x^y; 
	puts("AND 1 2");
	fflush(stdout);
	int qwq=read();	
	puts("AND 2 3");
	fflush(stdout);
	int awa=read();	
	for(int i=1; i<n; i<<=1)
	{//0551050
		if(z&i)//OR11
		{
			if(w&i)//01
			{
				if(y&i)//a2xor1a2a310 
				{
					if(qwq&i) a[1]+=i,a[2]+=i;
					else a[3]+=i;
				}
				else 
				{
					if(awa&i) a[2]+=i,a[3]+=i;
					else a[1]+=i;
				}
			 } 
			else//1 
			{
				a[1]+=i,a[3]+=i;
				if(!(x&i)) a[2]+=i;
			}
		 } 
		 else
		 {
		 	if(x&i) a[2]+=i;
		 }
	}
	for(int i=4; i<=n; i++)
	{
		printf("XOR 1 %d\n",i);
		fflush(stdout);
		a[i]=read()^a[1];
	}
	printf("! ");
	for(int i=1; i<=n; i++) printf("%d ",a[i]);
	puts("");
	fflush(stdout);
	return 0;
}