#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=5000+5;

int n,k;
int v[N];
map<int,int>f,seen;
int a[N],ma=0;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
        f[v[i]]++;
        a[i]=f[v[i]];
        ma=max(ma,a[i]);
        seen[a[i]]++;
    }
    if(ma>k)
    {
        cout<<"NO\n";
        return 0;
    }
    for(int i=1;i<=k;i++)
    {
        if(seen[i]==0)
        {
            bool g=0;
            for(int j=1;j<=k;j++)
            {
                if(seen[j]>=2)
                {
                    g=1;
                    seen[j]--;
                    for(int it=1;it<=n;it++)
                    {
                        if(a[it]==j)
                        {
                            a[it]=i;
                            break;
                        }
                    }
                    seen[i]++;
                    break;
                }
            }
            if(g==0)
            {
                cout<<"NO\n";
                return 0;
            }
        }
    }
    cout<<"YES\n";
    for(int i=1;i<=n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<"\n";
    return 0;
}
/**

4 4
1 2 2 3


**/