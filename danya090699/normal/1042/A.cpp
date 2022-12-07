#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    int ma=-1e9, su=0;
    for(int a=0; a<n; a++)
    {
        int q;
        cin>>q;
        ma=max(ma, q), su+=q;
    }
    cout<<max((su+m)/n+((su+m)%n>0), ma)<<" "<<ma+m;
}