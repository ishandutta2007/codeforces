#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int q;
    cin>>q;
    for(int a=0; a<q; a++)
    {
        int n, m, k;
        cin>>n>>m>>k;
        int x=n+m, y=n-m;
        if(x%2==0)
        {
            int os=k-(x/2+abs(y)/2);
            if(os>=0)
            {
                if(os%2==0) cout<<k;
                else cout<<k-2;
            }
            else cout<<-1;
        }
        else
        {
            int os=k-(x/2+abs(y)/2+1);
            if(os>=0) cout<<k-1;
            else cout<<-1;
        }
        cout<<"\n";
    }
}