#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=(int)2e5+7;

int a[N];
int b[N];

map<ld,int>f;

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++) cin>>b[i];
        int z=0;
        for(int i=1;i<=n;i++)
        {
                if(a[i]==0)
                {
                        if(b[i]==0)
                        {
                                z++;
                        }
                }
                else
                {
                        f[(ld)-b[i]/(ld)a[i]]++;
                }
        }
        int mx=0;
        for(auto &it:f)
        {
                mx=max(mx,it.second);
        }
        z+=mx;
        cout<<z<<"\n";
        return 0;
}
/**

**/