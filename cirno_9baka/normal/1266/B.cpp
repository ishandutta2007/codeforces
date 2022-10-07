#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long LL;
typedef long double lb;
#define ri register int
const lb PI=3.141592653589793238462643383279;
const ll inf=1000000000000000000ll;
const int N=600005,M=998244353;
int m,r[N],lim,t,i;
long long n;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&t);
	while(t--)
	{
		cin>>n;
		bool f=false;
		for(i=1;i<=6;++i)
			if(n>=i+14&&(n-i-14)%14==0)
				break;
		puts(i<=6?"YES":"NO");
	}
}