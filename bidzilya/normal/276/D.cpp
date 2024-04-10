#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <algorithm>
using namespace std;

typedef long long ll;
const int N = 63;

ll st[N];

ll go(ll l, ll r)
{
    for (int i=N-1; i>=0; i--)
        if (st[i]-1>=l && st[i]<=r)
            return st[i+1]-1;
    for (int i=0; i<N; i++)
        if (st[i+1]>l)
        {
            l -= st[i];
            r -= st[i];
            return go(l,r);
        }
}

int main()
{
    st[0] = 1;
    for (int i=1; i<N; i++)st[i] = st[i-1]*2;
    ll l,r;
    cin >> l >> r;
    if (l==r){cout << 0 << endl; return 0;}
    cout << go(l,r) << endl;
    return 0;
}