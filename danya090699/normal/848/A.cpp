//Come on, make Togliatti great again!
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int sz=1e5+01;
main()
{
    //freopen("input.txt", "r", stdin);
    int k, yk=0;
    cin>>k;
    if(k==0) cout<<"a";
    else
    {
        while(k>0)
        {
            char cu='a'+yk;
            //if(yk>=26) while(1) cout<<1;
            for(int a=2; a<sz; a++)
            {
                if(k<(a*(a-1))/2)
                {
                    k-=((a-1)*(a-2))/2;
                    for(int b=0; b<a-1; b++) cout<<cu;
                    break;
                }
            }
            yk++;
        }
    }
}