#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin>>n>>k;
    int mod=(n-k)/2+1;
    for(int a=0; a<n; a++) cout<<(a%mod!=mod-1);
}