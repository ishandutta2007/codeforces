#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, ok=1, fo=0;
    string s;
    cin>>n>>s;
    if(s[0]=='?') fo=1;
    if(s[n-1]=='?') fo=1;
    for(int a=1; a<n-1; a++)
    {
        if(s[a]=='?')
        {
            if(s[a-1]=='?' or s[a+1]=='?') fo=1;
            else if(s[a-1]==s[a+1]) fo=1;
        }
        else
        {
            if(s[a-1]==s[a] or s[a+1]==s[a]) ok=0;
        }
    }
    if(ok and fo) cout<<"Yes";
    else cout<<"No";
}