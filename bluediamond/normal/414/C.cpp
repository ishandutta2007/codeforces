#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=(1<<20)+7;
int n;
int a[N];
int aib[N];
int on[N];
ll sum[30][2];

void add(int i,int val)

{
        while (i<=n)
        {
                aib[i]+=val;
                i+=i&(-i);
        }
}

int get(int i)
{
        int sol=0;
        while (i)
        {
                sol+=aib[i];
                i-=i&(-i);
        }
        return sol;
}

int get(int l,int r)
{
        return get(r)-get(l-1);
}

void build(int v,int tl,int tr,int lvl)
{
        if (tl==tr)
        {
                return;
        }
        int tm=(tl+tr)/2;
        build(2*v,tl,tm,lvl-1);
        build(2*v+1,tm+1,tr,lvl-1);
        for (int j=tl;j<=tm;j++)
                add(a[j],+1);
        for (int j=tm+1;j<=tr;j++)
        {
                sum[lvl-1][0]+=get(a[j]+1,n);;
                sum[lvl-1][1]+=get(1,a[j]-1);
        }
        for (int j=tl;j<=tm;j++)
                add(a[j],-1);
}



int main()
{
        ios::sync_with_stdio(0);
        cin.tie(0);

        cin>>n;
        int k=n;
        n=(1<<n);
        map<int,int> tr;
        for (int i=1;i<=n;i++)
        {
                cin>>a[i];
                tr[a[i]]=0;
        }
        int kol=0;
        for (auto &it : tr)
                it.second=++kol;
        for (int i=1;i<=n;i++)
                a[i]=tr[a[i]];
        build(1,1,n,k);
        int q;
        cin>>q;
        while (q--)
        {
                int l;
                cin>>l;
                l--;
                for (int j=l;j>=0;j--)
                        on[j]^=1;
                ll sol=0;
                for (int j=0;j<=k;j++)
                        sol+=sum[j][on[j]];
                cout<<sol<<"\n";
        }
}