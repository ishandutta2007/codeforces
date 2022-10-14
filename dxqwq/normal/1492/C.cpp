#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
char s[1000003],t[1000003];
int n=read(),m=read();
int A[1000003],B[1000003];
vector<int> v[1000003],g[1000003];
signed main()
{
	scanf("%s",s+1);
	scanf("%s",t+1);
	for(int i=1; i<=n; i++) v[s[i]-'a'].push_back(i);
	for(int i=n; i>=1; i--) g[s[i]-'a'].push_back(-i);
	for(int i=1; i<=m; i++) A[i]=*lower_bound(v[t[i]-'a'].begin(),v[t[i]-'a'].end(),A[i-1]+1);
	B[m+1]=100000000;
	for(int i=m; i>=1; i--) B[i]=-(*lower_bound(g[t[i]-'a'].begin(),g[t[i]-'a'].end(),-(B[i+1]-1)));
	int ans=0;
    for(int i=1; i<m; i++) ans=max(ans,B[i+1]-A[i]);
    printf("%d\n",ans);
	return 0;
}