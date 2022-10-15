#include <iostream>
#include <cstring>
using namespace std;
int ap[30];
int main()
{
    char s[1005];
    cin.getline(s,1005);
    int n=strlen(s),i,k,su=0,t,ch;
    for(i=0;i<n;i++)
        ap[s[i]-'a']++;
    cin>>k;
    for(i=0;i<26;i++)
        if(ap[i])
            su++;
    t=k-su;
    if(t<=0)
    {
        cout<<0;
        return 0;
    }
    ch=n-su;
    if(t<=ch)
        cout<<t;
    else
        cout<<"impossible";
    return 0;
}