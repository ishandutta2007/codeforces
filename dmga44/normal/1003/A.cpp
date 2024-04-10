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
typedef pair<int,int> pii;
#define MAXN 105

int mk[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,a;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a;
        mk[a]++;
    }

    int res=0;
    for(int i=0;i<MAXN;i++)
        res=max(res,mk[i]);

    db(res)

    return 0;
}