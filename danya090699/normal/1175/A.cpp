#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t)
    {
        t--;
        int n, k, an=0;
        cin>>n>>k;
        while(n)
        {
            if(n%k) an+=n%k, n-=n%k;
            else n/=k, an++;
        }
        cout<<an<<"\n";
    }
}