#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, rg=0;
    cin>>n>>m;
    for(int a=0; a<n; a++)
    {
        int l, r;
        cin>>l>>r;
        if(l<=rg) rg=max(rg, r);
    }
    if(rg==m) cout<<"YES";
    else cout<<"NO";
}