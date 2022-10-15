#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=(int)3e5+7;

int n;
int v[N];

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        cin>>n;
        for(int i=1;i<=n;i++)
        {
                cin>>v[i];
        }
        int p=n;
        while(v[p]==v[1])
        {
                p--;
        }
        int res=(p-1);
        p=1;
        while(v[p]==v[n])
        {
                p++;
        }
        res=max(res,n-p);
        cout<<res<<"\n";
        return 0;
}
/**

**/