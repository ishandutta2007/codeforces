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

int main()
{
	int n;
	int siz;
	pair<int,int>houses[1234];
	cin>>n>>siz;
	for(int i=0;i<n;i++)
	{
		cin>>houses[i].first>>houses[i].second;
	}
	int ans = 2;
	sort(houses,houses+n);
	for(int i=1;i<n;i++)
	{
		int space = (houses[i].first - houses[i-1].first) * 2 - houses[i].second - houses[i-1].second;
		if(space >= siz * 2)
		{
			ans++;
		}
		if(space > siz * 2)
		{
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
 }