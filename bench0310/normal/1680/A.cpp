#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int l1,r1,l2,r2;
        cin >> l1 >> r1 >> l2 >> r2;
        int res=l1+l2;
        if(!(r1<l2)&&!(r2<l1)) res=min(res,max(l1,l2));
        cout << res << "\n";
    }
    return 0;
}