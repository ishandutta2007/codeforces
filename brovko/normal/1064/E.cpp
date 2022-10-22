#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n;
string c, x;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("name.in", "r", stdin);
    //freopen("name.out", "w", stdout);

    cin >> n;
    n--;
    int L=1;
    int R=1e9-2;
    cout << "0 0" << endl;
    cin >> c;

    for(int i=0;i<n;i++)
    {
        int M=(L+R)/2;
        cout << M << ' ' << 0 << endl;
        cin >> x;
        if(x==c)
            L=M+1;
        else R=M;
    }

    cout << L << " 1 " << L+1 << " 5" << endl;
}