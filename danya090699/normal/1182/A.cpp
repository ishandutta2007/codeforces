#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    if(n%2) cout<<0;
    else cout<<(1<<(n/2));
}