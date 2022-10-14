#include<bits/stdc++.h>
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
using namespace std;
int a[1000003];
int main()
{
	int n=read(),m=read();
	long long tot=0;
	for(int i=1; i<=m; i++) a[i]=read(),tot+=a[i];
	for(int i=1; i<=m; i++) if(i-1+a[i]>n) return 0&printf("-1\n");
	if(tot<n) return 0&printf("-1\n");
	if(m-1+a[m]>n) return 0&printf("-1\n");
	int pos=m;
	tot=0;
	while(pos+tot<n) tot+=a[pos--];
	if(pos==n) 
	{
		for(int i=1; i<=n; i++) printf("%d ",i);
		return 0;
	}
	for(int i=1; i<=pos+1; i++) printf("%d ",i);
	tot-=a[pos+1];
	for(int i=pos+2; i<=m; i++) printf("%d ",n-tot+1),tot-=a[i];
	return 0;
}