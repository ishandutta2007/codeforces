#include<bits/stdc++.h>
//#define int long long
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
queue<int> q1;
priority_queue<pair<int,int> > q2;
bool f[1000003];
signed main()
{
	int T=read(),n=0;
	while(T--)
	{
		int opt=read();
		if(opt==1)
		{
			int x=read();
			++n;
			q1.push(n);
			q2.push(make_pair(x,-n));
		}
		else if(opt==2)
		{
			while(!q1.empty())
			{
				int x=q1.front();
				q1.pop();
				if(f[x]) continue;
				f[x]=1;
				printf("%d ",x);
				break;
			}
		}
		else 
		{
			while(!q2.empty())
			{
				pair<int,int> x=q2.top();
				q2.pop();
				if(f[-x.second]) continue;
				f[-x.second]=1;
				printf("%d ",-x.second);
				break;
			}
		}
	}
	return 0;
}