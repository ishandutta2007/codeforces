#include <bits/stdc++.h>
using namespace std;
main()
{
    int p, y, fo=0;
    cin>>p>>y;
    for(y; y>p; y--)
    {
        int ok=1;
        for(int a=2; (a<=p and a*a<=y); a++) if(y%a==0) ok=0;
        if(ok)
        {
            fo=1;
            cout<<y;
            break;
        }
    }
    if(fo==0) cout<<-1;
}