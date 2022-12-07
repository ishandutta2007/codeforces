#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    string s;
    cin>>s;
    int n=s.size(), an=0;
    for(int a=0; a<n; a++)
    {
        for(int b=a+1; b<=n; b++)
        {
            bool ok=1;
            for(int c=0; a+c<b; c++) if(s[a+c]!=s[b-c-1]) ok=0;
            if(ok==0) an=max(an, b-a);
        }
    }
    cout<<an;
}