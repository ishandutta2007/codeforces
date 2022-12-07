#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, q;
    cin>>n>>q;
    int ar[n], va[n][2];
    for(int a=0; a<n; a++) scanf("%lld", &ar[a]);
    int ma=ar[0];
    vector <int> st;
    for(int a=1; a<n; a++)
    {
        va[a][0]=ma, va[a][1]=ar[a];
        if(ma<ar[a]) st.push_back(ma), ma=ar[a];
        else st.push_back(ar[a]);
    }
    for(int a=0; a<q; a++)
    {
        int nu;
        scanf("%lld", &nu);
        nu--;
        if(nu/(n-1)) printf("%lld %lld\n", ma, st[nu%(n-1)]);
        else printf("%lld %lld\n", va[nu+1][0], va[nu+1][1]);
    }
}