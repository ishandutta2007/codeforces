#include <bits/stdc++.h>
#define int long long
using namespace std;
const int inf=4e18;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, su=0, an=inf;
    cin>>n;
    int ar[n];
    for(int a=0; a<n; a++) scanf("%lld", &ar[a]), su+=ar[a];
    vector <int> de;
    for(int a=2; a*a<=su; a++)
    {
        if(su%a==0)
        {
            de.push_back(a);
            while(su%a==0) su/=a;
        }
    }
    if(su>1) de.push_back(su);
    if(de.size()==0)
    {
        cout<<-1;
        return 0;
    }
    for(int a=0; a<de.size(); a++)
    {
        int ar2[n], yk=0, d=de[a], tot=0;
        for(int b=0; b<n; b++) ar2[b]=ar[b]%d;
        while(yk<n)
        {
            int su=0;
            vector <int> sp;
            while(yk<n)
            {
                if(su+ar2[yk]<=d)
                {
                    sp.push_back(ar2[yk]);
                    su+=ar2[yk++];
                }
                else
                {
                    ar2[yk]-=d-su;
                    sp.push_back(d-su);
                    break;
                }
            }
            int cu=0, be=inf, pref=0, suf=0;
            for(int b=1; b<sp.size(); b++) cu+=sp[b]*b, suf+=sp[b];
            for(int b=0; b<sp.size(); b++)
            {
                be=min(be, cu);
                pref+=sp[b], cu+=pref;
                if(b+1<sp.size()) cu-=suf, suf-=sp[b+1];
            }
            tot+=be;
        }
        an=min(an, tot);
    }
    cout<<an;
}