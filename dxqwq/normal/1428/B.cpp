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
char a[2000003];
bool f[2000003];
int main()
{
	int T=read();
	while(T--)
	{
		int n=read();
		for(int i=0; i<n*2; i++) f[i]=0;
		scanf("%s",a);
		for(int i=0; i<n; i++) a[n+i]=a[i];
		int cnt1=0;
		for(int i=0; i<n; i++) if(a[i]!='>') ++cnt1;
		for(int i=n; i<n*2; i++) 
		{
			if(cnt1==n) f[i-n]=1;
			if(a[i]!='>') ++cnt1;
			if(a[i-n]!='>') --cnt1;
		 }  
		cnt1=0;
		for(int i=2*n-1; i>=n; i--) if(a[i]!='<') ++cnt1;
		for(int i=n-1; i>=0; i--) 
		{
			if(cnt1==n) f[i]=1;
			if(a[i]!='<') ++cnt1;
			if(a[i+n]!='<') --cnt1;
		 } 
		for(int i=0; i<n; i++) if(a[i]=='-' || a[(i+n-1)%n]=='-') f[i]=1;
		int ans=0;
		for(int i=0; i<n; i++) ans+=f[i];
		printf("%d\n",ans);
	}
	return 0;
}