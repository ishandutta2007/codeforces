#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> pip;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int c=0,a;
        for(int i=0;i<n;i++)
        {
            cin >> a;
            if(a&1)
                c++;
        }
        if((n==1 && c==0) || c==0 || (c==n && n%2==0))
            db("NO")
        else
            db("YES")
    }

    return 0;
}