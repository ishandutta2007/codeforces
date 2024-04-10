#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, an;
    string s;
    cin>>n>>s;
    an=n;
    for(int a=0; a+1<n; a++)
    {
        if((s[a]=='R' and s[a+1]=='U') or (s[a]=='U' and s[a+1]=='R'))
        {
            a++, an--;
        }
    }
    cout<<an;
}