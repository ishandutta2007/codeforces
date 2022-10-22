#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;

map<int,bool> m;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int res=0;
    while(!m[n])
    {
        m[n]=1;
        res++;
        n++;
        while(n%10==0)
            n/=10;
    }
    db(res)

    return 0;
}