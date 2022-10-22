#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
#define MAXN 105

int f[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie();

    int n,k,a;
    cin >> n >> k;
    for(int i=0;i<n;i++)
    {
        cin >> a;
        f[a%k]++;
    }

    int res=f[0]-(f[0]&1);
    if(k%2==0)
        res+=f[k/2]-(f[k/2]&1);
    for(int i=1;i<(k+1)/2;i++)
        res+=2*min(f[i],f[k-i]);
    db(res)

    return 0;
}