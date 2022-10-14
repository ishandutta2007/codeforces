#include<bits/stdc++.h>
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
using namespace std;string s;
bool vis[1000003];
int ans=0,n,q,len;
using namespace std;
int ch[503],cnt;
void f(int k)
{
	if(!vis[n-k-1]) cnt++,ch[(int)s[n-k-1]]++,vis[n-k-1]=1,f(n-k-1);
	if(k>=q) 
	{
		if(!vis[k-q]) cnt++,ch[(int)s[k-q]]++,vis[k-q]=1,f(k-q);
	}
	if(k+q<len) 
	{
		if(!vis[k+q]) cnt++,ch[(int)s[k+q]]++,vis[k+q]=1,f(k+q);
	}
}
int main()
{
	int t=read();
	while(t--)
	{
		n=read(),q=read();
		ans=0;
		cin>>s;
		len=s.size();
		for(int i=0; i<len; i++) vis[i]=0;
		for(int i=0; i<len; i++) if(!vis[i]) 
		{
			f(i);
			int Max=0;
			for(int i=50; i<=150; i++) Max=max(Max,ch[i]);
			ans+=cnt-Max;
			 for(int i=50; i<=150; i++) ch[i]=0;
			 cnt=0;
		}
		printf("%d\n",ans);
	}
	return 0;
}