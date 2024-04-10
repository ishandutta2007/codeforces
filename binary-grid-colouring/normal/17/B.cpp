#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>
#include <unistd.h> 
using namespace std;
//#pragma GCC optimize ("O3")
typedef long long ll;
const int lowbit(int x) { return x&-x; }
int read(){ int v = 0, f = 1;char c =getchar();
while( c < 48 || 57 < c ){if(c=='-') f = -1;c = getchar();}
while(48 <= c && c <= 57) v = v*10+c-48, c = getchar();
return v*f;}
/*
ios::sync_with_stdio(0);
cin.tie(0);
*/
/***************************timer******************************/
struct timer
{
   double t;
   timer() { t=clock(); }
   ~timer() { printf("\nruntime %.3f s\n", get_time()); }
   double get_time() { return (clock()-t)/CLOCKS_PER_SEC; }
};
/*************************************************************/
int x;
int g[1234];
int y,z;
int cnt = 0;
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		g[i] = 1<<30;
	}
	int m;
	cin>>m;
	while(m--)
	{
		cin>>x>>y>>z;
		g[y] = min(g[y],z);
	}
	int ans = 0;
	for(int i=1;i<=n;i++)
	{
		if(g[i]==(1<<30)) cnt++;
		else ans += g[i];
	}
	if(cnt>1)cout<<-1<<endl;
	else cout<<ans<<endl;
 }