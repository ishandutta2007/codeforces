#include <bits/stdc++.h>
#define int long long
using namespace std;
int f(int n)
{
    return n*(n-1)/2+n;
}
main()
{
	//freopen("input.txt", "r", stdin);
	int t;
	cin>>t;
	while(t)
    {
        t--;
        int n, m;
        scanf("%lld%lld", &n, &m);
        int an=f(n);
        int q=(n-m)/(m+1);
        an-=f(q)*(m+1-(n-m)%(m+1));
        an-=f(q+1)*((n-m)%(m+1));
        printf("%lld\n", an);
    }
}