/*********************
*  Author: xuziyuan  * 
*********************/

#include <bits/stdc++.h>

#define rt0 return 0
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define replet(c) for(char c='a';c<='z';c++) 
#define LL long long
#define pii pair <int,int>
#define pb push_back
#define fi first
#define se second
#define mpr make_pair
#define sqr(a) ((a)*(a))

using namespace std;

const LL MOD=1e9+7;

LL r;

int main()
{
	cin>>r;
	r--;
	if(r<4)
	{
		puts("NO");
		rt0;
	}
	if(r%2==0)
	{
		cout<<1<<' '<<(r-2)/2<<endl;
		rt0;
	}
	puts("NO");
	rt0;
}