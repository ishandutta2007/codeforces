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
int a[123];
int main()
{
	int n;
	int suma=0,sumb=0;
	n=read();
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	if(a[i]%2==1)suma++;
    	else sumb++;
	}
	if(suma==1)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]%2==1)cout<<i<<endl;
		}
	}
	else if(sumb==1)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]%2==0)cout<<i<<endl;
		}
	}
	return 0;
}