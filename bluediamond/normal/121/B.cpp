#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=100000+5;
int val[N],cnt[N],e[N];
int sz=0;
int n,l;

inline void afis()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=cnt[i];j++)
            cout<<val[i];
    cout<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>l;
    string a;
    cin>>a;
    for(int i=0;i<n;i++)
    {
        int cif=a[i]-'0';
        if(sz==0 || cif!=val[sz])
            val[++sz]=cif;
        cnt[sz]++;
        e[sz]=i+1;
    }
    n=sz;
    for(int i=1;i<=n;i++)
    {
       // cout<<val[i]<<" "<<cnt[i]<<"\n";
    }
    for(int i=1;i<n;i++)
    {
        if(l==0)
        {
            afis();
            return 0;
        }
        if(val[i]==4 && val[i+1]==7)
        {
            if(e[i]%2==1)
            {
                if(cnt[i+1]==1)
                {
                    l--;
                    cnt[i]++;
                    cnt[i+1]--;
                    continue;
                }
                l%=2;
                if(l==1)
                {
                    cnt[i]++;
                    cnt[i+1]--;
                }
                afis();
                return 0;
            }
            else
            {
                if(cnt[i]==1)
                {
                    l--;
                    cnt[i]--;
                    cnt[i+1]++;
                    continue;
                }
                l%=2;
                if(l==1)
                {
                    cnt[i]--;
                    cnt[i+1]++;
                }
                afis();
                return 0;
            }
        }
    }
    afis();
    return 0;
}
/**

**/