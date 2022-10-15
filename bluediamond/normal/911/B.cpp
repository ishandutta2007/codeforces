#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,a,b,sol=0;
    cin>>n>>a>>b;
    for(int i=1;i<n;i++)
    {
        sol=max(sol,min(a/i,b/(n-i)));
    }
    cout<<sol;
    return 0;
}
/**
**/