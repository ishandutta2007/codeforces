#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, k;
    cin>>n>>k;
    int an=(k-1)/2;
    if(n<k-1) an-=(k-1)-n;
    cout<<max(an, 0ll);
}