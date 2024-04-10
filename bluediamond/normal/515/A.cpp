#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int a,b,s;
    cin>>a>>b>>s;
    a=abs(a);
    b=abs(b);
    if(a+b<=s && s%2==(a+b)%2)
    {
        cout<<"Yes\n";
    }
    else
    {
        cout<<"No\n";
    }
    return 0;
}
/**


**/