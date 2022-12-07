#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, k;
    cin>>n>>k;
    int q[k];
    for(int a=0; a<k; a++) q[a]=0;
    for(int a=0; a<n; a++)
    {
        int x;
        cin>>x;
        x--, q[x]++;
    }
    int bad=0;
    for(int a=0; a<k; a++) bad+=(q[a]&1);
    cout<<n-bad/2;
}