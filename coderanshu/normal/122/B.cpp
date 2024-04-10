#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int se=0,fo=0,i;
    for(i=0;s[i];i++)
    {
        if(s[i]=='7')se++;
        else if(s[i]=='4')fo++;
    }
    if(fo==0 && se==0)
    {
        cout<<-1;
    }
    else
    {
    if(fo>=se)cout<<4;
    else cout<<7;
    }
    return 0;
}