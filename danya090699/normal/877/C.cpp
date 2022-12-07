#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    cout<<n+n/2<<"\n";
    for(int a=2; a<=n; a+=2) cout<<a<<" ";
    for(int a=1; a<=n; a+=2) cout<<a<<" ";
    for(int a=2; a<=n; a+=2) cout<<a<<" ";
}