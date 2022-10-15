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
    int n=strlen(s),v[105],y=0;
    for(int i=0;i<n;i+=2)
        v[++y]=s[i]-'0';
    sort(v+1,v+y+1);
    for(int i=1;i<y;i++)
        cout<<v[i]<<"+";
    cout<<v[y];
    return 0;
}
/**
**/