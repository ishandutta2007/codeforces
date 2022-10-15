#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int f[100],r;

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        int n,k;
        cin>>n>>k;
        while(n--)
        {
                int x;
                cin>>x;
                f[x%k]++;
        }
        for(int i=0;i<k;i++)
        {
                for(int j=0;j<k;j++)
                {
                        if((i+j)%k==0)
                        {
                                int t=0;
                                if(i==j)
                                {
                                        t=f[i]/2;
                                }
                                else
                                {
                                        t=min(f[i],f[j]);
                                }
                                f[i]-=t;
                                f[j]-=t;
                                r+=t;
                        }
                }
        }
        r+=r;
        cout<<r<<"\n";
        return 0;
}
/**

**/