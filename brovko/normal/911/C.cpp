#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int a, b, c;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b >> c;
    if(a > b)
        swap(a, b);
    if(b > c)
        swap(b, c);
    if(a > b)
        swap(a, b);

    if(a==1 || b==2 || (a==3 && c==3) || (a==2 && b==4 && c==4))
        cout << "YES";
    else cout << "NO";
}