#include <bits/stdc++.h>
using namespace std;
int mo(int x)
{
    if(x<0) return -x;
    else return x;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, q1=0, q2=0;
    cin>>n;
    string s;
    cin>>s;
    for(int a=0; a<n; a++)
    {
        if(s[a]=='U') q1++;
        if(s[a]=='D') q1--;
        if(s[a]=='L') q2++;
        if(s[a]=='R') q2--;
    }
    cout<<n-mo(q1)-mo(q2);
}