#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int a[1000003];
int cnt[1000003],C=0;
signed main()
{
	int n=read(),k=read();
	int al=1,ar=1,len=1;
	for(int l=1,r=1; r<=n; r++)
	{
		a[r]=read();
		if(!cnt[a[r]]) ++C;
		++cnt[a[r]];
		while(C>k)
		{
			if(cnt[a[l]]==1) --C;
			--cnt[a[l]];
			++l;
		}
		if(r-l+1>len) al=l,ar=r,len=r-l+1;
	}
	printf("%d %d\n",al,ar);
    return 0;
}