#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    for(int a=0; a<n; a++)
    {
        int k, x;
        cin>>k>>x;
        cout<<x+(k-1)*9<<"\n";
    }
}