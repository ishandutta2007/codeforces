#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int nax=(int)1e4+7;
int f[nax];

int main()
{

        bool ishome=0;

        if(ishome)
        {
                freopen("__input__","r",stdin);
        }
        else
        {
                ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        }

        int q;
        cin>>q;

        while(q--)
        {
                int n;
                cin>>n;
                for(int i=0;i<nax;i++)
                        f[i]=0;
                for(int i=1;i<=4*n;i++)
                {
                        int x;
                        cin>>x;
                        f[x]++;
                }
                bool ok=1;
                for(int i=1;i<nax;i++)
                        if(f[i]%2==1)
                                ok=0;
                if(!ok)
                {
                        cout<<"NO\n";
                        continue;
                }
                for(int i=1;i<nax;i++)
                        f[i]/=2;
                vector <int> ids;
                for(int i=1;i<nax;i++)
                        for(int j=1;j<=f[i];j++)
                                ids.push_back(i);
                set <int> all;
                for(int i=0;i<(int)ids.size()-i-1;i++)
                        all.insert(ids[i]*ids[(int)ids.size()-i-1]);
                if((int)all.size()==1)
                        cout<<"YES\n";
                else
                        cout<<"NO\n";
                ///cout<<"?\n";
        }

        return 0;
}