#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int n=s.size();
    if(n==1)
    {
        if(isdigit(s[0])) cout << (s[0]=='0') << "\n";
        else cout << "1\n";
    }
    else
    {
        int res=0;
        for(int x=0;x<=9;x++)
        {
            string t=s;
            for(char &c:t) if(c=='X') c=('0'+x);
            if(t[0]=='0') continue;
            int opt=1;
            for(int i=0;i<n-2;i++) if(t[i]=='_') opt*=(10-(i==0));
            vector<string> v={"00","25","50","75"};
            for(string a:v)
            {
                bool ok=1;
                for(int i=0;i<2;i++) ok&=(t[n-2+i]=='_'||t[n-2+i]==a[i]);
                if(ok&&!(n==2&&a=="00")) res+=opt;
            }
        }
        bool e=0;
        for(char c:s) e|=(c=='X');
        if(!e) res/=10;
        cout << res << "\n";
    }
    
    return 0;
}