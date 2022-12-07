#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, a, b, c;
    cin>>n>>a>>b>>c;
    if(n>1)
    {
        if(a<b) cout<<a+(n-2)*min(a, c);
        else cout<<b+(n-2)*min(b, c);
    }
    else cout<<0;
}