#include<bits/stdc++.h>
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
inline long long readll(){
   long long s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
using namespace std;
char a[1000003];
int main()
{
	scanf("%s",a);
	int len=strlen(a),l=0,r=len-1;
	queue<char> Q;
	stack<char> S;
	while(l+1<r-1)
	{
		if(a[l]==a[r]) Q.push(a[l]),S.push(a[r]),++l,--r;
		else if(a[l]==a[r-1]) Q.push(a[l]),S.push(a[r-1]),++l,--r,--r;
		else if(a[l+1]==a[r]) Q.push(a[l+1]),S.push(a[r]),++l,++l,--r;
		else Q.push(a[l+1]),S.push(a[r-1]),++l,++l,--r,--r;
	}
	while(!Q.empty()) printf("%c",Q.front()),Q.pop();
	if(r-l==0) printf("%c",a[l]);
	if(r-l==1) if(a[l]==a[r]) printf("%c%c",a[l],a[r]); else printf("%c",a[l]);
	if(r-l==2) if(a[l]==a[r]) printf("%c%c%c",a[l],a[l+1],a[r]);
	else if(a[l]==a[l+1]) printf("%c%c",a[l],a[l+1]);
	else if(a[l+1]==a[r]) printf("%c%c",a[l+1],a[r]); else printf("%c",a[l]);
	while(!S.empty()) printf("%c",S.top()),S.pop();
	return 0;
}