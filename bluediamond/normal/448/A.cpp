#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int x,y,z,n;
    cin>>x>>y>>z; int a=x+y+z;
    cin>>x>>y>>z; int b=x+y+z;
    cin>>n;
    if((a+4)/5+(b+9)/10<=n)
        cout<<"YES\n";
    else
        cout<<"NO\n";
    return 0;
}
/**
**/