#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q;
    cin>>q;
    while(q--)
    {
        ll s,a,b,c;
        cin>>s>>a>>b>>c;
        ll ch=s/c;
        cout<<ch+b*(ch/a)<<"\n";
    }
    return 0;
}
/**

**/