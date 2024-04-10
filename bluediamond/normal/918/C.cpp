#include<bits/stdc++.h>
using namespace std;
const int nmax=5000;
char s[nmax+5];
int n,ans=0;
int main()
{
    cin.getline(s,nmax+5);
    n=strlen(s);
    for(int st=0;st<n;st++)
    {
        int MA=0,MI=0;
        for(int dr=st;dr<n;dr++)
        {
            if(s[dr]=='(')
            {
                MA++;
                MI++;
            }
            if(s[dr]==')')
            {
                MA--;
                MI--;
                MI=max(MI,0);
            }
            if(s[dr]=='?')
            {
                MA++;
                MI--;
                MI=max(MI,0);
            }
            if(MA<0)
                break;
            if((dr-st+1)%2==0 and MI==0)
                ans++;
        }
    }
    cout<<ans;
    return 0;
}