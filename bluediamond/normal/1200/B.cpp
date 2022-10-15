#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=100+7;
int v[N];

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        /// freopen("__input__","r",stdin);

        int t;
        cin>>t;

        while(t--)
        {
                int n,m,k;
                cin>>n>>m>>k;
                for(int i=1;i<=n;i++)
                        cin>>v[i];
                bool ok=1;
                for(int i=1;i<n;i++)
                {
                        if(v[i]>=v[i+1]-k)
                        {
                                m+=min(v[i],(v[i]-(v[i+1]-k)));
                        }
                        else
                        {
                                int dif=v[i+1]-k-v[i];
                                if(dif<=m)
                                {
                                        m-=dif;
                                }
                                else
                                        ok=0;
                        }
                }
                if(ok)
                        cout<<"YES\n";
                else
                        cout<<"NO\n";
        }

        return 0;
}
/**

**/