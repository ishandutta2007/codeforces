#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef long double ld;

ll calc(ll a,ll b)
{
    if(a==0 || b==0)
    {
        return 0;
    }
    else
    {
        if(a<b)
        {
            swap(a,b);
        }
        /// a > b
        return a/b+calc(b,a%b);
    }
}

int main()
{
///    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll a,b;
    cin>>a>>b;
    cout<<calc(a,b)<<"\n";
    return 0;
}
/**


**/