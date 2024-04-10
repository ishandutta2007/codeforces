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
        int n,k;
        cin >> n >> k;
        string s;
        cin >> s;
        s="$"+s;
        if(k&1) for(int i=1;i<=n;i++) s[i]=('0'^'1'^s[i]);
        vector<int> res(n+1,0);
        for(int i=1;i<=n;i++)
        {
            if(s[i]=='0'&&k>0)
            {
                s[i]='1';
                res[i]++;
                k--;
            }
        }
        if(k>0)
        {
            res[n]+=k;
            if(k&1) s[n]='0';
        }
        cout << s.substr(1,n) << "\n";
        for(int i=1;i<=n;i++) cout << res[i] << " \n"[i==n];
    }
    return 0;
}