#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int a[13][100003],val[13],tmp[13];
bitset<4096> b[100053];
bool cmp(int x,int y)
{
	return val[x]<val[y];
}
signed main()
{
	int n=read(),k=read(),cnt=k,q=read();
	for(int i=1; i<=k; ++i) for(int j=1; j<=n; ++j) a[i][j]=read();
	for(int i=1; i<=k; ++i) for(int j=0; j<4096; ++j) if(j&(1<<(i-1))) b[i][j]=1;
	for(int op,x,y;q--;)
	{
		op=read(),x=read(),y=read();
		if(op==1) b[++cnt]=b[x]&b[y];
		if(op==2) b[++cnt]=b[x]|b[y];
		if(op==3)
		{
			for(int j=1; j<=k; ++j) tmp[j]=j,val[j]=a[j][y];
			sort(tmp+1,tmp+k+1,cmp);
			int res=0;
			for(int j=1; j<=k; ++j) 
			{
				res|=(1<<(tmp[j]-1));
				if(b[x][res])
				{
					printf("%d\n",val[tmp[j]]);
					break;
				}
			}
		}
	}
	return 0;
}