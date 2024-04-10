#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, su=0, k=0;
    cin>>n;
    int ar[n];
    for(int a=0; a<n; a++)
    {
        cin>>ar[a], su+=ar[a], k=max(k, ar[a]);
    }
    for(k; ; k++)
    {
        int su2=0;
        for(int a=0; a<n; a++) su2+=k-ar[a];
        if(su2>su)
        {
            cout<<k;
            break;
        }
    }
}