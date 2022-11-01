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
        string a,s;
        cin >> a >> s;
        int idx=(int)s.size()-1;
        ranges::reverse(a);
        cout << [&]()->string
        {
            string b;
            for(char c:a)
            {
                int x=(c-'0');
                if(idx==-1) return "-1";
                int y=(s[idx--]-'0');
                if(x<=y) b+=char('0'+y-x);
                else
                {
                    if(idx==-1||s[idx]!='1') return "-1";
                    idx--;
                    b+=char('0'+10+y-x);
                }
            }
            while(idx>=0) b+=s[idx--];
            while(b.size()>=2&&b.back()=='0') b.pop_back();
            ranges::reverse(b);
            return b;
        }() << "\n";
    }
    return 0;
}