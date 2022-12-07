#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, l, r;
    cin>>n>>l>>r;
    int mi=(n-l), ma=(n-r)*(1<<(r-1));
    for(int a=0; a<l; a++) mi+=(1<<a);
    for(int a=0; a<r; a++) ma+=(1<<a);
    cout<<mi<<" "<<ma;
}