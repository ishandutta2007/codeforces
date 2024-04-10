#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,a,b;
    cin>>n>>m>>a>>b;
    if(b/m>=a)
    cout<<n*a;
    else
    {
    if(b<(n%m)*a)
    cout<<(n/m*b)+b;
    else cout<<(n/m*b)+(n%m*a);
    }
    return 0; 
}