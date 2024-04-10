#include <bits/stdc++.h>

using namespace std;

const int N=(int)1e5+7;
const int LG=17;

int n,cntq;
int ret[N][LG];
int _log2[N];

int get_gcd(int a,int b)
{
        if(b==0)
        {
                return a;
        }
        else
        {
                return get_gcd(b,a%b);
        }
}

int get(int l,int r)
{
        int k=(r-l+1);
        k=_log2[k];
        return get_gcd(ret[l][k],ret[r-(1<<k)+1][k]);
}

int a[N];
int b[N];
vector<int>ids[N];

/// aib

int t[N];

void add(int p,int x)
{
        for(int i=p;i<=n;i+=i&(-i))
        {
                t[i]+=x;
        }
}

int prefix(int p)
{
        int r=0;
        for(int i=p;i>=1;i-=i&(-i))
        {
                r+=t[i];
        }
        return r;
}

vector<int>in[N];
vector<int>out[N];

int p1[N],p2[N],p3[N];

int sol[N];

int ask(int st,int dr)
{
        return prefix(dr)-prefix(st-1);
}

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        ///freopen("data.in","r",stdin); freopen("data.out","w",stdout);
        cin>>n;
        for(int i=1;i<=n;i++)
        {
                cin>>ret[i][0];
        }
        for(int k=1;(1<<k)<=n;k++)
        {
                for(int i=1;i+(1<<k)-1<=n;i++)
                {
                        ret[i][k]=get_gcd(ret[i][k-1],ret[i+(1<<(k-1))][k-1]);
                }
        }
        for(int i=2;i<=n;i++)
        {
                _log2[i]=1+_log2[i>>1];
        }
        for(int i=1;i<=n;i++)
        {
                int x=ret[i][0];
                int lo,hi;
                int L,R;
                lo=i;
                hi=n;
                while(lo<=hi)
                {
                        int mid=(lo+hi)>>1;
                        if(get(i,mid)%x==0)
                        {
                                R=mid;
                                lo=mid+1;
                        }
                        else
                        {
                                hi=mid-1;
                        }
                }
                lo=1;
                hi=i;
                while(lo<=hi)
                {
                        int mid=(lo+hi)>>1;
                        if(get(mid,i)%x==0)
                        {
                                L=mid;
                                hi=mid-1;
                        }
                        else
                        {
                                lo=mid+1;
                        }
                }
                p1[i]=L;
                p2[i]=i;
                p3[i]=R;
                in[p1[i]].push_back(i);
                out[p2[i]+1].push_back(i);
                ///cout<<"Points : "<<p1[i]<<" "<<p2[i]<<" "<<p3[i]<<"\n";
        }
        cin>>cntq;
        for(int i=1;i<=cntq;i++)
        {
                cin>>a[i]>>b[i];
                ids[a[i]].push_back(i);
        }
        for(int a=1;a<=n;a++)
        {
                for(auto &i:in[a])
                {
                        add(p3[i],1);
                }
                for(auto &i:out[a])
                {
                        add(p3[i],-1);
                }
                for(auto &i:ids[a])
                {
                        /// b[i]
                        sol[i]+=ask(b[i],n);
                }
        }
        for(int i=0;i<N;i++)
        {
                t[i]=0;
        }
        for(int a=1;a<=n;a++)
        {
                for(auto &i:in[a])
                {
                        add(p2[i],1);
                }
                for(auto &i:out[a])
                {
                        add(p2[i],-1);
                }
                for(auto &i:ids[a])
                {
                        sol[i]-=ask(b[i]+1,n);
                }
        }
        for(int i=1;i<=cntq;i++)
        {
                int res=b[i]-a[i]+1-sol[i];
                cout<<res<<"\n";
        }
        return 0;
}