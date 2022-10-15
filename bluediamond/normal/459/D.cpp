#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=(int)1e6+7;

int n;
int v[N];

map<int,int>f;

int a[N];
int b[N];
/// i < j and a[i] > b[j]

int t[N];

void add(int p,int x)
{
        for(int i=p;i<=n;i+=i&(-i))
        {
                t[i]+=x;
        }
}

int gt(int p)
{
        int r=0;
        for(int i=p;i>=1;i-=i&(-i))
        {
                r+=t[i];
        }
        return r;
}

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        cin>>n;
        for(int i=1;i<=n;i++)
        {
                cin>>v[i];
        }
        for(int i=1;i<=n;i++)
        {
                f[v[i]]++;
                a[i]=f[v[i]];
        }
        f.clear();
        for(int i=n;i>=1;i--)
        {
                f[v[i]]++;
                b[i]=f[v[i]];
        }
        ll r=0;
        for(int i=1;i<=n;i++)
        {
                int cnt=i-1-gt(b[i]);
                r+=cnt;
                add(a[i],1);
        }
        cout<<r<<"\n";
        return 0;
}