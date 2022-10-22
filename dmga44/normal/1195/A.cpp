#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<pii,pii> ppp;
#define MAXN 1005

int a[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,k,x;
    cin >> n >> k;
    for(int i=0;i<n;i++)
    {
        cin >> x;
        a[x]++;
    }

    int odd=0;
    for(int i=1;i<=k;i++)
        if(a[i]&1)
            odd++;
    x=(n+1)/2;
    db((n-odd)+x-((n-odd)/2))

    return 0;
}