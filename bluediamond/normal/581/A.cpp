#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef long double ld;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int a,b;
    cin>>a>>b;
    int t=min(a,b);
    a-=t;
    b-=t;
    cout<<t<<" "<<(max(a,b)>>1)<<"\n";
    return 0;
}
/**


**/