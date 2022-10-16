#include<bits/stdc++.h>
using namespace std;
string s[31211];
int main()
{
    int n,i;
    cin>>n;
    for(i=0;i<n;i++)cin>>s[i];
    for(i=0;i<s[0].size();i++)
    {
        bool ok=1;
        for(int j=1;j<n;j++)
            if(s[j][i]!=s[j-1][i])
                ok=false;
        if(!ok)break;
    }
    cout<<i;
}