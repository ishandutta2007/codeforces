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
    int s=0;
    for(int i=0;i<n;i++)
    {
        char c;
        cin >> c;
        if(c=='+')
            s++;
        else
            s=max(0,s-1);
    }
    db(s)

    return 0;
}