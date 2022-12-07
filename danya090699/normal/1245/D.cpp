#include <bits/stdc++.h>
#define int long long
using namespace std;
const int sz=2e3+10, inf=1e18;
int sm[sz][sz];
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int ar[n+1][2], k[n+1];
    for(int a=1; a<=n; a++)
    {
        cin>>ar[a][0]>>ar[a][1];
    }
    for(int a=1; a<=n; a++)
    {
        cin>>sm[0][a];
        sm[a][0]=sm[0][a];
    }
    for(int a=1; a<=n; a++) cin>>k[a];
    for(int a=1; a<=n; a++)
    {
        for(int b=1; b<=n; b++)
        {
            sm[a][b]=(k[a]+k[b])*(abs(ar[a][0]-ar[b][0])+abs(ar[a][1]-ar[b][1]));
        }
    }
    //cout<<1;
    int d[n+1], pr[n+1], us[n+1], an=0;
    for(int a=0; a<=n; a++) d[a]=inf, us[a]=0;
    d[0]=0;
    for(int a=0; a<=n; a++)
    {
        int be=-1;
        for(int b=0; b<=n; b++)
        {
            if(us[b]==0 and (be==-1 or d[be]>d[b])) be=b;
        }
        //cout<<be<<" "<<d[be]<<"\n";
        an+=d[be];
        us[be]=1;
        for(int b=0; b<=n; b++)
        {
            int cu=sm[be][b];
            if(us[b]==0 and d[b]>cu) d[b]=cu, pr[b]=be;
        }
    }
    vector <int> sp;
    vector <pair <int, int> > sp2;
    for(int a=1; a<=n; a++)
    {
        if(pr[a]) sp2.push_back({a, pr[a]});
        else sp.push_back(a);
    }
    cout<<an<<"\n"<<sp.size()<<"\n";
    for(int a=0; a<sp.size(); a++) cout<<sp[a]<<" ";
    cout<<"\n"<<sp2.size()<<"\n";
    for(int a=0; a<sp2.size(); a++) cout<<sp2[a].first<<" "<<sp2[a].second<<"\n";
    //cout<<sm[2][3];
}