#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char s[100005];
    cin.getline(s,100005);
    int n=strlen(s),st=0,dr=0,i;
    for(st=0;st<=n;st++)
        if(s[st]!='a')
            break;
    if(st==n)
    {
        for(i=1;i<n;i++)
            cout<<"a";
        cout<<"z";
        return 0;
    }
    for(dr=st;dr<n;dr++)
        if(s[dr+1]=='a')
            break;
    for(i=st;i<=dr;i++)
        s[i]=char{s[i]-1};
    for(i=0;i<n;i++)
        cout<<s[i];
    return 0;
}