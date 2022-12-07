#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, an=0, rg=-1;
    cin>>n;
    for(int a=0; a<n; a++)
    {
        int x;
        cin>>x;
        rg=max(rg, x-1);
        if(rg==a) an++;
    }
    cout<<an;
}