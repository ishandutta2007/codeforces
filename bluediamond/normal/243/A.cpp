#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=100000+5;
const int LIM=2000000+5;
const int LG=19+1;

int n;
int v[N];
int f[N][LG];
bool seen[LIM];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
    }
    for(int bt=0;bt<LG;bt++)
    {
        f[n+1][bt]=-1;
    }
    for(int i=n;i>=1;i--)
    {
        for(int bt=0;bt<LG;bt++)
        {
            f[i][bt]=f[i+1][bt];
            if(v[i]&(1<<bt))
            {
                f[i][bt]=i;
            }
        }
    }
    for(int st=1;st<=n;st++)
    {
        int now=v[st];
        seen[now]=1;
        int poz=st;
        while(1)
        {
            int mi=(1<<30);
            for(int bt=0;bt<LG;bt++)
            {
                if((now&(1<<bt))==0 && f[poz][bt]!=-1)
                {
                    mi=min(mi,f[poz][bt]);
                }
            }
            if(mi==(1<<30))
            {
                break;
            }
            for(int bt=0;bt<LG;bt++)
            {
                if((now&(1<<bt))==0 && f[poz][bt]==mi)
                {
                    now+=(1<<bt);
                }
            }
            poz=mi;
            seen[now]=1;
        }
    }
    int ans=0;
    for(int i=0;i<LIM;i++)
    {
        if(seen[i])
        {
            ans++;
        }
    }
    cout<<ans<<"\n";
    return 0;
}