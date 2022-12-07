#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, ma=0;
    cin>>n;
    for(int a=0; a<n; a++)
    {
        int x;
        cin>>x;
        ma=max(ma, x);
    }
    if(ma>25) cout<<ma-25;
    else cout<<0;
}