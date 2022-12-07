#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, s;
    cin>>n>>s;
    if(s>=n*2)
    {
        cout<<"YES\n";
        for(int a=0; a<n-1; a++) printf("2 ");
        cout<<2+s-(n*2)<<"\n";
        cout<<1;
    }
    else cout<<"NO";
}