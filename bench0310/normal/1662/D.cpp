#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    while(tc--)
    {
        auto f=[&](string s)->string
        {
            int b=0;
            string t;
            for(char a:s)
            {
                if(a=='B') b^=1;
                else
                {
                    if(t.empty()||t.back()!=a) t+=a;
                    else t.pop_back();
                }
            }
            if(b==1) t+='B';
            return t;
        };
        string a,b;
        cin >> a >> b;
        if(f(a)==f(b)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}