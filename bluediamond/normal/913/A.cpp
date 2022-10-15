#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,p=1;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    while(n and p<=m)
    {
        n--;
        p*=2;
    }
    if(p<=m)
        cout<<m%p;
    else
        cout<<m;
    return 0;
}
/**

**/