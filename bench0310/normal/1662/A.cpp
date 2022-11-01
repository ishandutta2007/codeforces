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
        vector<int> m(11,0);
        for(int i=1;i<=n;i++)
        {
            int b,d;
            cin >> b >> d;
            m[d]=max(m[d],b);
        }
        int s=0;
        bool ok=1;
        for(int i=1;i<=10;i++)
        {
            s+=m[i];
            ok&=(m[i]>0);
        }
        if(ok) cout << s << "\n";
        else cout << "MOREPROBLEMS\n";
    }
    return 0;
}