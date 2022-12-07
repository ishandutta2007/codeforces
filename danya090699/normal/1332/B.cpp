#include <bits/stdc++.h>
using namespace std;
const int sz=1e3+10;
int c[sz];
main()
{
    int q=1;
    for(int a=2; a<sz; a++)
    {
        if(!c[a])
        {
            for(int b=a+a; b<sz; b+=a) if(!c[b]) c[b]=q;
            q++;
        }
    }
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        map <int, int> ma;
        int ar[n];
        for(int a=0; a<n; a++)
        {
            cin>>ar[a];
            ma[c[ar[a]]]=0;
        }
        int m=1;
        for(auto it=ma.begin(); it!=ma.end(); it++) (*it).second=m++;
        cout<<m-1<<"\n";
        for(int a=0; a<n; a++) cout<<ma[c[ar[a]]]<<" ";
        cout<<"\n";
    }
}