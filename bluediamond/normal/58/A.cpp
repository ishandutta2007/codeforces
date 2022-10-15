#include <iostream>
#include <math.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <iomanip>
#include <cstring>
#include <cctype>
using namespace std;
#define ll long long
int n,poz=0;
char s[105];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin.getline(s,105);
    n=strlen(s);
    bool ok;
    ok=0;
    for(int i=poz;i<n;i++)
    {
        if(s[i]=='h')
        {
            ok=1;
            poz=i;
            break;
        }
    }
    if(ok==0)
    {
        cout<<"NO";
        return 0;
    }
    ok=0;
    for(int i=poz;i<n;i++)
    {
        if(s[i]=='e')
        {
            ok=1;
            poz=i;
            break;
        }
    }
    if(ok==0)
    {
        cout<<"NO";
        return 0;
    }
    ok=0;
    for(int i=poz;i<n;i++)
    {
        if(s[i]=='l')
        {
            ok=1;
            poz=i+1;
            break;
        }
    }
    if(ok==0)
    {
        cout<<"NO";
        return 0;
    }
    ok=0;
    for(int i=poz;i<n;i++)
    {
        if(s[i]=='l')
        {
            ok=1;
            poz=i;
            break;
        }
    }
    if(ok==0)
    {
        cout<<"NO";
        return 0;
    }
    ok=0;
    for(int i=poz;i<n;i++)
    {
        if(s[i]=='o')
        {
            ok=1;
            poz=i;
            break;
        }
    }
    if(ok==0)
    {
        cout<<"NO";
        return 0;
    }
    cout<<"YES";
    return 0;
}
/**
hello
**/