#include<bits/stdc++.h>
#define pb push_back
//#define int long long
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
vector<int> v;
signed main()
{
	int n=read(),k=read()%64,x=read();
	for(int i=1,x; i<=n; i++) x=read(),v.push_back(x);
	while(k--)
	{
		sort(v.begin(),v.end());
		for(int i=0; i<n; i+=2) v[i]^=x;
	}
	sort(v.begin(),v.end());
	printf("%d %d\n",v[n-1],v[0]);
	return 0;
}