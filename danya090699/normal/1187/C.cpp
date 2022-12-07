#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    int ar[n], sm[n];
    for(int a=0; a<n; a++) sm[a]=0;
    vector <pair <int, int> > sp;
    for(int a=0; a<m; a++)
    {
        int ty, l, r;
        cin>>ty>>l>>r;
        l--, r--;
        if(ty)
        {
            for(int b=l; b+1<=r; b++) sm[b]=1;
        }
        else sp.push_back({l, r});
    }
    int yk=0;
    while(yk<n)
    {
        int cu=n+1-yk;
        while(sm[yk]) ar[yk]=cu, yk++;
        ar[yk]=cu, yk++;
    }
    for(int a=0; a<sp.size(); a++)
    {
        bool fo=0;
        for(int b=sp[a].first; b+1<=sp[a].second; b++)
        {
            if(ar[b]>ar[b+1]) fo=1;
        }
        if(fo==0)
        {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES\n";
    for(int a=0; a<n; a++) cout<<ar[a]<<" ";
}