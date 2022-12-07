#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n;
    int ar[n];
    for(int a=0; a<n; a++) scanf("%lld", &ar[a]);
    cin>>m;
    int ar2[m];
    for(int a=0; a<m; a++) scanf("%lld", &ar2[a]);
    int yk=0, su=0, yk2=0, su2=0, an=0, ok=1;
    while(yk<n or yk2<m)
    {
        if(su==su2 and su!=0)
        {
            an++, su=0, su2=0;
        }
        else
        {
            if(su<su2)
            {
                if(yk<n)
                {
                    su+=ar[yk], yk++;
                }
                else
                {
                    ok=0;
                    break;
                }
            }
            else
            {
                if(yk2<m)
                {
                    su2+=ar2[yk2], yk2++;
                }
                else
                {
                    ok=0;
                    break;
                }
            }
        }
    }
    if(su!=su2) ok=0;
    if(ok) cout<<an+1;
    else cout<<-1;
}