#include<bits/stdc++.h>
#define p pair<int,pair<int,int> > 
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
p a[1000003];
priority_queue<int,vector<int>,greater<int> > q;
int main(){
	int n=read(),k=read();
	for(int i=1; i<=n; i++) a[i].first=read(),a[i].second.first=read(),a[i].second.second=i;
	sort(a+1,a+n+1);
	for(int i=1; i<=k; i++) q.push(a[i].second.first);
	int ans=max(q.top()-a[k].first+1,0),l=a[k].first;
	for(int i=k+1; i<=n; i++) 
	{
		q.push(a[i].second.first),q.pop();
		if(q.top()-a[i].first+1>ans) ans=q.top()-a[i].first+1,l=a[i].first;
	}
	printf("%d\n",ans);
	if(ans==0)
	{
		for(int i=1; i<=k; i++) printf("%d ",i);
		return 0; 
	}
	for(int i=1; i<=n; i++) 
	{
		if(a[i].first<=l && a[i].second.first>=l+ans-1) printf("%d ",a[i].second.second),--k;
		if(!k) return 0;
	}
	return 0;
}///