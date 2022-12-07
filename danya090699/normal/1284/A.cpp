#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    string pre[n], suf[m];
    for(int a=0; a<n; a++) cin>>pre[a];
    for(int a=0; a<m; a++) cin>>suf[a];
    int q;
    cin>>q;
    for(int a=0; a<q; a++)
    {
        int i;
        cin>>i;
        i--;
        cout<<pre[i%n]<<suf[i%m]<<"\n";
    }
}