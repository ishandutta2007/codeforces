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
    char s1[105],s2[105];
    cin.getline(s1,105);
    cin.getline(s2,105);
    int n=strlen(s1);
    for(int i=0;i<n;i++)
        if('A'<=s1[i] and s1[i]<='Z')
            s1[i]='a'+s1[i]-'A';
    for(int i=0;i<n;i++)
        if('A'<=s2[i] and s2[i]<='Z')
            s2[i]='a'+s2[i]-'A';
    for(int i=0;i<n;i++)
    {
        if(s1[i]<s2[i])
        {
            cout<<-1;
            return 0;
        }
        if(s1[i]>s2[i])
        {
            cout<<1;
            return 0;
        }
    }
    cout<<0;
    return 0;
}
/**
**/