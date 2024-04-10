// Problem: A. Cut and Paste
// Contest: Codeforces - Codeforces Round #607 (Div. 1)
// URL: https://codeforces.com/contest/1280/problem/A
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
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
const int p=1e9+7;
signed main()
{
	for(int T=read();T--;)
	{
		int n;
		string s;
		cin>>n>>s;
		int ans=s.size();
		for(int i=0; i<n; ++i)
		{
			int N=s[i]-'1';
			int S=s.size();
			if(N&&S<n)
			{
				string t=s.substr(i+1);
				for(int j=1; j<=N; j++) s+=t;
			}
			ans=(ans+(ans+p+p-i-1)*N)%p;
		}
		cout<<ans<<endl;
	}
	return 0;
}