//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int l, r, x, y, k, ok=0;
    cin>>l>>r>>x>>y>>k;
    for(x; x<=y; x++) if(1ll*x*k>=l and 1ll*x*k<=r) ok=1;
    if(ok) cout<<"YES";
    else cout<<"NO";
}