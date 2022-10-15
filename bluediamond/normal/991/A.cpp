#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

ll a,b,c,n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>a>>b>>c>>n;
    ll p1=a-c;
    ll p2=b-c;
    ll p3=c;
    if(p1>=0 && p2>=0 && p3>=0)
    {
        ll su=p1+p2+p3;
        if(su<n)
        {
            cout<<n-su<<"\n";
            return 0;
        }
    }
    cout<<"-1\n";
    return 0;
}
/**



**/