#include <bits/stdc++.h>
#define int long long
#define y1 sdofhdodfhd

using namespace std;

int x, y, z, a, b, c;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> x >> y >> z >> a >> b >> c;
    if(x<=a && x+y<=a+b && x+y+z<=a+b+c)
        cout << "YES";
    else cout << "NO";
}