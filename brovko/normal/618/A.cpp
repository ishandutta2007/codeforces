#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back
#define mp make_pair

using namespace std;



int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    bitset <20> b = n;

    for(int i = 19; i >= 0; i--)
        if(b[i])
            cout << i + 1 << ' ';
}