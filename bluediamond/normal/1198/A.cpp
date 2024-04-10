#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define pb push_back

const ll N=(ll)4e5+7;
ll n,I;
ll a[N];
map <ll,ll> t;
ll sm[N];

ll get(ll l,ll r)
{
        return sm[r]-sm[l-1];
}

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

        cin>>n>>I;
        I*=8;
        for(ll i=1;i<=n;i++)
                cin>>a[i];
        /// n*k<=I
        /// k<=I/n
        ll lim=I/n;
        /// K<=2^k
        if(lim>=30)
        {
                cout<<"0\n";
                return 0;
        }
        lim=(1<<lim);
        /// K<=lim
        set <ll> s;
        for(ll i=1;i<=n;i++)
                s.insert(a[i]);
        ll cur=1;
        for(auto &x:s)
                t[x]=cur++;
        for(ll i=1;i<=n;i++)
                a[i]=t[a[i]];
        for(ll i=1;i<=n;i++)
                sm[a[i]]++;
        for(ll i=1;i<=n;i++)
                sm[i]+=sm[i-1];
        ll un=0;
        for(ll i=1;i<=n;i++)
        {
                ll l=i,r=min(n,i+lim-1);
                un=max(un,sm[r]-sm[l-1]);
        }
        cout<<n-un<<"\n";

        return 0;
}