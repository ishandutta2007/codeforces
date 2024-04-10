#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
#define MAXN 1000005

ll a[MAXN],s1[MAXN],s2[MAXN],res[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];

    stack<pii> s;
    for(int i=0;i<n;i++)
    {
        ll cant=0,dif=0;
        while(!s.empty() && s.top().first>=a[i])
        {
            cant+=s.top().second;
            dif+=(s.top().first-a[i])*s.top().second;
            s.pop();
        }

        if(i)
            s1[i]=s1[i-1]-dif+a[i];
        else
            s1[i]=a[i];

        s.push(pii(a[i],cant+1));
    }
    while(!s.empty())
        s.pop();

    for(int i=n-1;i>=0;i--)
    {
        ll cant=0,dif=0;
        while(!s.empty() && s.top().first>=a[i])
        {
            cant+=s.top().second;
            dif+=(s.top().first-a[i])*s.top().second;
            s.pop();
        }

        s2[i]=s2[i+1]-dif+a[i];

        s.push(pii(a[i],cant+1));
    }

    ll r=s2[0];
    ll p=-1;
    for(int i=0;i<n;i++)
        if(r<s1[i]+s2[i+1])
        {
            r=s1[i]+s2[i+1];
            p=i;
        }

    if(p!=-1)
        res[p]=a[p];
    for(int i=p-1;i>=0;i--)
        res[i]=min(res[i+1],a[i]);

    res[p+1]=a[p+1];
    for(int i=p+2;i<n;i++)
        res[i]=min(res[i-1],a[i]);

    for(int i=0;i<n;i++)
        cout << res[i] << ' ';
    cout << '\n';

    return 0;
}