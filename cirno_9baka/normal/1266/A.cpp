#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long LL;
typedef long double lb;
#define ri register int
const lb PI=3.141592653589793238462643383279;
const ll inf=1000000000000000000ll;
const int N=600005,M=998244353;
int n,m,r[N],lim,t,i;
char c[10005];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",c+1);
		int f0=0,f1=0,s=0;
		for(i=1;c[i];++i)
		{
			if(c[i]-'0'==0&&f0==0)
				f0=1;
			else
				if(((c[i]-'0')&1)==0)
					f1=1;
			s+=c[i]-'0';
		}
		puts(f0&&f1&&s%3==0?"red":"cyan");
	}
}