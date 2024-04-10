#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int main()
{
	for(int T=read(); T--;)
	{
		int x=read();
		bool f=0;
		for(int i=0; i*3<=x; i++) for(int j=0; i*3+j*5<=x; j++)	
		{
			if(f) break;
			int k=(x-i*3-j*5)/7;
			if(i*3+j*5+k*7==x) 
			{
				f=1;
				printf("%d %d %d\n",i,j,k);
				break;
			}
		}
		if(!f) puts("-1");
	}
	return 0;
}