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
        string res;
        for(int m=1;m<=3;m++)
        {
            string a(m,'$');
            function<void(int)> gen=[&](int o)
            {
                if(o==m)
                {
                    if(!res.empty()) return;
                    bool ok=1;
                    for(int i=0;i+m-1<n;i++) ok&=(s.substr(i,m)!=a);
                    if(ok) res=a;
                    return;
                }
                for(int i=0;i<26;i++)
                {
                    a[o]=('a'+i);
                    gen(o+1);
                }
            };
            gen(0);
            if(!res.empty()) break;
        }
        cout << res << "\n";
    }
    return 0;
}