#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int ar[n];
    for(int a=0; a<n; a++) cin>>ar[a];
    int be=0, va=1e9;
    for(int t=1; t<110; t++)
    {
        int cu=0;
        for(int a=0; a<n; a++)
        {
            if(ar[a]<t) cu+=t-1-ar[a];
            else if(ar[a]>t) cu+=ar[a]-(t+1);
        }
        if(cu<va) be=t, va=cu;
    }
    cout<<be<<" "<<va;
}