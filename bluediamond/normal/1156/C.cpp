#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=(int)4e5+7;

int n,d;
int v[N];
int e[N];
bool tk[N];

bool pot(int k)
{
        if(k>n/2) return 0;
        int lastp=-1;
        for(int i=1;i<=k;i++)
        {
                int vl=e[i];
                if(vl>n) return 0;
                if (vl <= lastp)
                    vl = lastp + 1;
                if(vl>n) return 0;
                lastp=vl;
        }
        return 1;
}

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
       /// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
                cin>>v[i];
        }
        sort(v+1,v+n+1);
        v[n+1]=2e9+7;
        int j=1;
        for(int i=1;i<=n;i++)
        {
                while(v[j]-v[i]<d) j++;
                e[i]=j;
        }
        int l=0,r=n;
        int res=0,mid;
        while(l<=r)
        {
                mid=(l+r)/2;
                if(pot(mid))
                {
                        res=mid;
                        l=mid+1;
                }
                else
                {
                        r=mid-1;
                }
        }
        cout<<res<<"\n";
        return 0;
}
/**

**/