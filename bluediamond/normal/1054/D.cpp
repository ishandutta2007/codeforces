#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=200000+7;
int n, k, a[N];

signed main()
{
        ios::sync_with_stdio(0); cin.tie(0);

///        freopen ("input", "r", stdin);

        cin>>n>>k;
        k=(1<<k)-1;
        for (int i=1; i<=n; i++)
                cin>>a[i];
        for (int i=1; i<=n; i++)
                a[i]^=a[i-1];
        map<int, int> f;
        f[0]++;
        for (int i=1; i<=n; i++)
                f[min(a[i], k^a[i])]++;

        ll sol=0;
        for (auto &it:f)
        {
               /// cout<<"= "<<it.second<<"\n";
                ll x=it.second/2, y=it.second-x;
                sol+=x*(x-1)/2;
                sol+=y*(y-1)/2;
        }
        cout<<(ll)n*(n+1)/2-sol<<"\n";

        return 0;
}
/**

alea care au cea mai mica valoare au 0 la stanga si 0 la dreapta

**/