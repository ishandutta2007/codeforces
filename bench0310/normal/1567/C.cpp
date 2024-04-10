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
        string s=to_string(n);
        reverse(s.begin(),s.end());
        int len=s.size();
        ll res=0;
        for(int m=0;m<(1<<len);m++)
        {
            if((m&1)||(m&2)) continue;
            ll now=1;
            for(int i=0;i<len;i++)
            {
                int c=((m>>i)&1);
                int nxt=((m>>(i+2))&1);
                int opt=0;
                for(int a=0;a<=9;a++) for(int b=0;b<=9;b++) if((a+b+c)%10==(s[i]-'0')&&(a+b+c>=10)==nxt) opt++;
                now*=opt;
            }
            res+=now;
        }
        cout << res-2 << "\n";
    }
    return 0;
}