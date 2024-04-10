#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int n, x;
        cin>>n>>x;
        int ar[n];
        for(int a=0; a<n; a++) scanf("%d", &ar[a]);
        sort(ar, ar+n, greater <int>());
        int yk=0, an=0;
        while(yk<n)
        {
            int q=1;
            while(yk<n and 1ll*ar[yk]*q<x)
            {
                q++, yk++;
            }
            if(yk<n)
            {
                an++, yk++;
            }
        }
        cout<<an<<"\n";
    }
}