// Problem: D. Colored Boots
// Contest: Codeforces - Codeforces Round #547 (Div. 3)
// URL: https://codeforces.com/contest/1141/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// zhoukangyang 
#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
	return s*w;
}
stack<int> vs[30],vt[30];
char s[1000003],t[1000003];
int x[1000003],y[1000003],c;
void add(int X,int Y)
{
	x[++c]=X,y[c]=Y;
	return ;
}
void print()
{
	printf("%d\n",c);
	for(int i=1; i<=c; ++i) printf("%d %d\n",x[i],y[i]);
	return ;
}
signed main()
{
	int n=read();
	scanf("%s",s+1);
	scanf("%s",t+1);
	for(int i=1; i<=n; i++) if(s[i]!='?') vs[s[i]-'a'].push(i);
	else vs[26].push(i);
	for(int i=1; i<=n; i++) if(t[i]!='?') vt[t[i]-'a'].push(i);
	else vt[26].push(i);
	for(int i=0; i<26; i++)
	{
		while(!vs[i].empty()&&!vt[i].empty())
		{
			int A=vs[i].top(),B=vt[i].top();
			add(A,B);
			vs[i].pop(),vt[i].pop();
		}
	}
	for(int i=0; i<26; i++)
	{
		while(!vs[i].empty()&&!vt[26].empty())
		{
			int A=vs[i].top(),B=vt[26].top();
			add(A,B);
			vs[i].pop(),vt[26].pop();
		}
	}
	for(int i=0; i<26; i++)
	{
		while(!vs[26].empty()&&!vt[i].empty())
		{
			int A=vs[26].top(),B=vt[i].top();
			add(A,B);
			vs[26].pop(),vt[i].pop();
		}
	}
			while(!vs[26].empty()&&!vt[26].empty())
		{
			int A=vs[26].top(),B=vt[26].top();
			add(A,B);
			vs[26].pop(),vt[26].pop();
		}
	print();
    return 0;
}