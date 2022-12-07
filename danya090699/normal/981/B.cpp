#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, an=0;
    cin>>n;
    map <int, int> ma;
    for(int a=0; a<n; a++)
    {
        int i, va;
        cin>>i>>va;
        ma[i]=max(ma[i], va);
    }
    cin>>m;
    for(int a=0; a<m; a++)
    {
        int i, va;
        cin>>i>>va;
        ma[i]=max(ma[i], va);
    }
    for(auto it=ma.begin(); it!=ma.end(); it++) an+=(*it).second;
    cout<<an;
}