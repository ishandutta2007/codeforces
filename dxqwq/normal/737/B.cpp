// Problem: B. Sea Battle
// Contest: Codeforces - Codeforces Round #380 (Div. 1, Rated, Based on Technocup 2017 - Elimination Round 2)
// URL: https://codeforces.com/contest/737/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
char s[1000003];
int f[1000003];
pair<int,int> p[1000003];
int S[1000003];
vector<int> V;
void Add(int x)
{
	V.push_back(x);
}
void Print()
{
	printf("%lld\n",(int)V.size());
	for(int i:V) printf("%lld ",i);
}
signed main()
{
	int n=read(),a=read(),b=read(),k=read();
	scanf("%s",s+1);
	for(int i=1; i<=n; ++i) if(s[i]=='1') f[i]=0;
	else f[i]=f[i-1]+1;
	int c=0,G=0;
	for(int i=1; i<=n; ++i) if(i==n||s[i+1]=='1') 
	if(f[i]) 
	p[++c]=make_pair(f[i],i-f[i]),S[c]+=f[i]/b,G+=S[c];
	G-=a;
	assert(G>=0);
	for(int i=1; i<=c; ++i)
	{
		for(int j=b,k=1; k<=S[i]&&G>=0; ++k,j+=b)
		{
			Add(p[i].second+j);
			--G;
		}
	}
	Print();
	return 0;
}