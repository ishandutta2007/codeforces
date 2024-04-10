#include <bits/stdc++.h>
using namespace std;
char s[100005];
int n;
int main()
{
    cin.getline(s,100005);
    n=strlen(s);
    cout<<s;
    for(int i=n-1;i>=0;i--)
        cout<<s[i];
    return 0;
}