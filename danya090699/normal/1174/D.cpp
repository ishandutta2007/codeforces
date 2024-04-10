#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, x, pr=0;
    cin>>n>>x;
    vector <int> an;
    for(int a=1; a<(1<<n); a++)
    {
        int b=a^x;
        //cout<<a<<" "<<b<<"\n";
        if(a<b) an.push_back(pr^a), pr=a;
    }
    cout<<an.size()<<"\n";
    for(int a=0; a<an.size(); a++) printf("%d ", an[a]);
}