#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int ar[n], be=0, p;
    for(int a=0; a<n; a++)
    {
        scanf("%d", &ar[a]);
        if(ar[a]>be) be=ar[a], p=a;
    }
    vector <int> l, r;
    for(int a=0; a<p; a++) l.push_back(ar[a]);
    for(int a=n-1; a>p; a--) r.push_back(ar[a]);
    while(l.size() or r.size())
    {
        int cu=0;
        if(l.size()>0) cu=l.back();
        if(r.size()>0) cu=max(cu, r.back());
        if(cu<be) be=cu;
        else
        {
            cout<<"NO";
            return 0;
        }
        if(l.size() and l.back()==cu) l.pop_back();
        else r.pop_back();
    }
    cout<<"YES";
}