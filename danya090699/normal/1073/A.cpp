#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    string s;
    cin>>s;
    bool fo=0;
    for(int a=0; a+1<n; a++)
    {
        if(s[a]!=s[a+1])
        {
            cout<<"YES\n"<<s[a]<<s[a+1];
            fo=1;
            break;
        }
    }
    if(fo==0) cout<<"NO";
}