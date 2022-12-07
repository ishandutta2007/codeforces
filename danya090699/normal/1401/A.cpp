#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        if(n<k) cout<<k-n<<"\n";
        else cout<<(n-k)%2<<"\n";
    }
}