#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, yk=0, su=0;
    cin>>n>>m;
    int ar[n];
    for(int a=0; a<n; a++) cin>>ar[a];
    for(int a=0; a<m; a++)
    {
        int nu;
        cin>>nu;
        while(su+ar[yk]<nu)
        {
            su+=ar[yk], yk++;
        }
        cout<<yk+1<<" "<<nu-su<<"\n";
    }
}