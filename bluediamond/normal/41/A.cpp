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
    if(strlen(s2)!=n)
    {
        cout<<"NO";
        return 0;
    }
    for(int i=0;i<n;i++)
        if(s1[i]!=s2[n-1-i])
        {
            cout<<"NO";
            return 0;
        }
    cout<<"YES";
    return 0;
}
/**
**/