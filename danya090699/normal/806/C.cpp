#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int last[40], st[40];
    for(int a=0; a<40; a++)
    {
        last[a]=0, st[a]=0;
    }
    for(int a=0; a<n; a++)
    {
        int x;
        cin>>x;
        for(int b=39; b>=0; b--)
        {
            if(x>=(1ll<<b))
            {
                if(x==(1ll<<b)) st[b]++;
                else last[b]++;
                break;
            }
        }
    }
    vector <int> an;
    for(int a=1; a<=st[0]; a++)
    {
        int cula[40], en[40], pr=a;
        for(int b=0; b<40; b++)
        {
            cula[b]=last[b], en[b]=0;
        }
        cula[0]+=st[0]-a;
        for(int b=1; b<40; b++)
        {
            if(st[b]>=pr) cula[b]+=st[b]-pr;
            else
            {
                en[b-1]=pr-st[b];
                pr=st[b];
            }
        }
        en[39]=pr;
        for(int b=0; b<39; b++) if(cula[b]>en[b]) cula[b+1]+=cula[b]-en[b];
        if(cula[39]<=en[39]) an.push_back(a);
    }
    if(an.size()==0) cout<<-1;
    else
    {
        for(int a=0; a<an.size(); a++) cout<<an[a]<<" ";
    }
}