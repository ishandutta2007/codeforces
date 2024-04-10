#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    double an=1e9;
    for(int a=0; a<n; a++)
    {
        int x, y;
        cin>>x>>y;
        an=min(an, x*1.0/y*m);
    }
    cout<<fixed<<setprecision(10)<<an;
}