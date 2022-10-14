// Problem: B. A Determined Cleanup
// Contest: Codeforces - Codeforces Round #462 (Div. 1)
// URL: https://codeforces.com/contest/933/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//
#include<bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
signed main()
{
	int n=read(),k=read();
	vector<int> vec;
	int op=0;
	while(n)
	{
		op^=1;
		if(op)
		{
			vec.push_back(n%k);
		}
		else
		{
			if(n%k) 
			vec.push_back((k-(n%k))%k),
			n+=((k-(n%k))%k);
			else vec.push_back(0);
		}
		n/=k;
	}
	printf("%lld\n",(int)vec.size());
	for(int i:vec) printf("%lld ",i);
	return 0;
}