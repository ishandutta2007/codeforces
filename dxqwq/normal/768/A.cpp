#include<bits/stdc++.h>
#define mp make_pair
#define pi pair<int,int>
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
int a[100003];
signed main()
{
	int n=read();
	int mn=1000000003,mx=-1;
	for(int i=1; i<=n; i++) a[i]=read(),mn=min(a[i],mn),mx=max(a[i],mx);
	int cnt=0;
	for(int i=1; i<=n; i++) if(a[i]!=mn && a[i]!=mx) ++cnt;
	printf("%d\n",cnt);
	return 0;
}