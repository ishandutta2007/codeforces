#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=500000+7;
const int B=60;
int n, ze;
ll a[N], num[B], t;

bool add(ll x)
{
        for (int b=B-1; b>=0; b--)
                if (x&(1LL<<b))
                        x^=num[b];
        if (!x)
                return 1;
        ze++;
        for (int b=B-1; b>=0; b--)
                if ((x&(1LL<<b)) && !num[b])
                {
                        num[b]=x;
                        return 0;
                }
        assert(0);
}

int main()
{
        ios::sync_with_stdio(0); cin.tie(0);

        cin>>n;
        for (int i=1; i<=n; i++)
        {
                ll x, y;
                cin>>x>>y;
                t^=x;
                a[i]=x^y;
        }
        for (int i=1; i<=n; i++)
                add(a[i]);
        bool ok=add(t);
        if (!ok)
                cout<<"1/1\n";
        else
                cout<<(1LL<<ze)-1<<"/"<<(1LL<<ze)<<"\n";

}