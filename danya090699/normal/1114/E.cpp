#include <bits/stdc++.h>
#define int long long
using namespace std;
const int inf=1e9;
main()
{
    srand(time(0));
    int n, q=60;
    cin>>n;
    int l=0, r=inf;
    while(r-l>1)
    {
        int mid=(l+r)>>1;
        cout<<"> "<<mid<<"\n";
        int re;
        cin>>re;
        if(re) l=mid;
        else r=mid;
        q--;
    }
    vector <int> us, sp;
    sp.push_back(r);
    while(us.size()<n and q)
    {
        int p=(1ll*rand()*rand())%n, ok=1;
        for(int a=0; a<us.size(); a++) if(us[a]==p) ok=0;
        if(ok)
        {
            cout<<"? "<<p+1<<"\n";
            int re;
            cin>>re;
            if(re!=r) sp.push_back(re);
            us.push_back(p);
            q--;
        }
    }
    sort(sp.begin(), sp.end());
    int d=0;
    for(int a=0; a+1<sp.size(); a++) d=__gcd(d, sp[a+1]-sp[a]);
    vector <int> de;
    for(int a=1; a*a<=d; a++)
    {
        if(d%a==0)
        {
            de.push_back(a);
            de.push_back(d/a);
        }
    }
    for(int a=0; a<de.size(); a++)
    {
        int cu=de[a], sm=r-cu*(n-1);
        if(sm>=0 and sm<=sp[0])
        {
            cout<<"! "<<sm<<" "<<cu<<"\n";
            break;
        }
    }
}