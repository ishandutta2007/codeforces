#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int r;
    cin>>r;
    for(int x=1; x*x+x+1<r; x++)
    {
        int y=r-x*x-x-1;
        if(y%(2*x)==0)
        {
            cout<<x<<" "<<y/(2*x);
            return 0;
        }
    }
    cout<<"NO";
}