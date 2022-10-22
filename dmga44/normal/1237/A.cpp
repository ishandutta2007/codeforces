#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int imp=0;
    for(int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        if(x&1)
        {
            if(imp&1)
                cout << (x+1)/2 << '\n';
            else
                cout << (x-1)/2 << '\n';
            imp++;
        }
        else
            cout << x/2 << '\n';
    }

    return 0;
}