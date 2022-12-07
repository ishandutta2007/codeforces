#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int ar[3], d;
    cin>>ar[0]>>ar[1]>>ar[2]>>d;
    sort(ar, ar+3);
    cout<<max(d-(ar[1]-ar[0]), 0)+max(d-(ar[2]-ar[1]), 0);
}