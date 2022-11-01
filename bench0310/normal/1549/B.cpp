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
        string a,b;
        cin >> b >> a;
        string r(n,'0');
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]=='0') continue;
            for(int j=max(0,i-1);j<=min(n-1,i+1);j++)
            {
                if(r[j]=='0'&&(j==i)==(b[j]=='0'))
                {
                    r[j]='1';
                    cnt++;
                    break;
                }
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}