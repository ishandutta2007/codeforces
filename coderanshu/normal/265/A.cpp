#include<bits/stdc++.h>
using namespace std;
int main()
{
    char s[52],t[52];
    int i,j=0;
    cin>>s;
    cin>>t;
    for(i=0;i<strlen(t);i++)
    {
        if(t[i]==s[j])
        {
            j++;
        }
    }
    cout<<j+1;
    return 0;
}