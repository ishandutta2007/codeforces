#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    int n, k;
    cin>>n>>k;
    int x=1;
    for(int a=0; a<k; a++) x*=10;
    for(int a=1; ; a++)
    {
        if((n*a)%x==0)
        {
            cout<<n*a;
            break;
        }
    }
}