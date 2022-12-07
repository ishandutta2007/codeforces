#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353, sz=100;
int fact[sz], rev[sz];
int po(int x, int y)
{
    int re=1;
    while(y)
    {
        if(y&1) re=re*x%mod;
        y>>=1;
        x=x*x%mod;
    }
    return re;
}
main()
{
    fact[0]=1, rev[0]=1;
    for(int a=1; a<sz; a++)
    {
        fact[a]=fact[a-1]*a%mod;
        rev[a]=po(fact[a], mod-2);
    }
    //freopen("input.txt", "r", stdin);
    int d, q;
    cin>>d>>q;
    vector <int> de;
    for(int a=2; a*a<=d; a++)
    {
        if(d%a==0)
        {
            de.push_back(a);
            while(d%a==0) d/=a;
        }
    }
    if(d>1) de.push_back(d);
    for(int a=0; a<q; a++)
    {
        int x[2], an[2]={1, 1}, su[2]={0, 0};
        vector <int> sp[2];
        scanf("%lld%lld", &x[0], &x[1]);
        for(int b=0; b<de.size(); b++)
        {
            int q[2]={0, 0};
            for(int i=0; i<2; i++)
            {
                int t=x[i];
                while(t%de[b]==0) t/=de[b], q[i]++;
            }
            if(q[0]<q[1]) an[0]=an[0]*rev[q[1]-q[0]]%mod, su[0]+=q[1]-q[0];
            else an[1]=an[1]*rev[q[0]-q[1]]%mod, su[1]+=q[0]-q[1];
        }
        an[0]=an[0]*fact[su[0]]%mod;
        an[1]=an[1]*fact[su[1]]%mod;
        printf("%lld\n", an[0]*an[1]%mod);
    }
}