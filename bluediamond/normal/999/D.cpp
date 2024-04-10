#include <bits/stdc++.h>

using namespace std;

const long long N=200000;

long long n,m,need[N+5],nev;
long long v[N+5];
long long ap[N+5];
vector<long long>who[N+5];
long long cost=0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
  ///  freopen("tema.in","r",stdin);
  ///  freopen("tema.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++)
    {
        cin>>v[i];
        long long val=v[i]%m;
        ap[val]++;
        who[val].push_back(i);
    }
    nev=n/m;
    for(long long i=0;i<m;i++)
        need[i]=max(0LL,nev-ap[i]);
    long long poz=-1;
    for(long long i=0;i<m;i++)
        if(ap[i]>nev)
        {
            long long am=ap[i]-nev;
            if(poz<i+1)
                poz=i+1;
            while(1)
            {
                if(poz>=n)
                    break;
                if(am>need[poz])
                {
                    for(long long j=1;j<=need[poz];j++)
                    {
                        ///cout<<i<<" : "<<who[i].size()<<"\n";
                        v[who[i][who[i].size()-1]]+=poz-i;
                        who[i].pop_back();
                    }
                    cost+=need[poz]*(poz-i);
                    am-=need[poz];
                    need[poz]=0;
                    poz++;
                }
                else /// am < need[poz]
                {
                    for(long long j=1;j<=am;j++)
                    {
                        v[who[i][who[i].size()-1]]+=poz-i;
                        who[i].pop_back();
                    }
                    cost+=am*(poz-i);
                    need[poz]-=am;
                    am=0;
                    break;
                }
            }
            ap[i]=am+nev;
        }
    poz=0;
    for(long long i=0;i<m;i++)
        if(ap[i]>nev)
        {
            long long am=ap[i]-nev;
            while(1)
            {
                if(poz>=i)
                    break;
                if(am>need[poz])
                {
                    for(long long j=1;j<=need[poz];j++)
                    {
                        ///cout<<m+i-poz<<"\n";
                        v[who[i][who[i].size()-1]]+=m-i+poz;
                        who[i].pop_back();
                    }
                    cost+=need[poz]*(m-i+poz);
                    am-=need[poz];
                    need[poz]=0;
                    poz++;
                }
                else /// am < need[poz]
                {
                    for(long long j=1;j<=am;j++)
                    {
                       /// cout<<m+i-poz<<"\n";
                        v[who[i][who[i].size()-1]]+=m-i+poz;
                        who[i].pop_back();
                    }
                    cost+=am*(m-i+poz);
                    need[poz]-=am;
                    am=0;
                    break;
                }
            }
            ap[i]=am+nev;
        }
    cout<<cost<<"\n";
    for(long long i=1;i<=n;i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<"\n";
    return 0;
}
/**

**/