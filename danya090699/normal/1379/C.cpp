#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int T;
    cin>>T;
    while(T--)
    {
        int n, m, an=0;
        cin>>n>>m;
        int fl[m][2], w[m], pref[m+1];
        for(int a=0; a<m; a++)
        {
            cin>>fl[a][0]>>fl[a][1];
            w[a]=fl[a][0];
        }
        sort(w, w+m, greater <int>());
        pref[0]=0;
        for(int a=1; a<=m; a++) pref[a]=pref[a-1]+w[a-1];
        if(n<=m) an=pref[n];
        for(int a=0; a<m; a++)
        {
            int q=upper_bound(w, w+m, fl[a][1], greater <int>())-w;
            int cu=pref[q];
            if(fl[a][0]<fl[a][1]) cu+=fl[a][0], q++;
            if(q<=n)
            {
                cu+=(n-q)*fl[a][1];
                an=max(an, cu);
            }
        }
        cout<<an<<"\n";
    }
}