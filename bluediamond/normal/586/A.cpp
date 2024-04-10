/**
 *
 * With Love from New York
 *
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=100+7;

int n,v[N];

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        cin>>n;
        for(int i=1;i<=n;i++)
        {
                cin>>v[i];
        }
        int cost=0;
        int go=-1;
        for(int i=1;i<=n;i++)
        {
                if(go==-1 && v[i]==1)
                {
                        go=i;
                }
                if(v[i]==1 && v[i+1]==0 && v[i+2]==0)
                {
                        cost+=(i-go+1);
                        go=-1;
                }
        }
        cout<<cost<<"\n";

        return 0;
}
/**

**/