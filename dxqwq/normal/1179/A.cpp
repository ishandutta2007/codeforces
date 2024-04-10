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
deque<int> q;
int a[1000003];
int x[1000003][2];
signed main()
{
	int n=read(),m=read();
	for(int i=1; i<=n; i++) a[i]=read(),q.push_back(a[i]);
	for(int i=1,t1,t2; i<n; i++) 
	{
		x[i][0]=t1=q.front(),q.pop_front(),x[i][1]=t2=q.front(),q.pop_front();
		if(t1<t2) swap(t1,t2);
		q.push_front(t1),q.push_back(t2); 
	}
	for(int i=0; i<n; i++) a[i]=q.front(),q.pop_front();
	for(int i=1; i<=m; i++) 
	{
		int t=read();
		if(t<n) printf("%lld %lld\n",x[t][0],x[t][1]);
		else printf("%lld %lld\n",a[0],a[(t-1)%(n-1)+1]);
	}
	return 0;
}