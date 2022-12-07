#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin>>n>>m;
    m=n-m;
    if(m>n/2)
    {
        m-=n/2+n%2;
        cout<<max(1, n/2-m);
    }
    else cout<<m;
}