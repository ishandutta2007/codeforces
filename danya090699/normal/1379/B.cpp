#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int T;
    cin>>T;
    while(T--)
    {
        int l, r, m;
        cin>>l>>r>>m;
        for(int a=l; a<=r; a++)
        {
            if(m%a<=r-l and m>=a)
            {
                cout<<a<<" "<<r<<" "<<r-m%a<<"\n";
                break;
            }
            else if(a-m%a<=r-l)
            {
                cout<<a<<" "<<l<<" "<<l+(a-m%a)<<"\n";
                break;
            }
        }
    }
}