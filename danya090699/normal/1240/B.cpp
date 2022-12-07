#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int q;
    cin>>q;
    while(q)
    {
        q--;
        int n;
        scanf("%d", &n);
        set <int> se;
        int l[n], r[n];
        for(int a=0; a<n; a++) l[a]=-1, r[a]=-1;
        for(int a=0; a<n; a++)
        {
            int x;
            scanf("%d", &x);
            x--;
            if(l[x]==-1) l[x]=a;
            r[x]=a;
            se.insert(x);
        }
        vector <int> sp;
        for(auto it=se.begin(); it!=se.end(); it++) sp.push_back(*it);
        int yk=0, an=sp.size();
        //cout<<sp.size();
        while(yk<sp.size())
        {
            int q=1;
            while(yk+1<sp.size() and l[sp[yk+1]]>r[sp[yk]]) yk++, q++;
            an=min(an, int(sp.size())-q);
            yk++;
        }
        printf("%d\n", an);
    }
}