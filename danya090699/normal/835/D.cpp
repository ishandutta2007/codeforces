//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
const int sz=5e3+10;
char is[sz][sz];
int main()
{
    //freopen("input.txt", "r", stdin);
    string s;
    cin>>s;
    int n=s.size(), q=0;
    for(int a=0; a<n; a++)
    {
        is[0][a]=1, is[1][a]=1, q++;
    }
    for(int a=2; a<=n; a++)
    {
        for(int b=0; b<=n-a; b++)
        {
            if(is[a-2][b+1]==1 and s[b]==s[b+a-1])
            {
                is[a][b]=1, q++;
            }
            else is[a][b]=0;
        }
    }
    cout<<q;
    for(int i=1; i<n; i++)
    {
        if(q==0) cout<<" 0";
        else
        {
            q=0;
            for(int a=n; a>1; a--)
            {
                int le=a/2;
                for(int b=0; b<=n-a; b++)
                {
                    if(is[a][b]==1 and is[le][b]==1 and is[le][b+a-le]==1)
                    {
                        is[a][b]=1, q++;
                    }
                    else is[a][b]=0;
                }
            }
            for(int a=0; a<n; a++) is[1][a]=0;
            cout<<" "<<q;
        }
    }
}