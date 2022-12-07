#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin>>n>>k;
    if(n==k or k==0) cout<<"0 ";
    else cout<<"1 ";
    cout<<min(n-k, k*2);
}