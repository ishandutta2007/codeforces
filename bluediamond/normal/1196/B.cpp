#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define pb push_back

const int N=(int)2e5+7;
int n,k;
int ip[N],cnt;


int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

        int q;
        cin>>q;

        while(q--)
        {
                int n,k;
                cin>>n>>k;
                cnt=0;
                for(int i=1;i<=n;i++)
                {
                        int x;
                        cin>>x;
                        x%=2;
                        if(x==1)
                                ip[++cnt]=i;
                }
                if(cnt>=k && (cnt-k)%2==0)
                {
                        cout<<"YES\n";
                        for(int i=1;i<k;i++)
                                cout<<ip[i]<<" ";
                        cout<<n;
                        cout<<"\n";
                }
                else
                        cout<<"NO\n";
        }

        return 0;
}
/**

**/