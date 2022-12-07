#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int T;
    cin>>T;
    while(T--)
    {
        int n, l, r, m;
        cin>>n>>l>>m;
        r=l;
        for(int a=0; a<m; a++)
        {
            int l2, r2;
            cin>>l2>>r2;
            if(max(l, l2)<=min(r, r2))
            {
                l=min(l, l2), r=max(r, r2);
            }
        }
        cout<<r-l+1<<"\n";
    }
}