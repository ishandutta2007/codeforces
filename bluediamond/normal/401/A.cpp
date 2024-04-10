#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef long double ld;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,x,s=0;
    cin>>n>>x;
    for(int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        s+=a;
    }
    s=abs(s);
    cout<<(s+x-1)/x<<"\n";
    return 0;
}
/**


**/