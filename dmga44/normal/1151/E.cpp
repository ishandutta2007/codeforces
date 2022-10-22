#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> pip;
#define MAXN 100005

int a[MAXN],f[MAXN],c[MAXN];
vector<int> g[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        f[a[i]]++;
        if(i)
        {
            g[max(a[i],a[i-1])].push_back(min(a[i],a[i-1]));
            c[min(a[i],a[i-1])]++;
        }
    }

    ll res=0,acf=0,acc=0,sum=0;
    for(int i=n;i;i--)
    {
        acf+=f[i];
        acc+=c[i];
        res+=(acf-acc);
    }
    sum+=res;

    for(int i=n;i;i--)
    {
        for(auto y : g[i])
            res+=y;
        res-=(f[i]*i);
        sum+=res;
    }
    db(sum)


    return 0;
}