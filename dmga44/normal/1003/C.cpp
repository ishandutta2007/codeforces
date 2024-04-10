#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define dbg(x) cout << #x << " : " << (x) << '\n';
#define mn(a, b) (a < b ? a : b)
#define mx(a, b) (a > b ? a : b)
#define all(v)  (v).begin(), (v).end()
#define f first
#define s second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
#define MAXN 5005

int a[MAXN],ac[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cout.precision(15);
    cout<<fixed;

    int n,k;
    cin >> n >> k;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        ac[i+1]=ac[i]+a[i];
    }

    ld res=0;
    for(int i=0;i<n;i++)
        for(int j=i+k;j<=n;j++)
            res=max(res,(ld)(ac[j]-ac[i])/(ld)(j-i));
    db(res)

    return 0;
}