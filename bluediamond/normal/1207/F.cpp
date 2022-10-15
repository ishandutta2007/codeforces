#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=500000+7;
const int M=700+7;
int n,m;
ll a[N];
ll sol[M][M];


int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        n=500000;
        int op;
        cin>>op;
        while(op--)
        {
                int t;
                ll x,y;
                cin>>t>>x>>y;
                if(t==1)
                {
                        a[x]+=y;
                        for(int mod=1;mod<=700;mod++)
                        {
                                int dau=x%mod;
                                sol[mod][dau]+=y;
                        }
                }
                else
                {
                        if(x<=700)
                                cout<<sol[x][y]<<"\n";
                        else
                        {
                                ll ans=0;
                                for(int j=y;j<=n;j+=x)
                                        ans+=a[j];
                                cout<<ans<<"\n";
                        }
                }
        }

        return 0;
}