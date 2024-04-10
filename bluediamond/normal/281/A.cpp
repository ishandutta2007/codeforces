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
    char s[1005];
    int n;
    cin.getline(s,1005);
    n=strlen(s);
    if('a'<=s[0] and s[0]<='z')
        cout<<char('A'+s[0]-'a');
    else
        cout<<s[0];
    for(int i=1;i<n;i++)
        cout<<s[i];
    return 0;
}
/**
**/