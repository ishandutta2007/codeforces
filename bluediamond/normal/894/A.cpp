#include <iostream>
#include <cstring>
using namespace std;
#define ll long long
char s[105];
ll sum,sl,par,n;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin.getline(s,105);
    n=strlen(s);
    for(int i=0;i<n;i++)
        if(s[i]=='Q')
            sum++;
    for(int i=0;i<n;i++)
        if(s[i]=='Q')
            par++;
        else
            if(s[i]=='A')
                sl+=par*(sum-par);
    cout<<sl;
    return 0;
}