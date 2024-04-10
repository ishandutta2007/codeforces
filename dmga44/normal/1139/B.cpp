#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAXN 200005

ll a[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    ll res=0,ma=2e9;
    for(int i=0;i<n;i++)
        cin >> a[i];

    for(int i=n-1;i>=0;i--)
    {
        ma=min(ma,a[i]);
        res+=ma;
        if(ma)
            ma--;
    }
    db(res)

    return 0;
}