#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int ar[n], an=0, same=0;
    for(int a=0; a<n; a++) scanf("%d", &ar[a]);
    sort(ar, ar+n);
    long long su=0;
    for(int a=0; a+1<n; a++)
    {
        if(ar[a]==ar[a+1])
        {
            same++;
            if(ar[a]==0)
            {
                cout<<"cslnb";
                return 0;
            }
            if(a and ar[a-1]+1==ar[a])
            {
                cout<<"cslnb";
                return 0;
            }
            ar[a]--, an=1;
        }
    }
    if(same>1)
    {
        cout<<"cslnb";
        return 0;
    }
    for(int a=0; a<n; a++) su+=ar[a];
    an^=((su-1ll*(n-1)*n/2)&1ll);
    if(an) cout<<"sjfnb";
    else cout<<"cslnb";
}