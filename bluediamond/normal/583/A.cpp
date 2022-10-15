#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=50+7;

int n;
bool limak1[N],limak2[N];

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        cin>>n;
        for(int i=1;i<=n*n;i++)
        {
                int r,c;
                cin>>r>>c;
                if(limak1[r]==0 && limak2[c]==0)
                {
                        cout<<i<<" ";
                        limak1[r]=1, limak2[c]=1;
                }
        }
        cout<<"\n";
        return 0;
}
/**

**/