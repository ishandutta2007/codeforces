#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    map <int, int> ma;
    for(int a=0; a<n; a++)
    {
        int x;
        scanf("%lld", &x);
        ma[x-a]+=x;
    }
    int an=0;
    for(auto it=ma.begin(); it!=ma.end(); it++) an=max(an, (*it).second);
    cout<<an;
}