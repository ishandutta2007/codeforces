#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, mi=2e9, ma=-2e9, be=0;
    cin>>n;
    for(int a=0; a<n; a++)
    {
        int l, r;
        cin>>l>>r;
        mi=min(mi, r), ma=max(ma, l);
    }
    cin>>m;
    for(int a=0; a<m; a++)
    {
        int l, r;
        cin>>l>>r;
        if(l>mi) be=max(be, l-mi);
        if(r<ma) be=max(be, ma-r);
    }
    cout<<be;
}