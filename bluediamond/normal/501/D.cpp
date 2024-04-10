#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=200000+7;

int n;

int t[N];

void add(int p,int x)
{
        for(int i=p;i<=n;i+=i&(-i))
        {
                t[i]+=x;
        }
}

int get(int p)
{
        int r=0;
        for(int i=p;i>=1;i-=i&(-i))
        {
                r+=t[i];
        }
        return r;
}

void put(int a[],int p[])
{
        for(int i=1;i<=n;i++)
        {
                t[i]=0;
        }
        for(int i=1;i<=n;i++)
        {
                add(i,1);
        }
        for(int i=1;i<=n;i++)
        {
                int cate=get(a[i]-1);
                p[n-i]+=cate;
                add(a[i],-1);
        }
}

int a[N],b[N];
int p[N];

void print()
{
        for(int i=1;i<=n;i++)
        {
                t[i]=0;
        }
        for(int i=1;i<=n;i++)
        {
                add(i,1);
        }
        for(int i=1;i<=n;i++)
        {
                int x=p[n-i]+1;
              ///  cout<<x<<" : ";
              ///  continue;
                /// al x+1-lea numar nefolosit
                int lo=1;
                int hi=n;
                int res=0;
                while(lo<=hi)
                {
                        int mid=(lo+hi)>>1;
                        if(get(mid)<x)
                        {
                                res=mid;
                                lo=mid+1;
                        }
                        else
                        {
                                hi=mid-1;
                        }
                }
                res++;
                add(res,-1);
                cout<<res-1<<" ";
        }
        cout<<"\n";
}

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        cin>>n;
        for(int i=1;i<=n;i++)
        {
                cin>>a[i];
                a[i]++;
        }
        for(int i=1;i<=n;i++)
        {
                cin>>b[i];
                b[i]++;
        }
        put(a,p);
        put(b,p);
        for(int i=0;i<n;i++)
        {
                /// fact[i] * p[i]
                while(p[i]>=i+1)
                {
                        p[i]-=(i+1);
                        p[i+1]++;
                }
        }
        print();
        return 0;
        for(int i=0;i<n;i++)
        {
                cout<<i<<"! * "<<p[i]<<"\n";
        }
        return 0;
}
/**

**/