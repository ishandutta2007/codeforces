//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, an=0;
    cin>>n;
    string s;
    while(cin>>s)
    {
        int q=0;
        for(int a=0; a<s.size(); a++) if(s[a]>='A' and s[a]<='Z') q++;
        an=max(an, q);
    }
    cout<<an;
}