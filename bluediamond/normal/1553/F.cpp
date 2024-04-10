#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=(int) 2e5+7;
const int A=(int) 3e5+7;
int n, a[N];
ll aib[A];
int aib2[A];
ll sol[N];

void add1(int i)
{
        int init=i;
        while (i<A)
        {
                aib[i]+=init;
                i+=i&(-i);
        }
}

ll get1(int i)
{
        ll sol=0;
        while (i)
        {
                sol+=aib[i];
                i-=i&(-i);
        }
        return sol;
}

ll get1(int l, int r)
{
        return get1(r)-get1(l-1);
}

void add2(int i)
{
        while (i<A)
        {
                aib2[i]++;
                i+=i&(-i);
        }
}

int get2(int i)
{
        int sol=0;
        while (i)
        {
                sol+=aib2[i];
                i-=i&(-i);
        }
        return sol;
}

int get2(int l, int r)
{
        return get2(r)-get2(l-1);
}

signed main()
{
        ios::sync_with_stdio(0); cin.tie(0);

       /// freopen ("input", "r", stdin);

        cin>>n;
        for (int i=1; i<=n; i++)
                cin>>a[i];
        for (int i=1; i<=n; i++)
        {
                add1(a[i]);
                ll ans=0, ant=0;
                int l=1;
                while (l<=a[i])
                {
                        int r=min(a[i], a[i]/(a[i]/l));
                        ll cur=get1(r);
                        ans+=(cur-ant)*(a[i]/l);
                        ant=cur;
                        l=r+1;
                }
                sol[i]+=(ll)i*a[i]-ans;
        }
        /**
        if (n>3000)
                return 0;**/
        ll pref=0;
        for (int i=1; i<=n; i++)
        {
                add2(a[i]);
                pref+=a[i];
                ll ans=0;
                for (int c=0; a[i]*c<A; c++)
                {
                        int l=a[i]*c, r=min(A-1, l+a[i]-1);
                        if (!l)l=1;
                        ans+=(ll)c*get2(l, r);
                }
                sol[i]+=pref-ans*a[i];
        }
        for (int i=1; i<=n; i++)
        {
                sol[i]+=sol[i-1];
                cout<<sol[i]<<" ";
        }
        cout<<"\n";
        return 0;
}