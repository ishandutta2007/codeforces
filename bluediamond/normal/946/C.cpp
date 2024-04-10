#include <bits/stdc++.h>

using namespace std;
const int nmax=100000;
char s[nmax+5];
int n;
int poz;
int main()
{
    cin.getline(s,nmax+5);
    n=strlen(s);
    bool ok=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]-'a'<=poz)
        {
            s[i]='a'+poz;
            poz++;
            if(s[i]=='z')
            {
                ok=1;
                break;
            }
        }
    }
    if(ok)
        cout<<s;
    else
        cout<<-1;
    return 0;
}