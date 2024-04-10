#include<bits/stdc++.h>
#define mp make_pair
#define int long long
#define zkakioi priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >
#define q1f (q1.top().first)
#define q2f (q2.top().first)
#define q3f (q3.top().first)
#define q4f (q4.top().first)
#define q5f (q5.top().first)
#define q1s (q1.top().second)
#define q2s (q2.top().second)
#define q3s (q3.top().second)
#define q4s (q4.top().second)
#define q5s (q5.top().second)
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
zkakioi q1,q2,q3,q4,q5;
//q1:01ai
//q2:12bi-ai
//q3:02bi 
//q4:21ai-bi
//q5:10-ai 
int a[300003],b[300003],f[300003];
signed main()
{
	int n=read(),m=read();
	for(int i=1; i<=n; i++) 
	a[i]=read(),b[i]=read(),q1.push(mp(a[i],i)),q3.push(mp(b[i],i));
	long long ans=0;
	while(m--)
	{
		int x=10000000000ll,opt=-1;
		while(!q1.empty()&&f[q1s]!=0) q1.pop();
		while(!q2.empty()&&f[q2s]!=1) q2.pop();
		while(!q3.empty()&&f[q3s]!=0) q3.pop();
		while(!q4.empty()&&f[q4s]!=2) q4.pop();
		while(!q5.empty()&&f[q5s]!=1) q5.pop();
		if(!q1.empty()&&q1f<x) x=q1f,opt=1;
		if(!q2.empty()&&q2f<x) x=q2f,opt=2;
		if(!q3.empty()&&!q4.empty()&&q3f+q4f<x) x=q3f+q4f,opt=3;
		if(!q3.empty()&&!q5.empty()&&q3f+q5f<x) x=q3f+q5f,opt=4;
		ans+=x;
		if(opt==1) f[q1s]=1,q2.push(mp(b[q1s]-a[q1s],q1s)),q5.push(mp(-a[q1s],q1s)),q1.pop();
		if(opt==2) f[q2s]=2,q4.push(mp(a[q2s]-b[q2s],q2s)),q2.pop();
		if(opt==3) f[q3s]=2,f[q4s]=1,q4.push(mp(a[q3s]-b[q3s],q3s)),q2.push(mp(b[q4s]-a[q4s],q4s)),q5.push(mp(-a[q4s],q4s)),q3.pop(),q4.pop();
		if(opt==4) f[q3s]=2,f[q5s]=0,q4.push(mp(a[q3s]-b[q3s],q3s)),q1.push(mp(a[q5s],q5s)),q3.push(mp(b[q5s],q5s)),q3.pop(),q5.pop();
	}
	printf("%lld\n",ans);
	for(int i=1; i<=n; i++) printf("%lld",f[i]);
	puts("");
	return 0;
}