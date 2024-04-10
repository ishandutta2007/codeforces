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
        int x;
        cin >> x;
        ll res=(1ll<<60);
        for(int i=0;i<(1<<10);i++)
        {
            string s;
            int sum=0;
            for(int j=1;j<=9;j++)
            {
                if(i&(1<<j))
                {
                    s+=((char)('0'+j));
                    sum+=j;
                }
            }
            if(sum==x) res=min(res,stoll(s));
        }
        if(res==(1ll<<60)) res=-1;
        cout << res << "\n";
    }
    return 0;
}