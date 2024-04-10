#include <bits/stdc++.h>
using namespace std;
main()
{
    int w, h, an=1, mod=998244353;
    cin>>w>>h;
    for(int a=0; a<w+h; a++) an=(an+an)%mod;
    cout<<an;
}