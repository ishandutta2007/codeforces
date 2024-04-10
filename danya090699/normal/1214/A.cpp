#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, d, e, an;
    cin>>n>>d>>e;
    an=n;
    for(int a=0; a*d<=n; a++) an=min(an, (n-a*d)%(5*e));
    cout<<an;
}