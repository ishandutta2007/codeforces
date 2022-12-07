#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, x=2e9, q=0;
    cin>>n;
    int ar[n];
    for(int a=0; a<n; a++) scanf("%d", &ar[a]);
    for(int a=n-1; a>=0; a--)
    {
        if(a<x) q++;
        x=min(x, a-ar[a]);
    }
    cout<<q;
}