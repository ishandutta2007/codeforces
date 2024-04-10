#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int l=n, r=-1, q=0;
        for(int a=0; a<n; a++)
        {
            int x;
            scanf("%d", &x);
            x--;
            if(x!=a)
            {
                l=min(l, a), r=max(r, a), q++;
            }
        }
        if(q==0) cout<<"0\n";
        else if(q==r-l+1) cout<<"1\n";
        else cout<<"2\n";
    }
}