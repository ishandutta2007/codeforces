#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    string s, t;
    cin>>n>>m>>s>>t;
    int fo=-1;
    for(int a=0; a<n; a++) if(s[a]=='*') fo=a;
    if(fo==-1)
    {
        if(s==t) cout<<"YES";
        else cout<<"NO";
    }
    else
    {
        if(s.size()-1<=t.size())
        {
            if(s.substr(0, fo)==t.substr(0, fo) and s.substr(fo+1, n-fo-1)==t.substr(m-(n-fo-1), n-fo-1)) cout<<"YES";
            else cout<<"NO";
        }
        else cout<<"NO";
    }
}