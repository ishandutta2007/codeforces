#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int ar[n];
    for(int a=0; a<n; a++) cin>>ar[a];
    sort(ar, ar+n);
    cout<<ar[(n-1)/2];
}