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
    cin.getline(s,105);
    int n=strlen(s);
    for(int i=0;i+6<=n-1;i++)
    {
        if(s[i]==s[i+1] and s[i]==s[i+2] and s[i]==s[i+3] and s[i]==s[i+4] and s[i]==s[i+5] and s[i]==s[i+6])
        {
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}
/**
**/