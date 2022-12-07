#include <bits/stdc++.h>
using namespace std;
const int sz=2e5+10;
int add[sz], va[sz], pre[sz+1];
int main()
{
    int n, k, q, cu=0;
    cin>>n>>k>>q;
    for(int a=0; a<sz; a++) add[a]=0;
    for(int a=0; a<n; a++)
    {
        int l, r;
        cin>>l>>r;
        add[l-1]++, add[r]--;
    }
    pre[0]=0;
    for(int a=0; a<sz; a++)
    {
        cu+=add[a];
        va[a]=cu;
        pre[a+1]=pre[a];
        if(cu>=k) pre[a+1]++;
    }
    for(int a=0; a<q; a++)
    {
        int l, r;
        cin>>l>>r;
        cout<<pre[r]-pre[l-1]<<"\n";
    }
}