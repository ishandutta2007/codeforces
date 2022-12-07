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
        int ar[3];
        for(int a=0; a<3; a++) cin>>ar[a];
        sort(ar, ar+3);
        int an=ar[1]-ar[0];
        ar[1]-=an, ar[2]-=an;
        if(ar[2]>ar[0]*2) an+=ar[0]*2;
        else an+=(ar[2]+ar[0]*2)/2;
        cout<<an<<"\n";
    }
}