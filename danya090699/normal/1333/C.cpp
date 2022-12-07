#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, l=0, pref=0, an=0;
    cin>>n;
    map <int, int> ma;
    ma[0]=0;
    for(int a=1; a<=n; a++)
    {
        int x;
        scanf("%lld", &x);
        pref+=x;
        if(ma.find(pref)!=ma.end()) l=max(l, ma[pref]+1);
        ma[pref]=a;
        an+=a-l;
    }
    cout<<an;
}