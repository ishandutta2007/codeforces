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
        int a,b;
        string s;
        cin >> a >> b >> s;
        int n=s.size();
        string res=[&]()->string
        {
            if(a+b!=n) return "-1";
            int one=-1;
            int two=0;
            for(int i=0;i<=n-1-i;i++)
            {
                if(s[i]!='?'&&s[n-1-i]!='?')
                {
                    if(s[i]!=s[n-1-i]) return "-1";
                }
                else if(s[i]!='?'&&s[n-1-i]=='?') s[n-1-i]=s[i];
                else if(s[i]=='?'&&s[n-1-i]!='?') s[i]=s[n-1-i];
                else
                {
                    if(i<n-1-i) two++;
                    else one=i;
                }
            }
            for(int i=0;i<n;i++)
            {
                a-=(s[i]=='0');
                b-=(s[i]=='1');
            }
            if(a<0||b<0) return "-1";
            if(one!=-1)
            {
                if(a&1)
                {
                    s[one]='0';
                    a--;
                }
                else if(b&1)
                {
                    s[one]='1';
                    b--;
                }
            }
            if((a&1)||(b&1)) return "-1";
            for(int i=0;i<n-1-i;i++)
            {
                if(s[i]=='?')
                {
                    if(a>0)
                    {
                        s[i]=s[n-1-i]='0';
                        a-=2;
                    }
                    else
                    {
                        s[i]=s[n-1-i]='1';
                        b-=2;
                    }
                }
            }
            return s;
        }();
        cout << res << "\n";
    }
    return 0;
}