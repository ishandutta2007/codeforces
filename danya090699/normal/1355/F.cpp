#include <bits/stdc++.h>
#define int long long
using namespace std;
const int inf=1e18, mx=1e9;
main()
{
    vector <int> pri, qu;
    for(int a=2; a*a*a*4<=mx; a++)
    {
        bool ok=1;
        for(int b=2; b*b<=a; b++) if(a%b==0) ok=0;
        if(ok) pri.push_back(a);
    }
    int yk=0;
    while(yk<pri.size())
    {
        int x=1;
        while(yk<pri.size() and inf/pri[yk]>=x)
        {
            x*=pri[yk++];
        }
        qu.push_back(x);
    }
    int T;
    cin>>T;
    while(T--)
    {
        vector <int> de;
        for(int a=0; a<qu.size(); a++)
        {
            cout<<"? "<<qu[a]<<"\n";
            int x;
            cin>>x;
            for(int b=0; b<pri.size(); b++)
            {
                if(x%pri[b]==0) de.push_back(pri[b]);
            }
        }
        int an=1;
        for(int a=0; a<de.size(); a+=2)
        {
            int x=1;
            for(int b=a; b<min(0ll+long(de.size()), a+2); b++)
            {
                int t=1;
                while(t*de[b]<=mx) t*=de[b];
                x*=t;
            }
            cout<<"? "<<x<<"\n";
            cin>>x;
            for(int b=a; b<min(0ll+long(de.size()), a+2); b++)
            {
                int q=0;
                while(x%de[b]==0) x/=de[b], q++;
                an*=(q+1);
            }
        }
        if(an==1) cout<<"! 5\n";
        else if(an==2) cout<<"! 9\n";
        else cout<<"! "<<an*2<<"\n";
    }
}