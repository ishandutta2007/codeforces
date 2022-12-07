#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int b, g, n;
    cin>>b>>g>>n;
    b=min(b, n), g=min(g, n);
    cout<<b-(n-g)+1;
}