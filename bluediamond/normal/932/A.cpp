#include <bits/stdc++.h>
using namespace std;
const int nmax=1e5;
char s[nmax+5];
int n;
int Left[nmax+5],Right[nmax+5],Yst,Ydr;
int st,dr;
int main()
{
    cin.getline(s,nmax+5);
    n=strlen(s);
    st=0;
    dr=n-1;
    while(st<=dr)
    {
        if(st==dr)
        {
            Left[++Yst]=s[st];
            break;
        }
        if(s[st]==s[dr])
        {
            Left[++Yst]=s[st];
            Right[++Ydr]=s[dr];
            st++;
            dr--;
            continue;
        }
        Left[++Yst]=s[st];
        Right[++Ydr]=s[st];
        st++;
    }
    for(int i=1;i<=Yst;i++)cout<<char(Left[i]);
    for(int i=Ydr;i>=1;i--)cout<<char(Right[i]);
    return 0;
}