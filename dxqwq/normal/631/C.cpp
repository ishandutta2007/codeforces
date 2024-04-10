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
stack<int> s;
int q[1000003],cnt;
deque<int> dq;
int main(){
    int n=read(),m=read();
    for(int i=1; i<=n; i++) a[i]=read();
	while(m--)
	{
		int x=read(),y=read();
		while(!s.empty() && abs(s.top())<=y) s.pop();
		if(x==1) s.push(y); else s.push(-y);
	} 
	while(!s.empty()) q[++cnt]=s.top(),s.pop();
	sort(a+1,a+abs(q[cnt])+1);
	for(int i=1; i<=abs(q[cnt]); i++) dq.push_front(a[i]);
	int r=abs(q[cnt]);
	for(int i=cnt; i>=1; i--)
	{
		int t=abs(q[i])-abs(q[i-1]);
		if(q[i]>0)
		{
			for(int i=1; i<=t; i++) a[r--]=dq.front(),dq.pop_front();
		}
		else
		{
			for(int i=1; i<=t; i++) a[r--]=dq.back(),dq.pop_back();
		}
	}
	for(int i=1; i<=n; i++) printf("%d ",a[i]);
    return 0;
}