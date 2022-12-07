//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    string s;
    cin>>s;
    int n=s.size(), yk=0;
    char gl[]={'a', 'e', 'i', 'o', 'u'};
    while(yk<n)
    {
        if(yk+3>n)
        {
            while(yk<n)
            {
                cout<<s[yk], yk++;
            }
        }
        else
        {
            bool ok=0;
            for(int a=yk; a<yk+3; a++)
            {
                bool g=0;
                for(int b=0; b<5; b++)
                {
                    if(s[a]==gl[b]) g=1;
                }
                if(g) ok=1;
            }
            if(ok==0 and (s[yk]!=s[yk+1] or s[yk+1]!=s[yk+2]))
            {
                cout<<s[yk]<<s[yk+1]<<" ";
                yk+=2;
            }
            else
            {
                cout<<s[yk];
                yk++;
            }
        }
    }
}