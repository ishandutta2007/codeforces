#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef long double ld;

int a[7];

int p(int x)
{
    return x*x;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for(int i=1;i<=6;i++)
    {
        cin>>a[i];
    }
    int ans=p(a[1]+a[2]+a[3])-p(a[1])-p(a[3])-p(a[5]);
    cout<<ans<<"\n";
    return 0;
}
/**


**/