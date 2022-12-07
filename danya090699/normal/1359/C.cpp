#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int T;
    cin>>T;
    while(T--)
    {
        int h, c, t;
        cin>>h>>c>>t;
        if(2*t<=h+c) cout<<"2\n";
        else
        {
            int q=(h-t)/(2*t-h-c);
            int ch1=(h+c)*q+h-t*(q*2+1), zn1=q*2+1;
            int ch2=t*(q*2+3)-(h+c)*(q+1)-h, zn2=q*2+3;
            if(ch1*zn2<=ch2*zn1) cout<<q*2+1<<"\n";
            else cout<<q*2+3<<"\n";
        }
    }
}