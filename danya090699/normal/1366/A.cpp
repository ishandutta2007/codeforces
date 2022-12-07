#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int T;
    cin>>T;
    while(T--)
    {
        int a, b;
        cin>>a>>b;
        if(a>b) swap(a, b);
        int an=min(b-a, a);
        a-=an, an+=a/3*2;
        if(a%3==2) an++;
        cout<<an<<"\n";
    }
}