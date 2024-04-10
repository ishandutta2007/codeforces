// Problem: C2. Increasing Subsequence (hard version)
// Contest: Codeforces - Codeforces Round #555 (Div. 3)
// URL: https://codeforces.com/contest/1157/problem/C2
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
int a[1000003];
bool f[1000003];
void printl(int x){printf("L");return;}
void printr(int x){printf("R");return;}
signed main()
{
	int n=read();
	for(int i=1; i<=n; i++) a[i]=read();
	int d=1;
	while(d<n&&a[d+1]>a[d]) ++d;
	for(int i=1; i<=d; i++)f[a[i]]=1;
	int L=1,R=n+1;
	a[n+1]=-1;
	for(int l=d,r=n+1; l>=0; l--)
	{
		while(r>1&&a[r-1]>a[r]&&!f[a[r-1]]) --r;
		if(l+(n-r+1)>L+(n-R+1)) L=l,R=r;
		//printf("%d %d\n",l,r);
		f[a[l]]=0;
	}
	printf("%d\n",L+(n-R+1));
	int cl=1,cr=n;
	while(cl<=L&&R<=cr)
	{
		if(a[cl]<a[cr]) printl(a[cl++]);
		else printr(a[cr--]);
	}
	while(cl<=L) printl(a[cl++]);
	while(cr>=R) printr(a[cr--]);
    return 0;
}