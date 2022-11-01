#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    auto prime=[](int x)
    {
        bool ok=1;
        for(int i=2;i*i<=x;i++) ok&=((x%i)!=0);
        return ok;
    };
    auto out=[](int x){cout << x << "\n"; exit(0);};
    if(prime(n)) out(1);
    if((n%2)==0) out(2);
    if(prime(n-2)) out(2);
    out(3);
    return 0;
}