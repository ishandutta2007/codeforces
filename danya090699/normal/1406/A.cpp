#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int n, q=2, an=0;
        cin>>n;
        map <int, int> ma;
        for(int a=0; a<n; a++)
        {
            int x;
            cin>>x;
            ma[x]++;
        }
        for(int a=0; q>0; a++)
        {
            while(ma[a]<q) q--, an+=a;
        }
        cout<<an<<"\n";
    }
}