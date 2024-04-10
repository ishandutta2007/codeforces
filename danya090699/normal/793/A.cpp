#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, k, an=0, pos=1, mi=2e9;
    cin>>n>>k;
    int ar[n];
    for(int a=0; a<n; a++)
    {
        cin>>ar[a];
        mi=min(ar[a], mi);
    }
    for(int a=0; a<n; a++)
    {
        if((ar[a]-mi)%k!=0) pos=0;
        else an+=(ar[a]-mi)/k;
    }
    if(pos) cout<<an;
    else cout<<-1;
}