#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    long long int n,i=0,wl=0,wr=0,j;
    cin>>s;
    n=s.length();
    while(s[i++]!='^')
    {
        // impo loop
    }
    for(j=0;j<=i-2;j++)
    {
        if(s[j]!='=')
        wl+=(i-j-1)*(s[j]-48);
    }
    for(j=i;j<n;j++)
    {
        if(s[j]!='=')
        {
            wr+=(j+1-i)*(s[j]-48);
        }
    }
    if(wl>wr)cout<<"left";
    else if(wl<wr)cout<<"right";
    else cout<<"balance";
    return 0;
    // concept of torque.....
}