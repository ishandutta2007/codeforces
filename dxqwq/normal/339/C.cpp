#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
bool a[1003][13][13];
char s[13];
signed main()
{
	scanf("%s",s+1);
	int m=read(),c=0;
	for(int i=1; i<=10; i++) if(s[i]=='1') a[1][i][i]=1;
	for(int i=2; i<=m; i++)
	{
		for(int L=1; L<=10; L++) for(int k=1; k<=10; k++) 
		if(a[i-1][k][L]) for(int j=k+1; j<=10; j++) if(L!=j&&s[j]=='1') a[i][j-k][j]=1;
	}
	int f=0,g=0;
	for(int i=1; i<=10; i++) for(int j=1; j<=10; j++) if(a[m][i][j]) f=i,g=j;
	if(f)
	{
		puts("YES");
		stack<int> ss;
		for(int i=m-1; i>=1; i--)
		{
			ss.push(g);
			for(int j=1; j<=10; j++) if(a[i][g-f][j]&&j!=g)
			{
				f=g-f,g=j;
				break;
			}
		}
		ss.push(g);
		while(!ss.empty()) 
		{
			printf("%d ",ss.top());
			ss.pop();
			
		}puts("");
	}
	else
	{
		puts("NO");
	}
    return 0;
}