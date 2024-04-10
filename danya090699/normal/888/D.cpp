#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, k, x=1, an=0;
    cin>>n>>k;
    int q[]={0, 1, 2, 9}, f[]={1, 2, 6, 24};
    for(int a=0; a<min(k, n); a++)
    {
        x*=(n-a);
        an+=(x/f[a])*q[a];
    }
    cout<<an+1;
}