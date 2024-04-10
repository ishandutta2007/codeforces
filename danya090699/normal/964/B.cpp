#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, a, b, c, t, an=0;
    cin>>n>>a>>b>>c>>t;
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        an+=max(a, a+(t-x)*(c-b));
    }
    cout<<an;
}