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
        int n,m;
        cin >> n >> m;
        string s;
        cin >> s;
        int c=ranges::count(s,'1');
        if((ll(c)*m)%n) cout << "-1\n";
        else
        {
            int k=(ll(c)*m/n);
            vector<int> sum(n+1,0);
            for(int i=1;i<=n;i++) sum[i]=sum[i-1]+(s[i-1]-'0');
            bool ok=0;
            for(int i=1;i+m-1<=n;i++)
            {
                if(sum[i+m-1]-sum[i-1]==k)
                {
                    cout << "1\n";
                    cout << i << " " << i+m-1 << "\n";
                    ok=1;
                    break;
                }
            }
            if(!ok)
            {
                for(int i=1;i<m;i++)
                {
                    if(sum[i]+sum[n]-sum[n-(m-i)]==k)
                    {
                        cout << "2\n";
                        cout << 1 << " " << i << "\n";
                        cout << n-(m-i)+1 << " " << n << "\n";
                        break;
                    }
                }
            }
        }
    }
    return 0;
}