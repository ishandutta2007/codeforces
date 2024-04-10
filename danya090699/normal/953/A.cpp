#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    int l, r, x=1, an=0;
    cin>>l>>r;
    for(int a=0; a<=30; a++)
    {
        for(int b=0; b<=30; b++)
        {
            if(r/(1<<b)>=x)
            {
                if(x*(1<<b)>=l) an++;
            }
        }
        x*=3;
    }
    cout<<an;
}