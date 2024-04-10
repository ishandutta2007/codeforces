#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, x, y;
    cin>>n>>x>>y;
    if(y%x==0)
    {
        int z=y/x, y2=y;
        vector <int> de, de2;
        for(int a=2; a<1e6+10; a++)
        {
            if(z%a==0)
            {
                de.push_back(a);
                while(z%a==0) z/=a;
                de2.push_back(1);
                {
                    while(y2%a==0)
                    {
                        de2.back()*=a, y2/=a;
                    }
                }
            }
        }
        int ar[n];
        for(int a=0; a<n; a++)
        {
            scanf("%lld", &ar[a]);
            int d=__gcd(ar[a], z);
            if(d!=1 and d!=z)
            {
                de.push_back(d), de.push_back(z/d);
                de2.push_back(d), de2.push_back(z/d);
                z=1;
            }
        }
        if(z>1)
        {
            de.push_back(z), de2.push_back(z);
        }
        int m=de.size();
        int q[1<<m], q2[1<<m];
        for(int a=0; a<(1<<m); a++)
        {
            q[a]=0, q2[a]=0;
        }
        for(int a=0; a<n; a++)
        {
            if(ar[a]%x==0)
            {
                int os=ar[a]/x, mask=0;
                for(int i=0; i<m; i++) if(os%de[i]==0) mask+=(1<<i);
                q[mask]++;
            }
            if(y%ar[a]==0)
            {
                int mask=0;
                for(int i=0; i<m; i++) if(ar[a]%de2[i]==0) mask+=(1<<i);
                q2[mask]++;
            }
        }
        int an=0;
        for(int mask2=0; mask2<(1<<m); mask2++)
        {
            if(q2[mask2])
            {
                int su=0;
                for(int mask=mask2; ; mask=(mask-1)&mask2)
                {
                    su+=q[mask];
                    if(mask==0) break;
                }
                an+=q2[mask2]*su;
            }
        }
        cout<<an;
    }
    else cout<<0;
}