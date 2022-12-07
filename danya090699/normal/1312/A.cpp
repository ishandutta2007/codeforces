#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t)
    {
        t--;
        int m, n;
        cin>>m>>n;
        cout<<(m%n==0 ? "YES\n" : "NO\n");
    }
}