#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    string s;
    cin>>s;
    int n=s.size(), fo=0;
    for(int a=0; a<n-1-a; a++) if(s[a]!=s[0]) fo=1;
    if(fo)
    {
        for(int a=1; a<n; a++)
        {
            string t=s.substr(a, n-a)+s.substr(0, a);
            bool ok=1;
            for(int b=0; b<n-1-b; b++) if(t[b]!=t[n-1-b]) ok=0;
            if(ok and t!=s)
            {
                cout<<1;
                return 0;
            }
        }
        cout<<2;
    }
    else cout<<"Impossible";
}