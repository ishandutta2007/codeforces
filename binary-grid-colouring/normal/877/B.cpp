#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>
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
int numa[12345],numb[12345];
int main()
{
	int len = 0;
	string s;
	cin>>s;
	len = (int)s.size();
	for(int i=0;i<len;i++)
	{
		numa[i+1] = numa[i] + (s[i]=='a');
		numb[i+1] = numb[i] + (s[i]=='b');
	}
	int ans = 0;
	for(int i=1;i<=len+1;i++)
	{
		for(int j=i;j<=len+1;j++)
		{
			ans = max(ans,numa[len]-numa[j-1]+numb[j-1]-numb[i-1]+numa[i-1]);//a...a b...b a...a 
		}
	}
	cout<<ans<<endl;
	return 0;
}