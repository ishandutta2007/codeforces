#include <bits/stdc++.h>
#define db(x) cout << x << '\n';
using namespace std;
typedef long long ull;

int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n,k,sum=0,x;
    cin >> n >> k;
    for(int i=0;i<n;i++)
    {
        cin >> x;
        sum+=x;
    }

    db(max(0,2*(k*n-sum)-n))

    return 0;
}