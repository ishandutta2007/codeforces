#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef long double ld;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    ld s=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        ld x;
        cin>>x;
        s+=x;
    }
    s/=(ld)n;
    cout<<fixed<<setprecision(6)<<s<<"\n";
    return 0;
}
/**


**/