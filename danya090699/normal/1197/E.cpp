#include <bits/stdc++.h>
using namespace std;
const int sz=2e5+10, mod=1e9+7;
int l[sz], r[sz];
bool comp(int a, int b){return r[a]>r[b];}
bool comp2(int a, int b){return l[a]<l[b];}
inline int sum(int a, int b)
{
    return (a+b<mod) ? a+b : a+b-mod;
}
inline int dif(int a, int b)
{
    return (a-b>=0) ? a-b : a-b+mod;
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int p[n+1], p2[n+1], mi[n+1], dp[n+1];
    for(int a=0; a<n; a++)
    {
        scanf("%d%d", &r[a], &l[a]), p[a]=a, p2[a]=a;
    }
    l[n]=-1, r[n]=0, p[n]=n, p2[n]=n;
    sort(p, p+n+1, comp);
    sort(p2, p2+n+1, comp2);

    map <int, int> ma, ma2;
    int maxl=2e9, ykl=n, ykr=n;
    for(int a=0; a<=n; a++)
    {
        int i=p[a];
        //cout<<""
        while(l[p2[ykl]]>=r[i])
        {
            int i2=p2[ykl], cumi=l[i2]+mi[i2];
            ma[cumi]=sum(ma[cumi], dp[i2]);
            ma2[cumi]++;
            maxl=min(maxl, r[i2]-1);
            ykl--;
        }
        while(l[p2[ykr]]>maxl)
        {
            int i2=p2[ykr], cumi=l[i2]+mi[i2];
            ma[cumi]=dif(ma[cumi], dp[i2]);
            ma2[cumi]--;
            if(ma2[cumi]==0)
            {
                ma.erase(cumi), ma2.erase(cumi);
            }
            ykr--;
        }
        if(ma.size())
        {
            mi[i]=(*ma.begin()).first-r[i], dp[i]=(*ma.begin()).second;
        }
        else mi[i]=0, dp[i]=1;

        if(a==n) cout<<dp[i];
    }
}