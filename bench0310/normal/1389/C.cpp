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
        string s;
        cin >> s;
        int n=s.size();
        int res=n;
        vector<int> cnt(10,0);
        for(char c:s) cnt[c-'0']++;
        for(int i=0;i<=9;i++) res=min(res,n-cnt[i]);
        for(char a='0';a<='9';a++)
        {
            for(char b='0';b<='9';b++)
            {
                if(a==b) continue;
                int x=0;
                for(char c:s)
                {
                    if((x%2)==0&&c==a) x++;
                    else if((x%2)==1&&c==b) x++;
                }
                x-=(x&1);
                res=min(res,n-x);
            }
        }
        cout << res << "\n";
    }
    return 0;
}