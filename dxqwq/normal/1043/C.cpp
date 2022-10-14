// Problem: C. Smallest Word
// Contest: Codeforces - Codeforces Round #519 by Botan Investments
// URL: https://codeforces.com/contest/1043/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// zhoukangyang 
#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
	return s*w;
}
string s;
void solve(int x,bool f)
{
	if(x==1)
	{
		printf("0 ");
		return ;
	}
	if(!f)//target:aaabbb
	if(s[x-1]=='a') solve(x-1,1),printf("1 ");
	else solve(x-1,0),printf("0 ");
	else ///bbbaaa
	if(s[x-1]=='a') solve(x-1,1),printf("0 ");
	else solve(x-1,0),printf("1 ");
}
signed main()
{
	cin>>s;
	int n=s.size();
	solve(n,0);
    return 0;
}