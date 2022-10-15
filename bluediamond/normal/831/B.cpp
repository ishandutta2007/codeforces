#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;
int v[35];
int main()
{
    char s1[27],s[1005],ch;
    int n,i;
    cin.getline(s1,27);
    cin.getline(s,27);
    for(i=0;i<26;i++)
        v[s1[i]-'a']=s[i];
    cin.getline(s,1005);
    n=strlen(s);
    for(i=0;i<n;i++)
    {
        int x=s[i];bool m=0,d=0;
        d=isdigit(s[i]);
        if(x<97 and !d)
        {
            x=97+x-'A';
            m=1;
        }
        if(!d)
            x-='a';
        if(!d)
            {
            if(m)
                cout<<char{v[x]-('a'-'A')};
            else
                cout<<char{v[x]};
            }
        else
            cout<<s[i];
    }
    return 0;
}