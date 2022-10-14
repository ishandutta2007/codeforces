// Problem: E. Longest Increasing Subsequence
// Contest: Codeforces - Codeforces Round #315 (Div. 1)
// URL: https://codeforces.com/problemset/problem/568/E
// Memory Limit: 128 MB
// Time Limit: 1500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int a[1000003],b[1000003];
int f[1000003],ans[1000003];
int lst[1000003],pre[1000003];
int A[1000003],B[1000003],C;
signed main()
{
	int n=read();
	for(int i=1; i<=n; ++i) a[i]=read();
	a[++n]=1000000001;
	multiset<int> s;
	int m=read();
	for(int i=1; i<=m; ++i) b[i]=read(),s.insert(b[i]);
	sort(b+1,b+m+1);
	m=unique(b+1,b+m+1)-b-1;
	int len=0;
	memset(f,0x3f,sizeof(f)),f[0]=0;
	for(int i=1; i<=n; ++i)
	{
		if(a[i]==-1)
		{
			C=0;
			for(int j=1,pos=1; j<=m; ++j)
			{
				while(f[pos]<b[j]) ++pos;
				if(pos>len) ++len;
				A[++C]=pos,B[C]=b[j];
			}
			for(int j=1; j<=C; ++j) 
				if(f[A[j]]>B[j])
					f[A[j]]=B[j],lst[A[j]]=i;
		}
		else
		{
			int pos=lower_bound(f,f+len+1,a[i])-f;
			pre[i]=lst[pos-1],ans[i]=pos;
			if(pos>len) ++len;
			if(f[pos]>a[i]) f[pos]=a[i],lst[pos]=i;
		}
	}
	int cur=n;
	bool haspre=1;
	for(int i=len; i>=1; --i)
	{
		if(haspre) 
		{
			int V=a[cur];
			cur=pre[cur],haspre=(a[cur]!=-1);
			if(!haspre)
			{
				auto it=s.lower_bound(V);
				--it;
				int val=*it;
				a[cur]=val,s.erase(it);
			}
		}
		else
		{
			bool flg=0;
			for(int j=cur; j>=0; --j) if(a[j]!=-1&&ans[j]==i-1&&a[j]<a[cur])
			{
				flg=1,cur=j,haspre=1;
				break;
			}
			if(!flg)
			{
				haspre=0;
				auto it=s.lower_bound(a[cur]);
				--it;
				int val=*it;
				for(int j=cur-1; j>=0; --j) if(a[j]==-1)
				{
					a[j]=val,cur=j,s.erase(it),flg=1;
					break;
				}
			}
		}
	}
	for(int i=1; i<=n; ++i) if(a[i]==-1) 
		a[i]=*s.begin(),s.erase(s.begin()); 
	for(int i=1; i<n; ++i) printf("%d ",a[i]);
	return 0;
}