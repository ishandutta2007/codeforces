#include <cstdio>
#include <iostream>	
#include <algorithm>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;
#define LL long long 
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=1;i<=n;++i)
#define x0 gtmshb
#define x1 gtmjtjl
#define y0 gtmsub
#define y1 gtmsf
const long long base=288230376151711744LL;
int n,a[210000];
int main()
{	
	int T;
	cin>>T;
	while (T--)
	{
		scanf("%d",&n);
		long long sum1=0,sum2=0;
		for(int i=1;i<=n;i++){ int x; scanf("%d",&x); sum1=sum1+x; sum2=sum2^x; }
		if (sum1==2*sum2)
		{
			puts("0");
			continue;
		}
		puts("3");
		long long tbase=base;
		if (sum1&1)tbase++;
		sum1+=tbase,sum2^=tbase;
		long long sum3=(2*sum2-sum1)/2;
		printf("%lld %lld %lld\n",tbase,sum3,sum3);

	}
	return 0;
}