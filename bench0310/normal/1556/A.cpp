#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int c,d;
        cin >> c >> d;
        int res=0;
        if((c-d)&1) res=-1;
        else if(c==0&&d==0) res=0;
        else if(c==d) res=1;
        else res=2;
        cout << res << "\n";
    }
    return 0;
}