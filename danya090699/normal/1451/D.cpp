#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int d, k;
        cin>>d>>k;
        int x=0;
        while((x+k)*(x+k)*2<=d*d) x+=k;
        if(x*x+(x+k)*(x+k)<=d*d) cout<<"Ashish\n";
        else cout<<"Utkarsh\n";
    }
}