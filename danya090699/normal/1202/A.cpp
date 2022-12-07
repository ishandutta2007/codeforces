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
        string x, y;
        cin>>x>>y;
        int an=0;
        while(y.back()=='0') y.pop_back(), x.pop_back();
        while(x.back()=='0') x.pop_back(), an++;
        cout<<an<<"\n";
    }
}