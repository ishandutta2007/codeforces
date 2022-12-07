#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    string s;
    cin>>s;
    int n=s.size(), q=0;
    char an[n];
    for(int a=0; a<n; a++)
    {
        an[a]=s[a];
        if(s[a]-'a'<=q and q<26)
        {
            an[a]='a'+q, q++;
        }
    }
    if(q==26)
    {
        for(int a=0; a<n; a++) cout<<an[a];
    }
    else cout<<-1;
}