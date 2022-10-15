#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=(int)2e5+7;

int n,v[N];

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        cin>>n;
        for(int i=1;i<=n;i++)
        {
                cin>>v[i];
                v[i]=abs(v[i]);
        }
        sort(v+1,v+n+1);
        ll rs=0LL;
        for(int i=1;i<=n;i++)
        {
                int c=2*v[i];
                int l=i+1;
                int r=n;
                int cnt=0;
                while(l<=r)
                {
                        int m=(l+r)/2;
                   ///     cout<<v[m]<<" "<<c<<"\n";
                        if(v[m]<=c)
                        {
                                cnt=m-i;
                                l=m+1;
                        }
                        else
                        {
                                r=m-1;
                        }
                }
             //   cout<<"="<<cnt<<"\n";s
                rs+=cnt;
        }
        cout<<rs<<"\n";

        return 0;
}
/**

**/