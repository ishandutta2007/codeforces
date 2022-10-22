#include <bits/stdc++.h>
#define endl '\n'
#define db(x) cout << x << endl;
using namespace std;
typedef long long ll;
#define MAXN 200005

ll a[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

//    freopen(".in","r",stdin);

    ll n,k,sum=0;
    cin >> n >> k;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        sum+=a[i];
    }

    ll m=sum*k;

    int res=0;
    stack<ll> ps;
    ps.push(-1);
    vector<ll> v;
    for(int i=0;i<n;i++)
    {
        ll mul=a[i];
        ll sum=a[i];
        if(k==1)
            res++;
        if(a[i]!=1)
            v.push_back(i);
        ll last=i;
        while(!ps.empty())
        {
            ll p=ps.top();
            ps.pop();
            v.push_back(p);
            if((mul/k)*k==mul)
                if(mul/k>sum && mul/k<=sum+(last-p-1))
                    res++;
            if(p==-1)
                continue;
            if(m/mul>=a[p])
            {
                mul*=a[p];
                sum+=a[p]+last-p-1;
                if(sum*k==mul)
                    res++;
                last=p;
            }
            else
                break;
        }
        for(int j=v.size()-1;j>=0;j--)
            ps.push(v[j]);
        v.clear();
    }
    db(res)

    return 0;
}