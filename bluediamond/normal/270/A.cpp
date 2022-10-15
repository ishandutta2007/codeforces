#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef long double ld;

ld f(ld n)
{
    return 180*(n-2)/n;
}

bool ok[180];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for(ld i=3;i<=10000;i++)
    {
        ld x=f(i);
        if(x==(int)x)
        {
            ok[(int)x]=1;
        }
    }
    int t;
    cin>>t;
    while(t--)
    {
        int x;
        cin>>x;
        if(ok[x]) cout<<"YES\n"; else cout<<"NO\n";
    }
    return 0;
}
/**


**/