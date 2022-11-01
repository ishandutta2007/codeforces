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
        string s;
        cin >> s;
        int cnt=0;
        for(char c:s) cnt+=(c=='1');
        if((cnt&1)||s[0]=='0'||s[n-1]=='0') cout << "NO\n";
        else
        {
            string a,b;
            int d=0;
            cnt/=2;
            for(char c:s)
            {
                if(c=='1')
                {
                    char z=')';
                    if(cnt>0)
                    {
                        z='(';
                        cnt--;
                    }
                    a+=z;
                    b+=z;
                }
                else
                {
                    if(d==0)
                    {
                        a+='(';
                        b+=')';
                        d=1;
                    }
                    else
                    {
                        a+=')';
                        b+='(';
                        d=0;
                    }
                }
            }
            cout << "YES\n";
            cout << a << "\n";
            cout << b << "\n";
        }
    }
    return 0;
}