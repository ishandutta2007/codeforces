#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int n,k;
bool vis[100003],ans[100003]; 
int gcd(int a,int b) {while (b^=a^=b^=a%=b); return a;}
signed main()
{
	n=read(),k=read();
	int g=k; 
	for(int i=1; i<=n; i++) g=gcd(g,read());
	for(int i=0; i<k; i+=g) ans[i]=1;
	int cnt=0;
	for(int i=0; i<k; i++) if(ans[i]) ++cnt;
	printf("%d\n",cnt);
	for (int i=0; i<k; i++) if (ans[i]) printf("%d ",i);
	return 0;
}