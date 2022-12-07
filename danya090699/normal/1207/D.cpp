#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int fact[n+1];
    fact[0]=1;
    for(int a=1; a<=n; a++) fact[a]=(1ll*fact[a-1]*a)%mod;
    pair <int, int> ar[n];
    map <int, int> m1, m2;
    map <pair <int, int>, int > m3;
    for(int a=0; a<n; a++)
    {
        scanf("%d%d", &ar[a].first, &ar[a].second);
        m1[ar[a].first]++;
        m2[ar[a].second]++;
        m3[ar[a]]++;
    }
    sort(ar, ar+n);
    int b1=1, b2=1, b3=1;
    for(auto it=m1.begin(); it!=m1.end(); it++) b1=(1ll*b1*fact[(*it).second])%mod;
    for(auto it=m2.begin(); it!=m2.end(); it++) b2=(1ll*b2*fact[(*it).second])%mod;
    for(int a=0; a+1<n; a++) if(ar[a].second>ar[a+1].second) b3=0;
    for(auto it=m3.begin(); it!=m3.end(); it++) b3=(1ll*b3*fact[(*it).second])%mod;
    int an=fact[n];
    an-=b1;
    if(an<0) an+=mod;
    an-=b2;
    if(an<0) an+=mod;
    an=(an+b3)%mod;


    cout<<an;
}