#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int a, b, c, d;
    const int sz=1e6;
    cin>>a>>b>>c>>d;
        bool us[sz], fo=0;
        for(int i=0; i<sz; i++) us[i]=0;
        for(int i=b; i<sz; i+=a) us[i]=1;
        for(int i=d; i<sz; i+=c)
        {
            if(us[i])
            {
                cout<<i;
                fo=1;
                break;
            }
        }
    if(fo==0) cout<<-1;
}