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
int x[60100];
int v[60100];
int n;
bool check(double time)
{
	double L = 0,R = 1e9;
	for(int i=1;i<=n;i++)
	{
		L = max(L,x[i]-v[i]*time);
		R = min(R,x[i]+v[i]*time);
	}
	return L<=R; 
}
int main()
{
	n=read();
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>v[i];
	}
	double l=0,r=1e9;
	double mid;
	for(int i=1;i<=200;i++)
	{
		mid = (l+r)/2;
		if(check(mid))
		{
			r = mid;
		}
		else l = mid;
	}
	printf("%.12f\n",mid);
	return 0;
 }