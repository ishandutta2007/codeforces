#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=300+5;

int n,m;
int v[N];
int st[N],dr[N];
int f[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
    }
    for(int i=1;i<=m;i++)
    {
        cin>>st[i]>>dr[i];
        f[st[i]]++;
        f[dr[i]+1]--;
    }
    int res=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
                int a=v[i];
                int b=v[j];
                for(int it=1;it<=m;it++)
                {
                    int l=st[it];
                    int r=dr[it];
                    bool fa=0;
                    bool fb=0;
                    if(l<=i && i<=r) fa=1;
                    if(l<=j && j<=r) fb=1;
                    if(fa && fb==0)
                    {
                        a--;
                    }
                }
                res=max(res,abs(a-b));
        }
    }
    cout<<res;
    cout<<"\n";
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
                int a=v[i];
                int b=v[j];
                for(int it=1;it<=m;it++)
                {
                    int l=st[it];
                    int r=dr[it];
                    bool fa=0;
                    bool fb=0;
                    if(l<=i && i<=r) fa=1;
                    if(l<=j && j<=r) fb=1;
                    if(fa && fb==0)
                    {
                        a--;
                    }
                }
                if(abs(a-b)==res)
                {
                    vector<int>krr;
                a=v[i];
                b=v[j];
                for(int it=1;it<=m;it++)
                {
                    int l=st[it];
                    int r=dr[it];
                    bool fa=0;
                    bool fb=0;
                    if(l<=i && i<=r) fa=1;
                    if(l<=j && j<=r) fb=1;
                    if(fa && fb==0)
                    {
                        a--;
                        krr.push_back(it);
                    }
                }
                cout<<krr.size()<<"\n";
                for(auto &it:krr)
                {
                    cout<<it<<" ";
                }
                return 0;
                }
        }
    }
    return 0;
}
/**



**/