#include<bits/stdc++.h>
#define mp make_pair
#define pi pair<int,int>
#define pb push_back
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int a[1000003];
int mian()
{
	int n=read(),k=read();
	bool f=0;
	for(int i=1; i<=n; i++) a[i]=read(),(a[i]==k)&&(f=1);
	if(!f) return puts("no");
	if(n==1) return puts("yes");
	for(int i=1; i<n; i++) if(a[i]==k&&a[i+1]>=k) return puts("yes");
	for(int i=1; i<n; i++) if(a[i]>=k&&a[i+1]==k) return puts("yes");
	for(int i=1; i<n-1; i++) if(a[i]>=k&&a[i+2]>=k) return puts("yes");
	for(int i=1; i<n; i++) if(a[i]>=k&&a[i+1]>=k) return puts("yes");
	puts("no");
	return 0;
}
int main()
{ 
	for(int T=read();T--;) mian();
	return 0;
}