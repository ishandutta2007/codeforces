// Problem: A. Cram Time
// Contest: Codeforces - Codeforces Round #517 (Div. 1, based on Technocup 2019 Elimination Round 2)
// URL: https://codeforces.com/contest/1071/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
vector<int> a;
bool f[1000003];
signed main()
{
 	int n=read(),m=read();
 	int l=1,r=1000000,ans=0;
 	 while(l<=r)
 	 {
 	 	vector<int> tmp;
 	 	int mid=(l+r)>>1;
 	 	if(mid*(mid+1)/2>n+m)
 	 	{
 	 		r=mid-1;
 	 		continue;
 	 	}
 	 	ans=mid;
 	 	int x=n;
 	 	for(int i=mid; i>=1; i--) if(x>=i) x-=i,tmp.push_back(i);
 	 	else
 	 	{
 	 		if(x==0) break;
 	 		tmp.push_back(x);
 	 		break;
 	 	}
 	 	tmp.swap(a);
 	 	l=mid+1;
 	 }  
 	 for(int x:a) f[x]=1;
 	printf("%lld\n",(int)a.size());
 	for(int i=1; i<=ans; i++) if(f[i])printf("%lld ",i);
 	puts("");
 	printf("%lld\n",ans-(int)a.size());
 	for(int i=1; i<=ans; i++) if(f[i]==0)printf("%lld ",i);
	return 0;
}