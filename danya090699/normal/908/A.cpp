#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    string s;
    cin>>s;
    int q=0;
    for(int a=0; a<s.size(); a++)
    {
        if(s[a]>='0' and s[a]<='9')
        {
            if((s[a]-'0')%2) q++;
        }
        else if(s[a]=='a' or s[a]=='e' or s[a]=='i' or s[a]=='o' or s[a]=='u') q++;
    }
    cout<<q;
}