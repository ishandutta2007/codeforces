#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, p;
    cin>>n>>p;
    for(int a=0; (a<1000000 and n>=0); a++)
    {
        if(__builtin_popcount(n)<=a and n>=a)
        {
            cout<<a;
            return 0;
        }
        n-=p;
    }
    cout<<-1;
}