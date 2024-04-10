//Come on, make Togliatti great again!
#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, k, an=0;
    cin>>n>>k;
    set <pair <int, int>, greater <pair <int, int> > > se;
    int re[n];
    for(int a=0; a<k; a++)
    {
        int x;
        cin>>x;
        se.insert(make_pair(x, a));
    }
    for(int a=k; a<n; a++)
    {
        int x;
        cin>>x;
        se.insert(make_pair(x, a));
        int cu=(*se.begin()).second, va=(*se.begin()).first;
        se.erase(se.begin());
        an+=(a-cu)*va, re[cu]=a+1;
    }
    for(int a=0; a<k; a++)
    {
        int cu=(*se.begin()).second, va=(*se.begin()).first;
        se.erase(se.begin());
        an+=(n+a-cu)*va, re[cu]=n+a+1;
    }
    cout<<an<<"\n";
    for(int a=0; a<n; a++) cout<<re[a]<<" ";
}