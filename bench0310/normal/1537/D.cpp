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
        int n;
        cin >> n;
        int z=n;
        int p=0;
        while((z%2)==0)
        {
            z/=2;
            p++;
        }
        int res=0;
        if(z==1&&(p&1)) res=0;
        else if(n&1) res=0;
        else res=1;
        if(res==1) cout << "Alice\n";
        else cout << "Bob\n";
    }
    return 0;
}