#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, t;
    cin>>n>>t;
    int chsu=0, znsu=0;
    pair <int, int> ar[n];
    for(int a=0; a<n; a++) scanf("%lld", &ar[a].second);
    for(int a=0; a<n; a++) scanf("%lld", &ar[a].first);
    for(int a=0; a<n; a++)
    {
        chsu+=ar[a].first*ar[a].second, znsu+=ar[a].second;
    }
    sort(ar, ar+n);
    if(chsu<znsu*t)
    {
        int ch=0, zn=0;
        for(int a=n-1; a>=0; a--)
        {
            int ct=ar[a].first, v=ar[a].second;
            if(ch+ct*v>=t*(zn+v))
            {
                ch+=ct*v, zn+=v;
            }
            else
            {
                int x=ch-t*zn, y=(t-ct);
                double an=(zn+x/y)+(x%y*1.0)/y;
                cout<<fixed<<setprecision(10)<<an;
                break;
            }
        }
    }
    if(chsu>znsu*t)
    {
        int ch=0, zn=0;
        for(int a=0; a<n; a++)
        {
            int ct=ar[a].first, v=ar[a].second;
            if(ch+ct*v<=t*(zn+v))
            {
                ch+=ct*v, zn+=v;
            }
            else
            {
                int x=t*zn-ch, y=(ct-t);
                double an=(zn+x/y)+(x%y*1.0)/y;
                cout<<fixed<<setprecision(10)<<an;
                break;
            }
        }
    }
    else cout<<znsu;
}