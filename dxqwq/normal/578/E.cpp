// Problem: E. Walking!
// Contest: Codeforces - Codeforces Round #320 (Div. 1) [Bayan Thanks-Round]
// URL: https://codeforces.com/problemset/problem/578/E
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
vector<int> v[100003],ll,lr,rl,rr;
char s[100003];
int cnt=0;
signed main()
{
	scanf("%s",s+1);
	int n=strlen(s+1);
	for(int i=1; i<=n; ++i) 
		if(s[i]=='L')
			if(!lr.empty())
				v[lr.back()].push_back(i),
				ll.push_back(lr.back()),
				lr.pop_back();
			else if(!rr.empty()) 
				v[rr.back()].push_back(i),
				rl.push_back(rr.back()),
				rr.pop_back();
			else 
				ll.push_back(++cnt),
				v[cnt].push_back(i);
		else
			if(!rl.empty())
				v[rl.back()].push_back(i),
				rr.push_back(rl.back()),
				rl.pop_back();
			else if(!ll.empty()) 
				v[ll.back()].push_back(i),
				lr.push_back(ll.back()),
				ll.pop_back();
			else 
				rr.push_back(++cnt),
				v[cnt].push_back(i);
	printf("%d\n",cnt-1);
	if(ll.size()>rr.size())
	{
		for(int i:lr) 
			for(int j:v[i]) 
				printf("%d ",j);
		int N=(int)rr.size();
		for(int i=0; i<N; ++i)
		{
			for(int j:v[ll[i]])
				printf("%d ",j);
			for(int j:v[rr[i]])
				printf("%d ",j);
		}	
		for(int j:v[ll[N]])
			printf("%d ",j);
		for(int i:rl) 
			for(int j:v[i]) 
				printf("%d ",j);		
	}
	else if(ll.size()<rr.size())
	{
		for(int i:rl) 
			for(int j:v[i]) 
				printf("%d ",j);
		int N=(int)ll.size();
		for(int i=0; i<N; ++i)
		{
			for(int j:v[rr[i]])
				printf("%d ",j);
			for(int j:v[ll[i]])
				printf("%d ",j);	
		}	
		for(int j:v[rr[N]])
			printf("%d ",j);
		for(int i:lr) 
			for(int j:v[i]) 
				printf("%d ",j);	
	}
	else
	{
		while(!lr.empty()&&!rl.empty())
		{
			int x=lr.back(),y=rl.back();
			lr.pop_back(),rl.pop_back();
			if(v[x].back()<v[y].back())
				v[x].push_back(v[y].back()),v[y].pop_back();
			else v[y].push_back(v[x].back()),v[x].pop_back();
			ll.push_back(x),rr.push_back(y);
		}
		if(!lr.empty())
		{
			for(int i:lr)
				for(int j:v[i])
					printf("%d ",j);
			int N=(int)ll.size();
			for(int i=0; i<N; ++i)
			{
				for(int j:v[ll[i]])
					printf("%d ",j);
				for(int j:v[rr[i]])
					printf("%d ",j);
			}
		}
		else
		{
			for(int i:rl)
				for(int j:v[i])
					printf("%d ",j);
			int N=(int)ll.size();
			for(int i=0; i<N; ++i)
			{
				for(int j:v[rr[i]])
					printf("%d ",j);
				for(int j:v[ll[i]])
					printf("%d ",j);
			}
		}
	}
	return 0;
}