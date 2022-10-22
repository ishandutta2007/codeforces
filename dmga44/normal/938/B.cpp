#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,x;
    cin >> n;
    int res=0;
    for(int i=0;i<n;i++)
    {
        cin >> x;
        res=max(res,min(x-1,1000000-x));
    }
    db(res)

    return 0;
}