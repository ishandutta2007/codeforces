#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=16+7;

int n;
int v[N];
bool is[N][N];
bool seen[N][N];

void send(int l,int r)
{
        if(seen[l][r]) return;
        seen[l][r]=1;
        int m=(l+r)>>1;
        send(l,m);
        send(m+1,r);
}

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        cin>>n;
        for(int i=1;i<=n;i++)
        {
                cin>>v[i];
        }
        for(int i=1;i<=n;i++)
        {
                for(int j=i;j<=n;j++)
                {
                        bool ok=1;
                        for(int k=i+1;k<=j;k++)
                        {
                                if(v[k-1]>v[k])
                                {
                                        ok=0;
                                }
                        }
                        is[i][j]=ok;
                }
        }
        send(1,n);
        int l=0;
        for(int i=1;i<=n;i++)
        {
                for(int j=i;j<=n;j++)
                {
                        if(seen[i][j] && is[i][j])
                        {
                                l=max(l,j-i+1);
                        }
                }
        }
        cout<<l<<"\n";
        return 0;
}
/**

**/