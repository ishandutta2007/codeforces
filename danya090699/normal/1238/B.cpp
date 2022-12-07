#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t)
    {
        t--;
        int n, r, an=0;
        scanf("%d%d", &n, &r);
        set <int> se;
        for(int a=0; a<n; a++)
        {
            int x;
            scanf("%d", &x);
            se.insert(x);
        }
        vector <int> ar;
        for(auto it=se.begin(); it!=se.end(); it++) ar.push_back(*it);
        reverse(ar.begin(), ar.end());
        for(int a=0; a<ar.size(); a++) if(ar[a]>(1ll*a*r)) an++;

        printf("%d\n", an);
    }
}