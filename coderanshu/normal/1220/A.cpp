#include<bits/stdc++.h>
using namespace std;
int main()
{
    long n,z=0,o=0;
    string s;
    cin>>n>>s;
    for(auto i=0;s[i];i++)
    {
        if(s[i]=='z')z++;
        if(s[i]=='n')o++;
    }
    for(auto i=0;i<o;i++)cout<<"1 ";
    for(auto i=0;i<z;i++)cout<<"0 ";
    return 0;
}