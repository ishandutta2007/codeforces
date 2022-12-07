//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
int mo(int x)
{
    if(x<0) return -x;
    else return x;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    cout<<"YES\n";
    for(int a=0; a<n; a++)
    {
        int x1, y1, x2, y2;
        cin>>x1>>y1>>x2>>y2;
        if(mo(x1)%2==0)
        {
            if(mo(y1)%2==0) cout<<1<<"\n";
            else cout<<2<<"\n";
        }
        else
        {
            if(mo(y1)%2==0) cout<<3<<"\n";
            else cout<<4<<"\n";
        }
    }
}