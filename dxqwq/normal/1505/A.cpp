#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
const int p=998244353;
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
signed main()
{
	int A=0;
    while(1)
    {
    	char c=getchar();
    	if(c==EOF) return 0;
    	if(c=='u') A=1;
    	if(c=='\n')
    	{
    		if(A) puts("YES");
    		else puts("NO");
    		fflush(stdout);
    		A=0;
    	}
    }
	return 0;
}