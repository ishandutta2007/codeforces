//And in that light,I find deliverance.
#include<bits/stdc++.h>
using namespace std;
#define int long long
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
    for(int T=read();T--;)
    {
    	int a[13];
    	for(int i=1; i<=4; ++i) a[i]=read();
    	int b[12];
    	b[1]=max(a[1],a[2]);
    	b[2]=max(a[3],a[4]);
    	sort(a+1,a+5);
    	if(b[1]>b[2]) swap(b[1],b[2]);
    	if(b[1]==a[3]&&b[2]==a[4]) puts("YES");
    	else puts("NO");
    }
	return 0;
}