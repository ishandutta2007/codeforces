#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=(int)2e5+7;

int pref_min[N],pref_max[N];
int suf_min[N],suf_max[N];

pair <ll,ll> calc(int sgn[],int n)
{
        for(int i=1;i<=n;i++)
                sgn[i]+=sgn[i-1];
        pref_min[0]=pref_max[0]=sgn[0];
        for(int i=1;i<=n;i++)
        {
                pref_min[i]=min(pref_min[i-1],sgn[i]);
                pref_max[i]=max(pref_max[i-1],sgn[i]);
        }
        suf_min[n]=suf_max[n]=sgn[n];
        for(int i=n-1;i>=0;i--)
        {
                suf_min[i]=min(suf_min[i+1],sgn[i]);
                suf_max[i]=max(suf_max[i+1],sgn[i]);
        }
        int cur=pref_max[n]-pref_min[n];
        int best=cur;
        for(int i=0;i<=n;i++)
        {
                int mi,mx;
                mi=min(pref_min[i],suf_min[i]+1);
                mx=max(pref_max[i],suf_max[i]+1);
                best=min(best,mx-mi);
                mi=min(pref_min[i],suf_min[i]-1);
                mx=max(pref_max[i],suf_max[i]-1);
                best=min(best,mx-mi);
        }
        cur++;
        best++;
        return {cur,best};
}

int a[N],n;

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

        int t;
        cin>>t;
        while(t--)
        {
                string s;
                cin>>s;
                n=0;
                for(auto &x : s)
                {
                        if(x=='D')
                                a[++n]=+1;
                        if(x=='A')
                                a[++n]=-1;
                }
                pair <ll,ll> x=calc(a,n);
                n=0;
                for(auto &x : s)
                {
                        if(x=='W')
                                a[++n]=+1;
                        if(x=='S')
                                a[++n]=-1;
                }
                pair <ll,ll> y=calc(a,n);
                ll ans=min(x.first*y.first,x.first*y.second);
                ans=min(ans,x.second*y.first);
                cout<<ans<<"\n";
        }

        return 0;
}