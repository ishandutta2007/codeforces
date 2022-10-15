#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,s1=0,s2=0,x;
    cin>>n;
    for(int i=1;i<=n;i++) {cin>>x;s1+=x;}
    for(int i=1;i<=n;i++) {cin>>x;s2+=x;}
    if(s1>=s2)
    {
        cout<<"Yes\n";
    }
    else
        cout<<"No\n";
    return 0;
}
/**

**/