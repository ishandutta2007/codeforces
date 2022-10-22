#include <bits/stdc++.h>
#define int long long
#define y1 dwihweoighweoi
#define ld long double

using namespace std;

int x, y;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> x >> y;
    if(y==0 || (y==1 && x>0))
    {
        cout << "No";
        return 0;
    }
    x-=y-1;
    if(x>=0 && x%2==0)
        cout << "Yes";
    else cout << "No";
}