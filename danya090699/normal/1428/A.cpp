#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int x1, y1, x2, y2;
        cin>>x1>>y1>>x2>>y2;
        int an=abs(x1-x2)+abs(y1-y2);
        if(x1!=x2 and y1!=y2) an+=2;
        cout<<an<<"\n";
    }
}