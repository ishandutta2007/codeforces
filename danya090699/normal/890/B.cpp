#include <bits/stdc++.h>
using namespace std;
const int sz=2e5+10;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, pr[sz];
    cin>>n;
    for(int a=0; a<sz; a++) pr[a]=-1;
    for(int a=0; a<n; a++)
    {
        int x;
        cin>>x;
        pr[x]=a;
    }
    int be=-1, bva=1e9;
    for(int a=0; a<sz; a++)
    {
        if(pr[a]!=-1 and pr[a]<bva)
        {
            be=a, bva=pr[a];
        }
    }
    cout<<be;
}