// Problem: B. Bitwise Formula
// Contest: Codeforces - Codeforces Round #402 (Div. 1)
// URL: https://codeforces.com/contest/778/problem/B
// Memory Limit: 512 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
map<string,int> mp;
string s1[5003],s2[5003],s3[5003],s4[5003],s5[5003];
int f[5003],g[5003];
int n=read(),m=read();
int check(int x,int t)
{
	g[0]=t;
	int res=0;
	for(int i=1; i<=n; i++) 
	{
		if(f[i]==0)
		{
			g[i]=(s3[i][x]=='1');
			res+=g[i];
		}
		else
		{
			int A=g[mp[s3[i]]],B=g[mp[s5[i]]];
			if(s4[i][0]=='X')
			{
				g[i]=A^B;
			}
			else if(s4[i][0]=='O')
			{
				g[i]=A|B;
			}
			else
			{
				g[i]=A&B;
			}
			res+=g[i];
		}
	}
	return res;
}
int A[5003],B[5003];
signed main()
{
    
    for(int i=1; i<=n; i++)
    {
    	cin>>s1[i]>>s2[i]>>s3[i];
    	mp[s1[i]]=i;
    	if(s3[i][0]!='1'&&s3[i][0]!='0') f[i]=1,cin>>s4[i]>>s5[i];   	
    }
    for(int i=0; i<=m-1; i++)
    {
    	int X=check(i,0);
    	int Y=check(i,1);
    	//printf("%d %d\n",X,Y);
    	if(X<Y) A[i]=0,B[i]=1;
    	else if(X==Y) A[i]=0,B[i]=0;
    	else A[i]=1,B[i]=0;
    }
    for(int i=0; i<m; i++) printf("%d",A[i]);
    puts("");
    for(int i=0; i<m; i++) printf("%d",B[i]);
    puts("");
	return 0;
}