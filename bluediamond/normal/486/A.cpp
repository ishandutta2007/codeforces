#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll a;
    cin>>a;
    if(a%2==0)
        cout<<(a/2)<<"\n";
    else
        cout<<(a/2)-a<<"\n";
    return 0;
}
/**

**/