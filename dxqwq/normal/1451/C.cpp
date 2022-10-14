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
char a[1000003],b[1000003];
int A[26],B[26];
int main()
{
	int T=read();
	while(T--)
	{
		int n=read(),k=read();
		scanf("%s",a+1);
		scanf("%s",b+1); 
		for(int i=0; i<26; i++) A[i]=B[i]=0;
		for(int i=1; i<=n; i++) ++A[a[i]-'a'];
		for(int i=1; i<=n; i++) ++B[b[i]-'a'];
		bool f=1;
		for(int i=0; i<26; i++) if((A[i]-B[i])%k) f=0;
		for(int i=0,x=0,y=0; i<26; i++)
		{
			x+=A[i]/k,y+=B[i]/k;
			if(x<y) f=0;
		}
		if(f) puts("YES");
		else puts("NO");
	}
	return 0;
}