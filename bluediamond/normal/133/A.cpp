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
    int n;
    cin.getline(s,105);
    n=strlen(s);
    for(int i=0;i<n;i++)
        if(s[i]=='H' or s[i]=='Q' or s[i]=='9')
        {
            cout<<"YES";
            return 0;
        }
    cout<<"NO";
    return 0;
}
/**
**/