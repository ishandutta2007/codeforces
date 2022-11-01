#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    ll k;
    cin >> n >> m >> k;
    vector<int> a(n+1,0);
    vector<int> b(m+1,0);
    const int N=2*max(n,m);
    vector<int> one(N+1,0);
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        one[a[i]]=i;
    }
    vector<int> two(N+1,0);
    for(int i=1;i<=m;i++)
    {
        cin >> b[i];
        two[b[i]]=i;
    }
    if(n<m)
    {
        swap(n,m);
        swap(a,b);
        swap(one,two);
    }
    vector<int> d(m,n);
    for(int i=1;i<=m;i++)
    {
        if(one[b[i]]!=0)
        {
            int s=(((two[b[i]]-one[b[i]])%m)+m)%m;
            d[s]--;
        }
    }
    ll l=ll(n)*m;
    ll cycle=0;
    int s=0;
    for(int i=0;i<m;i++)
    {
        cycle+=d[s];
        s=(s+n)%m;
    }
    ll full=((k-1)/cycle);
    ll res=l*full;
    k-=(full*cycle);
    s=0;
    for(int i=0;i<m;i++)
    {
        if(k>d[s])
        {
            k-=d[s];
            res+=n;
        }
        else
        {
            for(int j=1;j<=n;j++)
            {
                res++;
                k-=(a[j]!=b[s+1]);
                s=(s+1)%m;
                if(k==0) break;
            }
            break;
        }
        s=(s+n)%m;
    }
    cout << res << "\n";
    return 0;
}