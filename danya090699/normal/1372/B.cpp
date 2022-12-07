#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int n, pr=1;
        cin>>n;
        for(int a=2; a*a<=n; a++)
        {
            if(n%a==0)
            {
                cout<<n/a<<" "<<n-n/a<<"\n";
                pr=0;
                break;
            }
        }
        if(pr) cout<<"1 "<<n-1<<"\n";
    }
}