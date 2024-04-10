#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

   // freopen(".in","r",stdin);

    int n,p;
    string s;
    cin >> n >> p >> s;
    bool ok=1;
    for(int i=0;i<n-p;i++)
    {
        if(s[i]==s[i+p] && (s[i]=='1' || s[i]=='0'))
            continue;
        else
        {
            ok=0;
            if(s[i]=='.' || s[i+p]=='.')
            {
                if(s[i]=='.' && s[i+p]!='.')
                    s[i]='1'+'0'-s[i+p];
                else if(s[i+p]=='.' && s[i]!='.')
                    s[i+p]='1'+'0'-s[i];
                else
                {
                    s[i]='0';
                    s[i+p]='1';
                }
            }
        }
    }

    for(int i=n-p;i<n;i++)
        if(s[i]=='.')
            s[i]='0';
    if(ok)
        db("No")
    else
        db(s)

    return 0;
}