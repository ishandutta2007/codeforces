#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct info
{
    int t;
    int x;
    int nod;
};

bool cmp(info a,info b)
{
    return a.t<b.t;
}

const int N=1e5+5;
int n,cnt,day;

int nin; info in[N];
int nout; info out[N];

ll dp[N],sum=0;
int cur=0;
int bst[N];

int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
    cin>>n>>cnt>>day;
    for(int i=1;i<=cnt;i++)
    {
        int t,a,b,x;
        cin>>t>>a>>b>>x;
        if(a)
            in[++nin]={t,x,a};
        else
            out[++nout]={t,x,b};
    }
    sort(in+1,in+nin+1,cmp);
    sort(out+1,out+nout+1,cmp);
    for(int i=1;i<=nin;i++)
    {
        int nod=in[i].nod;
        if(bst[nod]==0) bst[nod]=in[i].x,cur++,sum+=bst[nod];
        else sum-=bst[nod],bst[nod]=min(bst[nod],in[i].x),sum+=bst[nod];
        if(cur<n)
            dp[i]=-1;
        else
            dp[i]=sum;
    }
    cur=0;
    sum=0;
    for(int i=1;i<=n;i++) bst[i]=0;
    ll ans=-1;
    for(int i=nout;i>=1;i--)
    {
        int nod=out[i].nod;
        if(bst[nod]==0) bst[nod]=out[i].x,cur++,sum+=bst[nod];
        else sum-=bst[nod],bst[nod]=min(bst[nod],out[i].x),sum+=bst[nod];
        ll x;
        if(cur<n)
            x=-1;
        else
            x=sum;
        if(x==-1) continue;
        int st=out[i].t-day-1;
        int r=0,pas=(1<<16);
        while(pas)
        {
            if(r+pas<=nin && in[r+pas].t<=st) r+=pas; pas/=2;
        }
        if(r==0 || dp[r]==-1) continue;
        ll lol=x+dp[r];
        if(ans==-1) ans=lol; else ans=min(ans,lol);
        
    }
    cout<<ans<<"\n";
}