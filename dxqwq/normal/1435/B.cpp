#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int ans[503][503];
int maps[250003];
int main(){
    for(int T=read(); T--;)
    {
		int n=read(),m=read();
		for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) maps[read()]=j;
		for(int i=1; i<=m; i++) for(int j=1,x; j<=n; j++) x=read(),ans[j][maps[x]]=x;
		for(int i=1; i<=n; i++,puts("")) for(int j=1; j<=m; j++) printf("%d ",ans[i][j]);
	}
}