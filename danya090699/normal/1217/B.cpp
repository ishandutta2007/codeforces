#include <bits/stdc++.h>
using namespace std;
int de(int x, int y){return x/y+(x%y>0);}
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t)
    {
        t--;
        int n, x, dif=0, ma=0;
        cin>>n>>x;
        for(int a=0; a<n; a++)
        {
            int d, h;
            cin>>d>>h;
            dif=max(dif, d-h), ma=max(ma, d);
        }
        if(ma>=x) cout<<1;
        else
        {
            if(dif) cout<<de(x-ma, dif)+1;
            else cout<<-1;
        }
        cout<<"\n";
    }
}