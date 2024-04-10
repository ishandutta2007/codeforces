#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int k, d, t;
    cin>>k>>d>>t;
    t*=2;
    if(k>d) d=d*(k/d+(k%d>0));
    int q=k*2+(d-k);
    int an=(t/q)*d;
    if(t%q<k*2)
    {
        an+=(t%q)/2;
        cout<<an;
        if((t%q)%2) cout<<".5";
    }
    else cout<<an+(t%q)-k;
}