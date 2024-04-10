#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    int n, be=360;
    cin>>n;
    int ar[n];
    for(int a=0; a<n; a++) cin>>ar[a];
    for(int a=0; a<n; a++)
    {
        int su=0;
        for(int b=0; b<n; b++)
        {
            su+=ar[(a+b)%n];
            be=min(be, abs(su-(360-su)));
        }
    }
    cout<<be;
}