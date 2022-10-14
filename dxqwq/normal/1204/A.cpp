// Problem: A. BowWow and the Timetable
// Contest: Codeforces - Codeforces Round #581 (Div. 2)
// URL: https://codeforces.com/contest/1204/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
const int p=998244353;
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
signed main()
{
	string s;
	cin>>s;
	int n=s.size();
	int c=0;
	for(int i=1; i<n; ++i) if(s[i]=='1') ++c;
	int N=n;
	if(N%2)
	{
	//100
	if(c) printf("%lld\n",N/2+1);
	else printf("%lld\n",N/2);	
	}
	else printf("%lld\n",(N+1)/2);
	return 0;
}