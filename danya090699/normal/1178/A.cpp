#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, x;
    cin>>n>>x;
    int co=x, su=x;
    vector <int> an;
    an.push_back(1);
    for(int a=1; a<n; a++)
    {
        int q;
        cin>>q;
        if(q*2<=x) an.push_back(a+1), co+=q;

        su+=q;
    }
    if(co*2>su)
    {
        cout<<an.size()<<"\n";
        for(int a=0; a<an.size(); a++) cout<<an[a]<<" ";
    }
    else cout<<0;
}