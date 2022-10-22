#include <bits/stdc++.h>
#define int long long
#define ld lond double
#define y1 eohfweoifhew

using namespace std;

char a, b;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b;

    if((a == 'a' || a == 'h') && (b == '1' || b == '8'))
        cout << 3;

    else if(a == 'a' || a == 'h' || b == '1' || b == '8')
        cout << 5;

    else cout << 8;
}