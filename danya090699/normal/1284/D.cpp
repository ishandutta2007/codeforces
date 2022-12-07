#include <bits/stdc++.h>
using namespace std;
const int inf=2e9;
bool is_prime(int x)
{
    for(int a=2; a*a<=x; a++)
    {
        if(x%a==0) return true;
    }
    return false;
}
main()
{
    //freopen("input.txt", "r", stdin);
    srand(time(0));
    int mod=1e9+rand();
    while(!is_prime(mod)) mod++;
    int n;
    cin>>n;
    int l[2][n], r[2][n], nu[n];
    for(int a=0; a<n; a++) nu[a]=(rand()*rand())%mod;
    map <int, int> pref[2], suf[2];
    for(int a=0; a<n; a++)
    {
        for(int i=0; i<2; i++)
        {
            scanf("%d%d", &l[i][a], &r[i][a]);
            pref[i][r[i][a]]=(pref[i][r[i][a]]+nu[a])%mod;
            suf[i][l[i][a]]=(suf[i][l[i][a]]+nu[a])%mod;
        }
    }
    for(int i=0; i<2; i++)
    {
        int su=0;

        pref[i][0]=0;
        for(auto it=pref[i].begin(); it!=pref[i].end(); it++)
        {
            su=(su+(*it).second)%mod;
            (*it).second=su;
        }

        suf[i][inf]=0;
        auto it=suf[i].end();
        su=0;
        while(it!=suf[i].begin())
        {
            it--;
            su=(su+(*it).second)%mod;
            (*it).second=su;
        }
    }
    for(int a=0; a<n; a++)
    {
        int su[2];
        for(int i=0; i<2; i++)
        {
            auto it=pref[i].lower_bound(l[i][a]);
            it--;
            su[i]=(*it).second;
            it=suf[i].upper_bound(r[i][a]);
            su[i]=(su[i]+(*it).second)%mod;
        }
        if(su[0]!=su[1])
        {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
}