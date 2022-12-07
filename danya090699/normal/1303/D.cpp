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
        int n, m, an=0;
        scanf("%lld%lld", &n, &m);
        int q[60];
        for(int i=0; i<60; i++) q[i]=0;
        for(int a=0; a<m; a++)
        {
            int x;
            scanf("%lld", &x);
            q[63-__builtin_clzll(x)]++;
        }
        for(int i=0; i<60; i++)
        {
            if(n&1)
            {
                if(!q[i])
                {
                    int yk=i;
                    while(yk<60 and !q[yk]) q[yk++]=1, an++;
                    if(yk==60)
                    {
                        an=-1;
                        break;
                    }
                    q[yk]--;
                }
                q[i]--;
            }
            if(i+1<60) q[i+1]+=q[i]>>1;
            n>>=1;
        }
        printf("%lld\n", an);
    }
}