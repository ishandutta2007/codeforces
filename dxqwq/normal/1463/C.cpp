
#include<bits/stdc++.h>
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
using namespace std;
const int N=100010;
int T,n,p,q,t[N],x[N],ans; 
signed main(){
	for(int T=read();T--;)
	{
		int n=read();
		for(int i=1;i<=n;++i)t[i]=read(),x[i]=read();
		p=q=ans=0;
		for(int i=1,tp;i<=n;++i){
			if(p==q)q=x[i];
			if(t[i+1]-t[i]>=abs(p-q)||i==n)tp=q;
			else tp=p<q?p+t[i+1]-t[i]:p-t[i+1]+t[i];
			if(1ll*(x[i]-p)*(x[i]-tp)<=0)ans++;
			p=tp;
		}
		printf("%lld\n",ans);
	}
	return 0;
}