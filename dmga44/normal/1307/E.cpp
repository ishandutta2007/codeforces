#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<int,pii> pip;
typedef pair<pii,pii> ppp;
#define mod (ll)(1e9+7)
#define MAXN 5005

vector<int> fs[MAXN];
int f[MAXN],h[MAXN],n,m,c[MAXN],ac[MAXN];

pii solve(vector<int> f1,vector<int> f2,int ko)
{
//    for(int i=1;i<=n;i++)
//        cout << f1[i] << ' ' << f2[i] << '\n';
    ll r1=0,r2=1;
    for(int i=1;i<=n;i++)
    {
        ll ma=max(f1[i],f2[i]);
        ll mi=min(f1[i],f2[i]);

        ll c1=lower_bound(fs[i].begin(),fs[i].end(),ma+1)-lower_bound(fs[i].begin(),fs[i].end(),mi+1);
        ll c2=lower_bound(fs[i].begin(),fs[i].end(),mi+1)-fs[i].begin();
        if(f[ko]==i)
        {
            if(h[ko]<=mi)
                c2--;
            else if(h[ko]<=ma)
                c1--;
        }
        int x=min(min(c1,1ll)+min(c2,2ll),2ll);
        r1+=x;

        if(x==2)
        {
            ll sum=((c1*c2)+c2*(c2-1))%mod;
            r2=(r2*sum)%mod;
        }
        if(x==1)
        {
            ll sum=(c1+c2*2)%mod;
            r2=(r2*sum)%mod;
        }
    }
//    cout << r1 << ' ' << r2 << '\n';
//    db("")

    return pii(r1+(ko!=m),r2);
}

pii s(pii a,pii b)
{
    return pii((a.first+b.first)%mod,(a.second+b.second)%mod);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i=0;i<n;i++)
    {
        cin >> c[i];
        ac[c[i]]++;
    }

    for(int i=0;i<m;i++)
    {
        cin >> f[i] >> h[i];
        fs[f[i]].push_back(h[i]);
    }

    for(int i=1;i<=n;i++)
        sort(fs[i].begin(),fs[i].end());

    vector<int> mac1(n+1),mac2(n+1);
    for(int i=1;i<=n;i++)
        mac2[i]=ac[i];
    pii ini=solve(mac1,mac2,m);

    ll r1=ini.first,r2=ini.second;
    for(int i=0;i<m;i++)
    {
        int act=0,pos=-1;
        for(int j=0;j<n;j++)
            if(c[j]==f[i])
            {
                act++;
                if(act==h[i])
                {
                    pos=j;
                    break;
                }
            }
        if(pos==-1)
            continue;

        vector<int> m11(n+1),m12(n+1);
        for(int j=0;j<n;j++)
        {
            if(j<=pos)
            {
                if(c[j]!=f[i])
                    m11[c[j]]++;
            }
            else
                m12[c[j]]++;
        }

        pii m1=solve(m11,m12,i);

//        act=0,pos=-1;
//        for(int j=n-1;j>=0;j--)
//            if(c[j]==f[i])
//            {
//                act++;
//                if(act==h[i])
//                {
//                    pos=j;
//                    break;
//                }
//            }
//        if(pos==-1)
//            continue;
//
//        vector<int> m21(n+1),m22(n+1);
//        for(int j=0;j<n;j++)
//        {
//            if(j>=pos)
//            {
//                if(c[j]!=f[i])
//                    m22[c[j]]++;
//            }
//            else
//                m21[c[j]]++;
//        }
//
//        pip m2=solve(m22,m21,i);

        if(m1.first>r1)
        {
            r1=m1.first;
            r2=m1.second;
        }
        else if(m1.first==r1)
            r2=(r2+m1.second)%mod;

//        if(m2.first>r1)
//        {
//            r1=m2.first;
//            ss=m2.second;
//        }
//        else if(m2.first==r1)
//            r2=(r2+m2.second)%mod;
    }
    cout << r1 << ' ' << r2  << '\n';

    return 0;
}