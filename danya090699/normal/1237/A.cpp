#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, i=0;
    cin>>n;
    for(int a=0; a<n; a++)
    {
        int x;
        cin>>x;
        if(abs(x)%2)
        {
            int y=abs(x)/2;
            if(x<0) y=-y-1;
            if(i) y++;
            i^=1;
            cout<<y<<"\n";
        }
        else cout<<x/2<<"\n";
    }
}