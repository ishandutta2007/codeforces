//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, q=0;
    cin>>n;
    string s;
    cin>>s;
    s.push_back('0');
    for(int a=0; a<=n; a++)
    {
        if(s[a]=='1') q++;
        else
        {
            cout<<q;
            q=0;
        }
    }
}