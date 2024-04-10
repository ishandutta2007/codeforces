#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
	//freopen("input.txt", "r", stdin);
	int t;
	cin>>t;
	while(t)
    {
        t--;
        int n, g, b;
        scanf("%lld%lld%lld", &n, &g, &b);
        int l=n-1, r=2e18;
        while(r-l>1)
        {
            int mid=(l+r)>>1, q=mid/(g+b)*g+min(g, mid%(g+b));
            if(q*2>=n) r=mid;
            else l=mid;
        }
        printf("%lld\n", r);
    }
}