#include <iostream>
#include <cstring>
using namespace std;
#define ll long long
int main()
{
    char s[105];
    ll n,i,poz=-1;
    cin.getline(s,105);
    n=strlen(s);
    for(i=0;i<n;i++)
        if(s[i]=='1')
        {
            poz=i;
            break;
        }
    if(poz==-1)
    {
        cout<<"no";
        return 0;
    }
    int su=0;
    for(int i=poz;i<n;i++)
        if(s[i]=='0')
            su++;
    if(su>=6)
        cout<<"yes";
    else
        cout<<"no";
    return 0;
}
/**

**/