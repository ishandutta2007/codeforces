#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    int a, b, q=0;
    cin>>a>>b;
    while(a<=b)
    {
        a*=3, b*=2, q++;
    }
    cout<<q;
}