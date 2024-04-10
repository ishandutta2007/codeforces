#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=(int)2e5+7;

int n;
int p[N];

int gt(int l,int r)
{
        return p[r]-p[l-1];
}

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        cin>>n;
        for(int i=1;i<=n;i++)
        {
                int x;
                cin>>x;
                p[x]++;
        }
        for(int i=1;i<N;i++)
        {
                p[i]+=p[i-1];
        }
        ll res=0LL;
        for(int i=1;i<N;i++)
        {
                if(!gt(i,i)) continue;
                ll cur=0LL;
                for(int st=0;st<N;st+=i)
                {
                        int dr=min(N-1,st+i-1);
                        cur+=gt(st,dr)*(ll)st;
                }
                res=max(res,cur);
        }
        cout<<res<<"\n";
        return 0;
}
/**

**/