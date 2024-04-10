#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    string s, t;
    cin>>s>>t;
    char sy[5]={'a', 'e', 'i', 'o', 'u'};
    if(s.size()==t.size())
    {
        bool ok=1;
        for(int a=0; a<s.size(); a++)
        {
            int ty1=0, ty2=0;
            for(int b=0; b<5; b++)
            {
                if(s[a]==sy[b]) ty1=1;
                if(t[a]==sy[b]) ty2=1;
            }
            if(ty1!=ty2) ok=0;
        }
        if(ok) cout<<"Yes";
        else cout<<"No";
    }
    else cout<<"No";
}