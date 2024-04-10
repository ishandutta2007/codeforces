#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    int ar[n], an=0, fo=0;
    for(int a=0; a<n; a++)
    {
        int q;
        scanf("%lld", &ar[a]);
        an+=ar[a]*m;
    }
    sort(ar, ar+n);
    for(int a=0; a<m; a++)
    {
        int q;
        scanf("%lld", &q);
        if(q<ar[n-1])
        {
            cout<<-1;
            return 0;
        }
        if(q==ar[n-1]) fo=1;
        else
        {
            if(a!=m-1 or fo) an+=q-ar[n-1];
            else
            {
                if(n==1 or m==1)
                {
                    cout<<-1;
                    return 0;
                }
                else an+=q-ar[n-2];
            }
        }
    }
    cout<<an;
}