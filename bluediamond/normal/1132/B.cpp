#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=(int)3e5+7;

int n;
int v[N];

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        cin>>n;
        ll s=0LL;
        for(int i=1;i<=n;i++)
        {
                cin>>v[i];
                s+=v[i];
        }
        sort(v+1,v+n+1);
        reverse(v+1,v+n+1);
        int q;
        cin>>q;
        while(q--)
        {
                int k;
                cin>>k;
                cout<<s-v[k]<<"\n";
        }
        return 0;
}