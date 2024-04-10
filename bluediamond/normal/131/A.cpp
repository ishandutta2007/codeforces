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
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    char s[105];
    int n,ok=1;
    cin.getline(s,105);
    n=strlen(s);
    for(int i=1;i<n;i++)
        if('a'<=s[i] and s[i]<='z')
        {
            ok=0;
            break;
        }
    if(ok)
    {
        if('a'<=s[0] and s[0]<='z')
            cout<<char('A'+s[0]-'a');
        else
            cout<<char('a'+s[0]-'A');
        for(int i=1;i<n;i++)
            cout<<char('a'+s[i]-'A');
    }
    else
        cout<<s;
    return 0;
}
/**
**/