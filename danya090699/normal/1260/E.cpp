#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, fo=0;
    cin>>n;
    vector <int> ve;
    for(int a=0; a<n; a++)
    {
        int x;
        scanf("%d", &x);
        if(x==-1) fo=1;
        else
        {
            if(!fo) x=0;
            ve.push_back(x);
        }
    }
    long long an=0;
    multiset <int> se;
    for(int a=n/2; a; a/=2)
    {
        se.insert(ve.back());
        ve.pop_back();
        an+=*se.begin();
        se.erase(se.begin());
        for(int b=0; b<a-1; b++)
        {
            se.insert(ve.back());
            ve.pop_back();
        }
    }
    cout<<an;
}