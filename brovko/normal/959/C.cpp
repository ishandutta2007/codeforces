#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 doijwfojeoif

using namespace std;

int n;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    if(n<6)
        cout << "-1\n";
    else
    {
        cout << "1 2\n1 3\n1 4\n";
        for(int i=5;i<=n;i++)
            cout << "4 " << i << "\n";
    }

    for(int i=2;i<=n;i++)
        cout << 1 << ' ' << i << "\n";
}