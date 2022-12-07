#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int a, b, c, n;
    cin>>a>>b>>c>>n;
    if(c>a or c>b) cout<<-1;
    else
    {
        int m=a+b-c;
        if(m<n) cout<<n-m;
        else cout<<-1;
    }
}