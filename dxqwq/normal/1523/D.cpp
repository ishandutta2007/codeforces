// Problem: D. Love-Hate
// Contest: Codeforces - Deltix Round, Spring 2021 (open for everyone, rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1523/problem/D
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//If I can prove that everyone is wrong......
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
ll a[1000003];
int n=read(),m=read(),k=read();
bool check(int X)
{
	int S=(n+1)>>1;
	int C=0;
	for(int i=1; i<=n; ++i) if((a[i]&X)==X) ++C;
	return C>=S;
}
signed main()
{
	mt19937 rnd(time(0));
    srand(time(0));
    char s[66];
    for(int i=1; i<=n; ++i)
    {
    	scanf("%s",s+1);
    	for(int j=1; j<=m; ++j) 
    	if(s[j]=='1')a[i]+=1ll<<(m-j);
    }
    int ans=0;
    int cnt=0;
    int p[103];
    for(int j=1; j<=m; ++j) p[j]=j-1;
    for(int i=1; i<=100; ++i)
    {
    	
    	random_shuffle(p+1,p+m+1);
    	int cur=0;
    	for(int j=1; j<=m; ++j)
    	{
    		int A=1ll<<p[j];
    		cur+=A;
    		if(!check(cur)) cur-=A;
    	}
    	if(__builtin_popcountll(cur)>cnt)
    	{
    		ans=cur;
    		cnt=__builtin_popcountll(cur);
    	}
    }
    for(int i=m-1; i>=0; --i) if((1ll<<i)&ans) printf("1");
    else printf("0");
	return 0;
}