#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string an;
        for(int a=0; a<n; a++) an.push_back('9');
        int q=n;
        for(int a=n-1; a>=0; a--)
        {
            if(q>0) an[a]='8', q-=4;
        }
        cout<<an<<"\n";
    }
}