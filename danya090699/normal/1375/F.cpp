#include <bits/stdc++.h>
#define int long long
using namespace std;
const int inf=2e9;
main()
{
    int x[4];
    cin>>x[1]>>x[2]>>x[3];
    cout<<"First\n";
    cout<<inf<<"\n";
    int p;
    cin>>p;
    if(p)
    {
        x[p]+=inf;
        int ar[3]={x[1], x[2], x[3]};
        sort(ar, ar+3);
        cout<<ar[2]*2-ar[1]-ar[0]<<"\n";
        cin>>p;
        if(p)
        {
            x[p]+=ar[2]*2-ar[1]-ar[0];
            ar[0]=x[1], ar[1]=x[2], ar[2]=x[3];
            sort(ar, ar+3);
            cout<<ar[1]-ar[0]<<"\n";
            cin>>p;
        }
    }
}