#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int ar[n];
    for(int a=0; a<n; a++) cin>>ar[a];
    sort(ar, ar+n);
    for(int a=0; a<n; a+=2) cout<<ar[a]<<" ";
    for(int a=(n-1)-(((n-1)%2)^1); a>0; a-=2) cout<<ar[a]<<" ";
}