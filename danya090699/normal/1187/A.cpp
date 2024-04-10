#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int T;
    cin>>T;
    while(T)
    {
        T--;
        int n, s, t;
        cin>>n>>s>>t;
        cout<<max(n-s, n-t)+1<<"\n";
    }
}